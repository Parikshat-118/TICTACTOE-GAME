Tic Tac Toe Game - C++ Console Application
------------------------------------------

Overview:
This is a two-player console-based Tic Tac Toe game written in C++. It utilizes object-oriented programming principles to ensure modularity and clarity.

Key Features:
- 3x3 game board using a 2D array.
- Two players: 'X' and 'O' represented by custom Player objects.
- Turn-based input with move validation.
- Automatic win detection (rows, columns, diagonals).
- Draw detection when all cells are filled with no winner.
- Option to play multiple rounds without restarting the program.

Classes Used:
1. Player:
   - Stores player's symbol ('X' or 'O') and name.
   - Provides methods to access player data.

2. Board:
   - Maintains the game state using a 3x3 character array.
   - Provides methods to draw the board, validate moves, make moves, check for a winner, and reset the game.

3. TicTacToeGame:
   - Controls the overall game logic including alternating turns and gameplay flow.
   - Handles input and display messages to guide the user.

How to Use:
- Compile using any C++ compiler (e.g., g++).
- Run the executable in a terminal.
- Follow on-screen instructions to enter row and column numbers (1-3).
- After a game ends, enter 'Y' to play again or any other key to exit.

