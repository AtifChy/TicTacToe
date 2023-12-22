# TicTacToe

This is a simple implementation of the classic game TicTacToe in C++. The game is played in the terminal.

## Getting Started

To build and run the project, you need to have CMake installed.

### Prerequisites

- CMake 3.20 or higher
- A C++ compiler that supports C++17

### Building

1. Navigate to the project directory.
2. Create a new directory for the build files and navigate into it:
```sh
mkdir build
cd build
```
3. Run `cmake ..` to generate the build files in the new directory.
4. Run `cmake --build . --config Release --` to build the project.

### Running

After building the project, you can run the game with `./Release/TicTacToe`.

## Game Rules

The game is played on a 3x3 grid. The player is 'X' and the computer is 'O'. The player and the computer take turns to place their symbol on the grid. The first one to get 3 of their symbols in a line (horizontally, vertically, or diagonally) wins the game. If the grid is full and no one has won, the game is a draw.

## Code Structure

- `main.cpp`: Contains the main game loop and the game logic.
- `CMakeLists.txt`: Contains the CMake configuration for building the project.

## Contributing

Contributions are welcome. Please open an issue to discuss your ideas before making changes.

## License

This project is open source. Feel free to use, modify, and distribute the code.