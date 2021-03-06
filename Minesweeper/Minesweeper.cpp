// Minesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Board.h"


using namespace std;

void Game() {
	Board* BoardObject = new Board();

	bool endCurrentGame = false;

	int ColumnMine;
	int LineMine;
	while (!endCurrentGame) {
		cout << "Indicate the next box without mine\n";

		vector<int> TestMine;

		cout << "Column Number [0-" << BoardObject->nbColumn << "] ?";

		cin >> ColumnMine;

		ColumnMine--;

		cout << "Line Number [0-" << BoardObject->nbLine << "] ?";

		cin >> LineMine;

		LineMine--;

		TestMine.push_back(LineMine);
		TestMine.push_back(ColumnMine);

		if (find(BoardObject->ListOfMines.begin(), BoardObject->ListOfMines.end(), TestMine) != BoardObject->ListOfMines.end()) {

			cout << "You Loose\n";
			endCurrentGame = true;
			continue;

		}

		BoardObject->GetCase(LineMine, ColumnMine);

		BoardObject->Display(BoardObject->BoardToDisplay);

		endCurrentGame = BoardObject->CheckWin();

		
	}
}

int main()
{
	bool restart = true;

	while (restart) {
		Game();
		string restartInput;
		cout << "Do you want to restart ? (Y/N) ";
		cin >> restartInput;
		char FirstOfInput = restartInput[0];
		putchar(toupper(FirstOfInput));

		if (FirstOfInput == 'Y') {
			continue;
		}

		else if (FirstOfInput == 'N') {
			restart = false;
			continue;
		}
	}

	return 0;
}




