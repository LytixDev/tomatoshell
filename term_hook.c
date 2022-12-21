#include <signal.h>
#include <unistd.h>
#include <termios.h>

sig_atomic_t signal_status = 0;


static void sig_stub(int signal)
{
    signal_status = 1;
}

static void term_hook(struct termios *original, struct termios *modified)
{
    tcgetattr(STDIN_FILENO, original);
    modified = original;
    /* change so buffer don't require modified line or similar to return */
    modified->c_lflag &= ~ICANON;
    modified->c_cc[VTIME] = 0;
    modified->c_cc[VMIN] = 1;
    /* turn of echo */
    modified->c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, modified);
}

static inline void term_hook_reset(struct termios *original)
{
    tcsetattr(STDIN_FILENO, TCSANOW, original);
}

int main()
{
    struct termios original, modified;
    struct sigaction act;
    sigset_t mask;

    act.sa_handler = sig_stub;
    sigaction(SIGUSR1, &act, NULL);
    sigemptyset(&mask);

    term_hook(&original, &modified);
    while (!signal_status)
        sigsuspend(&mask);
    term_hook_reset(&original);

    return 0;
}
