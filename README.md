## 🎮 Rock Paper Scissors Game

This is my first programming project using the C++ language.
It was developed as an under-intermediate level exercise to practice core procedural programming concepts.
The project features a simple console-based interface and built to focus on understanding and applying fundamental programming principles in C++.

## ✨ Features

This application allows users to:

- Play Rock-Paper-Scissors against the computer.
- Choose the number of rounds to play (1–10).
- View the winner of each round.
- See game statistics including wins, losses, and draws.
- Replay the game as many times as desired.
- See the color of the terminal with different states (Red if the user loss, Green if the user win).

## Folder Structure

The workspace contains the following folder:

RockPaperScissors-CPP/
 ├── Source Files/
 │ └── RockPaperScissors.cpp
 ├── README.md

## Prerequisites

Before you can run this project, you'll need a C++ compiler. You can use any modern compiler like g++ (part of GCC), Clang, or Microsoft's MSVC. The project also requires a terminal that supports ANSI escape codes for the color-coded output. Most modern terminals on Linux, macOS, and Windows (like Git Bash or the new Windows Terminal) support this.

## 🚀 How to Run

### 1-Clone the Repository:

Start by cloning the project to your local machine using Git.

```bash
git clone https://github.com/CS-Abdulaziz/RockPaperScissors-CPP.git
cd RockPaperScissors-CPP
```

### 2-Compile the Source Code:

Navigate to the Source Files directory and compile the RockPaperScissors.cpp file. For g++, the command would look like this:

``` bash
g++ -o RockPaperScissors Source Files/RockPaperScissors.cpp
``` 

### 3-Run the Game:

After compilation, you can run the executable from your terminal.

``` bash
./RockPaperScissors
```

## How to Play

The game is simple and intuitive to play:

-When prompted, enter the number of rounds you want to play (1-10).
-For each round, you'll be asked to choose between Rock (1), Paper (2), or Scissors (3).
-Enter your choice and press Enter. The computer will make its move, and the winner of the round will be displayed. The text color will change to green if you win, red if you lose, and will stay the default color for a draw.
-After all rounds are complete, a summary of your wins, losses, and draws will be shown.
-You'll then have the option to play again or exit the game.

## Author
Name: Abdulaziz Khamis.
Date Starting: March 2025.
