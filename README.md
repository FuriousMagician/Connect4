The intent of this design project is to allow you the opportunity to demonstrate your ability to solve
problems using procedural C++ programming. This project will focus on using loops, functions and
arrays or vectors in the implementation of the game Connect4.

Implementation Requirements:
To receive full credit, you must implement the Connect4 game where two players take turns
dropping their checker until either someone wins the game, or all positions in the grid have been
taken (i.e. a tie). All input and output is to and from the console.

The implementation must meet the following design specifications:

1. When the program begins, a function should display a simple welcome message, randomly
select which player goes first and any specific player instructions for your code.

2. From main a function call will display the grid below and prompt the player
for their move (i.e. the column they would like to drop their checker in). After placing the
checker, the function will redisplay the grid and prompt
the next player for their move.

3. The program should continue alternating between the two players, prompting and placing each
player’s checker in the requested column.

4. If a player selects a column that is out of range (Ex: the column is outside 1-7), a function
should display a warning message and re-prompt for a new move. If a player requests a move
to a column that is full, the program should display a warning message.

5. Play continues until either a player wins or all the positions are taken.
