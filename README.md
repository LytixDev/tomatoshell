# Pomodoro timer in the shell with tomatoshell 🍅!
Copyright © 2022 Nicolai Brand under GPL v2.

tomatoshell is a simple <a href="https://en.wikipedia.org/wiki/Pomodoro_Technique">pomodoro</a> timer program for <a href="https://en.wikipedia.org/wiki/Unix-like">Unix-like</a> systems. It is written in <a href="https://www.gnu.org/software/bash/">Bash</a> and attempts to follow the <a href="https://en.wikipedia.org/wiki/Unix_philosophy">Unix philosophy</a> in a minimalistic bloat-free fashion. In addition to being a pomodoro timer in the terminal, it tracks the time and number of sessions to a log that can be queried to see total time spent.

## Installation

(still pending)
On Arch-based distribution, you can use the AUR (Arch User Repository).

```
$ yay -S tomatoshell
```

```
$ tomatoshell
```

That's it.

### To install manually:

#### Dependencies

- `git` - to download the source code (required at install).
- `bash` - shell scripting language. Is installed by default on 99% of distros.
- `alsa-lib` - audio support for linux.  Is installed by default on 99% of distros.

#### Optional dependencies 
- `gawk/awk` - for arithmetic on log file. Is installed by default on 99% of distros.
- `figlet` - for cool text using the `-f` argument.
- `pulseaudio and mpv` - better playback of alarm.
- `notify-send` - sends notification when a session is ended. A notification deamon is also needed for this.


```
$ git clone git@github.com:LytixDev/tomatoshell.git
```

```
$ cd tomatoshell && ./configure install
```

```
$ tomatoshell
```

## Usage

- `-r` - prints total hours spent using tomatoshell and exits
- `-t` - time for every session in minutes [default:25 minutes]
- `-d` - delay between sessions in minutes [default:5 minutes]
- `-n` - total sessions [default:3]
- `-f` - figlet on

After installation the program will create a datafolder in `$HOME/.local/share/tomatoshell`. Here the alarm, `alarm.wav`, and the logfile `tomatoshell_log.csv` is located. The alarm can be swapped out for any other audio file that is compatible with the user's chosen audio player. The log file is a csv file with its columns being on the form: "date,number of sessions,seconds per session". The `-r` argument only tallies up the time spent in hours. Feel free to create some more cool statistics using the data.
