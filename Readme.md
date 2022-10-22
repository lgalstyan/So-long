# so_long | 42 Yerevan


<p align="center">
  <img src = https://user-images.githubusercontent.com/80614377/197327627-b75c28dd-3062-4cfd-9cde-4405349f43a0.mov>
</p>

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Extras](#extras)
* [Gameplay](#gameplay)
* [Other Maps](#other-maps)
* [Installation](#installation)
* [Technical Issues](#technical-issues)
* [Summary](#summary)

## Introduction
In this project, we'll code a simple 2D game to get familiar with the mlx library and UI in general. In my case, it will be Pac-Man.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(pacman)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

## How it Works
For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited, but was still fun to use in the project.


## Extras

The pacman game I designed has a few extras we weren't asked to implement, but I thought would make the overall game experience better. Here's a list of the most relevant additions:

- Add custom (simple) chasing algorithm using euclidean distances.
- Ability to restart the game by pressing the ``R`` key
- Ability to exit the game by pressing the ``Q`` key
- Ghosts enter panic mode when there's less than a third of the pacdots remaining. During this time the players will be faster and ghosts will flash for the sake of distraction
- The score is displayed in the classic pacman fonts, instead of the (ugly) builtin fonts from ``mlx_string_put()``
- Arrow keys also move the player
- Add decorating pacman logo centered at the bottom
- Add support for both ``linux`` and ``MacOS``
- Implement several players in a single map
- Ability to save a direction for when it's available
- Added 30 test maps (most of them playable)
- Restrict ending or resetting the game while pacman is dying

## Installation

### Cloning the repositories
```shell
git clone https://github.com/lgalstyan/So-long.git
cd so_long
make
./so_long ./maps/map.ber
```

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. Then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```

### Usage

```
make                        compiles so_long executable
make git                    adds and commits everything, then pushes to upstream branch
make norminette             runs norminette for all files in the project that need to pass it
```
Note: we were not allowed to use multiple threads, thus it is pretty hard to time the speeds of the game. I found that using valgrind on ``linux`` helps slow the game down so it is more similar to the performance in MacOS. Depending on your computer's performance the speed of the game may vary. I hope to learn ways to improve that for future projects. For ``linux``, try always using valgrind as follows: ``valgrind ./so_long <map.ber>``

## Technical Issues

Throughout the project, there have been a few roadblocks that needed to be worked around, here's some of them:

- Timing: getting the timing for animations and other stuff right was quite challenging. I ended up just using the number of loop repetitions from ``mlx_loop_hook`` and fiddling with different rates, which also varied a lot between MacOS and Linux.
- Sprites: The minilibx in Linux doesn't handle transparency in sprites the same way MacOS' minilibx does. On Linux the sprites will just have black pixels in the transparent area. I found ways to work this around but it was too much of a hussle.
- Leaks: Minilibx has some leaks that are only detected by ``valgrind``. Using the function ``mlx_destroy_display`` solves that leak, but apparently that function isn't a part of the minilibx in MacOS. For this reason I decided to split the file where that function was called, so that the file compiled in Linux had that extra line for valgrind to be happy.
- Keycodes: yet another difference between MacOS and Linux. The keycodes (``WASD``, ``ESC``, etc) are completely different. I defined those variables straight from the makefile to correct this issue.

## Summary
This has been my favorite project so far, coding my own pacman clone was so much fun, regargless how flawed it might be :)

August 15th, 2022
