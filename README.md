# Pomodoro timer in the shell with tomatoshell 🍅!

<div align="center">
  <img src="https://github.com/LytixDev/tomatoshell/blob/main/sed11qlol.png" width="500">
</div>

## Requirements: cmus (for music playback), figlet (for -f figlet mode on text).

## How to use:
```
git clone https://github.com/LytixDev/tomatoshell.git
```
```
cd tomatoshell
```
```
./tomatoshell
```

## Options
 -t, --time,    time for every session in minutes [default:15 minutes]
 
 -d, --delay,   delay between sessions in minutes [default:5 minutes]
 
 -m, --music,   chose song for cmus to play during each session (full path)
 
 -n,            total sessions [default:4]
 
 -f,            figlet on
 
 -s, --song,    full path to song to be played by cmus
 
 -h, --help,    shows this

ex:

tomatoshell -n 2 -m /home/nic/Music/song.mp3 -t 30

This will start the program with two sessions, play the song given during the session, and each session lasts for 30 minutes.


