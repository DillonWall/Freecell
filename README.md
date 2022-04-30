# Freecell

## Overview
This program allows the user to play the game Freecell.

The game consists of a Play area, Free cell area, and Home area.

The goal of the game is to move all cards from play to the Home
area in sequencial order from Ace to King.


## Details
### Input
In the initial menu, entering 'x' will close the game, any
other character input will start the game

During gameplay:
- Help: type 'help' to bring up this menu again during play
- Move single card: '<m/move> <from area> <from zone #> <to area> <to zone #>'
  
	Example: to move from column 3 in the play area to the 2nd free cell, you may type:
  
				'm p 3 f 2' or 'move play 3 free 2'
- Move stack of mulitple cards: '<ms/movestack> <from zone #> <amount of cards> <to zone #>'
  
	Example: to move the bottom 3 cards from play area column 1 to play area column 2, you may type:
  
				'ms 1 3 2' or 'movestack 1 3 2'
- Area names: 
  
		Play Area (your main board) - 'p'or'play'
  
		Free Cells (upper left) - 'f'or'free'
  
		Home Area (upper right) - 'h'or'home'

### Output
Upon initial start, the program will display a help message
and wait for input from the user.

During play, the 3 play areas are displayed along with
their corresponding cards and indicating position numbers

  
## Installation
Open and run with Visual Studio 2022 (or your IDE of choice)

  
## Status
This project is finished.

  
## Screenshots
![image](https://user-images.githubusercontent.com/49173127/166088123-da22f0cd-de57-4fc8-a379-8243995bdf32.png)
