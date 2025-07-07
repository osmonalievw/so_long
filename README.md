# So Long

A small 2D game built with MiniLibX as part of a 42 school project. The objective is to navigate a character through a map, collect all the items, and reach the exit.

## Features

*   2D graphical representation using MiniLibX.
*   Map parsing from `.ber` files.
*   Player movement and collision detection.
*   Collectible items that must be gathered to open the exit.
*   Move counter displayed in the terminal.

## How to Play

*   Use the **W**, **A**, **S**, **D** keys to move the player up, left, down, and right.
*   Collect all the items ('C') on the map.
*   Once all items are collected, the exit ('E') will open.
*   Move to the open exit to win the game.
*   Press the **ESC** key or click the window's close button to quit the game.

## Platform

This project is developed and optimized for **Linux**. It relies on X11 libraries for graphics, which are standard in most Linux distributions.

## Setup and Compilation

1.  **Clone the repository:**
    ```bash
    git clone <your_repo_url>
    cd so_long
    ```

2.  **Install MiniLibX:**
    The project requires the MiniLibX graphics library. A rule is included in the `makefile` to clone the official repository.
    ```bash
    make install_mlx
    ```

3.  **Compile the project:**
    Use the `make` command to build the `so_long` executable.
    ```bash
    make
    ```

## Usage

Run the game by providing a path to a valid map file (`.ber` extension) as an argument. Several example maps are included in the `maps/` directory.

```bash
./so_long maps/map.ber
```

## Cleaning Up

*   To remove the object files, run:
    ```bash
    make clean
    ```
*   To remove the object files and the `so_long` executable, run:
    ```bash
    make fclean
    ```