/*************************************************************
*
* Lab / Assignment: Lab3 - Freecell
*
* Overview:
*		This program allows the user to play the game Freecell.
*		The game consists of a Play area, Free cell area, and Home area.
*		The goal of the game is to move all cards from play to the Home
*		area in sequencial order from Ace to King.
*
* Input:
*		In the initial menu, entering 'x' will close the game, any
*		other character input will start the game
*
*		During gameplay:
*		- Help: type 'help'to bring up this menu again during play
*		- Move single card: '<m/move> <from area> <from zone #> <to area> <to zone #>'
*			Example: to move from column 3 in the play area to the 2nd free cell, you may type:
*						'm p 3 f 2' or 'move play 3 free 2'
*		 - Move stack of mulitple cards: '<ms/movestack> <from zone #> <amount of cards> <to zone #>'
*			Example: to move the bottom 3 cards from play area column 1 to play area column 2, you may type:
*						'ms 1 3 2' or 'movestack 1 3 2'
*		 - Area names:
*				Play Area (your main board) - 'p'or'play'
*				Free Cells (upper left) - 'f'or'free'
*				Home Area (upper right) - 'h'or'home'
*
* Output:
*		Upon initial start, the program will display a help message
*		and wait for input from the user.
*
*		During play, the 3 play areas are displayed along with
*		their corresponding cards and indicating position numbers
*
**************************************************************/

/*************************************************************
* Author: Dillon Wall
* Filename: Driver.cpp
* Date Created: 2/12/2019
* Modifications:
**************************************************************/

#include "Freecell.h"
#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

#define BUFFER_SIZE 255

//Prints out the rules of the game
void DisplayRules();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	bool exit = false;
	Random::Init();

	try
	{
		while (!exit)
		{
			char inputChar = '0';

			DisplayRules();

			cout << "(Enter any char to start, x = Exit) : " << endl;
			cin >> inputChar;

			if (inputChar != 'x')
			{
				Freecell game;
				char inputBuffer[BUFFER_SIZE];

				while (cin.getline(inputBuffer, BUFFER_SIZE) && game.Update(inputBuffer) && !game.Won())
				{
					game.Print();
					if (strcmp(inputBuffer, "help") == 0)
						DisplayRules();
				}

				//show game after its over
				game.Print();

				//print final result
				cout << endl;
				if(game.Won())
					cout << "  --==< Y O U   W I N ! >==--" << endl;
				else
					cout << "  --==< G A M E   O V E R >==--" << endl;
				cout << endl;
			}
			else
			{
				exit = true;
			}
		}
	}
	catch (Exception e)
	{
		cout << e.GetMsg() << endl;
	}
}

void DisplayRules()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 15);
	cout << "Rules/Commands: " << endl;
	SetConsoleTextAttribute(hConsole, 4);
	cout << " - Help: ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "type ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'help'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "to bring up this menu again during play" << endl;
	SetConsoleTextAttribute(hConsole, 4);
	cout << " - Move single card: ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "'<m/move> <from area> <from zone #> <to area> <to zone #>'" << endl <<
		"    Example: to move from column 3 in the play area to the 2nd free cell, you may type:" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "                'm p 3 f 2'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << " or ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'move play 3 free 2'" << endl;
	SetConsoleTextAttribute(hConsole, 4);
	cout << " - Move stack of mulitple cards: ";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "'<ms/movestack> <from zone #> <amount of cards> <to zone #>'" << endl <<
		"    Example: to move the bottom 3 cards from play area column 1 to play area column 2, you may type:" << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "                'ms 1 3 2'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << " or ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'movestack 1 3 2'" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << " - Area names: " << endl;
	cout << "        Play Area (your main board) - ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'p'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "or";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'play'" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "        Free Cells (upper left) - ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'f'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "or";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'free'" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "        Home Area (upper right) - ";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'h'";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "or";
	SetConsoleTextAttribute(hConsole, 6);
	cout << "'home'" << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
}
