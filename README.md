# Biquadris 

### Game Overview
Also know as Latinization of the game Tetris, expanded for two player competition with the only different being that players are not timed.
- The game consists of two boards, each 11 columns wide and 15 rows high.
- Blocks are tetrominoes and generate at the top of the board depending on level.
- Game design included 4 levels with a range of difficultly from generating preset blocks to different variations of randomization.
- A player’s turn ends when block is dropped onto the board and program checked for special actions which adds to the game's difficulty.
- Game ends when player is unable to place block onto board. 

### Implementation 
The program follows a Model View Controller design pattern with both Text and Graphics-Based Display, Command Interpreter, seven unique blocks, 4 different levels and Special Actions. We made use of additional Object Oriented design patterns including the Observer pattern for rendering the boards and the Factory Method for Levels. The system handles scoring upon block deletion by encapsulating placed blocks and when a block is fully cleared, the score is calculated and passed to the board keeping the program abstracted. Additionally a Trienode data structure stores valid commands and smart pointers throughout entire program that took care of memory management.

### UML Class Model
![image1](https://github.com/jjudyyang/cs246-project/assets/25236683/152f9e4b-bac3-4d6b-8f8f-db7ab8bc79fb)
