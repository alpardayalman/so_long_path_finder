# Map Exit Validator

This program validates a map by checking if it is possible for the player to exit while collecting all the coins. It utilizes a recursive depth-first search (DFS) algorithm to explore the map.

## Table of Contents

- [Description](#description)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [Example Map](#example-map)
- [Contact](#contact)

## Description

The Map Exit Validator is a program written in C that determines the validity of a map for a game. It checks if the player can reach the exit while collecting all the coins on the map. The program uses a DFS algorithm to explore the map and keeps track of the number of coins collected and the player's position.

## Usage

To use the Map Exit Validator, follow these steps:

1. Open the C source file containing the program code.
2. Compile the program using a C compiler.
3. Execute the compiled program.
4. The program will output either "Valid Map" or "Faulty Map" depending on the validity of the map.

## Implementation Details

The program utilizes a `t_game` structure to store the map, map dimensions, number of coins, player position, and exit possibility. The DFS algorithm implemented in the `check_path` function recursively explores the map, collecting coins and checking for the exit. The `flood_fill` function creates a temporary copy of the game structure, invokes the DFS algorithm, and then checks if the exit is possible and all the coins have been collected.

The program dynamically allocates memory for the map and frees it when no longer needed using the `free_map` function.

## Example Map

Here is an example map used by the program:

```shell
1111111111111111111111111
1000000000000010000000001
100001E000000010000000001
1000010000000010000000001
100001000C000010000000001
1000010000000010000000001
1000100000P00010000000001
1000101001000011110C00001
1000001000000010000000001
1111111111111111111111111
```

In the map:
- `1` represents a wall or obstacle.
- `0` represents an empty space.
- `P` represents the player's initial position.
- `C` represents a coin.
- `E` represents the exit.


## Contact

It's your boy Asmongold

