# LAMEVID

### Your terminal is now a cinema. Please silence your notifications and lower your expectations.

Ever wanted to watch a video without opening a big fancy graphical player like some kind of *well-adjusted desktop user*?

Congratulations. We made a C program for that.

**LAMEVID** launches `mpv` using its `tct` true-colour terminal video output. Your movie becomes a glorious, rapidly changing wall of coloured characters. Is it IMAX? No. Is it a terminal doing its absolute best? YES.

```bash
lamevid movie.mp4
lamevid "recording from last Tuesday.mp4"
lamevid --loop-file=inf clip.mkv
```

## Features

- Plays video in your terminal using `mpv`'s `tct` output driver.
- Passes extra options through to `mpv`.
- Supports whatever video formats your installed `mpv` build and codecs can handle.
- Has `--help`, `--version`, and `--check` because even chaos deserves documentation.
- Written in C. Because apparently we looked at the problem and decided it needed a compiler.

## Requirements

- A terminal emulator with ANSI true-colour support.
- `mpv` built with the `tct` video output driver.
- Working audio output if you want to hear the movie instead of silently guessing the plot.

On Ubuntu:

```bash
sudo apt install mpv
```

Check the important bit:

```bash
mpv --vo=help
```

Look for `tct` in the output list. If it isn't there, LAMEVID can't summon it through sheer force of personality.

## Build and install

```bash
make
make test
sudo make PREFIX=/usr/local install
```

The default install prefix is `/usr/local`. Check the dependency with:

```bash
lamevid --check
```

## A few reality checks

- Terminal playback is not the same as a normal graphical video window.
- Performance and appearance depend on the terminal, video, and machine.
- Format support comes from `mpv` and its available codecs—not from LAMEVID personally knowing every file extension on Earth.

LAMEVID is a small C launcher. `mpv` does the actual decoding and playback, because writing a video decoder just to watch a raccoon movie would be an unreasonable Tuesday.

## License

MIT. Go forth and make your terminal earn its electricity.
