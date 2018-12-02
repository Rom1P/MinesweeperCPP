#include "stdafx.h"
#include "Board.h"

#include <iostream>
#include <conio.h>
#include <list>

#include <stdlib.h>
#include <time.h>
#include <vector>


using namespace std;

Board::Board()
{
	cout << "Please enter number of lines : ";
	cin >> nbLine;
	cout << "Please enter number of columns : ";
	cin >> nbColumn;

	CreateBoard(nbLine, nbColumn);

	cout << "Please enter number of mines : ";
	cin >> nbMine;
	CreateListOfMines();
}





void Board::CreateBoard(int nbLine, int nbColumn)
{
	vector<vector<int>> BoardVector;
	for (size_t i = 0; i < nbLine; i++)
	{
		vector<int> LineTemp;
		for (size_t j = 0; j < nbColumn; j++)
		{
			LineTemp.push_back(0);
		}
		BoardVector.push_back(LineTemp);
	}

	BoardToDisplay = BoardVector;


}

void Board::Display(vector<vector<int>> BoardToDisplay) {
	for (size_t i = 0; i < BoardToDisplay.size(); i++) {
		vector<int> LineTemp = BoardToDisplay[i];
		for (size_t j = 0; j < LineTemp.size(); j++)
		{
			int ValueTemp = LineTemp[j];

			cout << "[";

			if (ValueTemp == 0) {

				cout << " ";
			}

			else if (ValueTemp == 8) {
				cout << "-";
			}

			else {
				cout << ValueTemp;
			}


			cout << "]";
		}
		cout << "\n";
	}
}



void Board::CreateListOfMines()
{

	vector<int> TempList;
	for (size_t i = 0; i < nbMine; i++)
	{
		vector<int> TempList;
		srand(time(NULL));
		int RandomLine = rand() % (nbLine);
		int RandomColumn = rand() % (nbColumn);

		TempList.push_back(RandomLine);
		TempList.push_back(RandomColumn);



		if (find(ListOfMines.begin(), ListOfMines.end(), TempList) != ListOfMines.end()) {
			i--;
		}
		else {
			ListOfMines.push_back(TempList);
		}
	}
}

Board::~Board()
{
	cout << "This BoardObject is being deleted" << endl;
}



void Board::GetCase(int LineCase, int ColumnCase)
{

	vector<int> TempList;

	TempList.push_back(LineCase);
	TempList.push_back(ColumnCase);

	AlreadyChecked.push_back(TempList);


	int BombClose = 0;


	// TopLeft

	if (LineCase > 0 && ColumnCase > 0) {

		vector<int> TopLeft;

		TopLeft.push_back(LineCase - 1);
		TopLeft.push_back(ColumnCase - 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), TopLeft) != ListOfMines.end()) {
			BombClose++;
		}

	}


	// Top

	if (LineCase > 0) {
		vector<int> Top;

		Top.push_back(LineCase - 1);
		Top.push_back(ColumnCase);

		if (find(ListOfMines.begin(), ListOfMines.end(), Top) != ListOfMines.end()) {
			BombClose++;
		}


	}

	// TopRight

	if (LineCase > 0 && ColumnCase < nbColumn - 1) {
		vector<int> TopRight;

		TopRight.push_back(LineCase - 1);
		TopRight.push_back(ColumnCase + 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), TopRight) != ListOfMines.end()) {
			BombClose++;
		}


	}

	// Left

	if (ColumnCase > 0) {
		vector<int> Left;

		Left.push_back(LineCase);
		Left.push_back(ColumnCase - 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), Left) != ListOfMines.end()) {
			BombClose++;
		}



	}

	// Right

	if (ColumnCase < nbColumn - 1) {
		vector<int> Right;

		Right.push_back(LineCase);
		Right.push_back(ColumnCase + 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), Right) != ListOfMines.end()) {
			BombClose++;
		}




	}

	// BottomLeft

	if (LineCase < nbLine - 1 && ColumnCase > 0) {
		vector<int> BottomLeft;

		BottomLeft.push_back(LineCase + 1);
		BottomLeft.push_back(ColumnCase - 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), BottomLeft) != ListOfMines.end()) {
			BombClose++;
		}




	}

	// Bottom

	if (LineCase < nbLine - 1) {
		vector<int> Bottom;

		Bottom.push_back(LineCase + 1);
		Bottom.push_back(ColumnCase);

		if (find(ListOfMines.begin(), ListOfMines.end(), Bottom) != ListOfMines.end()) {
			BombClose++;
		}


	}

	// BottomRight

	if (LineCase < nbLine - 1 && ColumnCase < nbColumn - 1) {
		vector<int> BottomRight;

		BottomRight.push_back(LineCase + 1);
		BottomRight.push_back(ColumnCase + 1);

		if (find(ListOfMines.begin(), ListOfMines.end(), BottomRight) != ListOfMines.end()) {
			BombClose++;
		}


	}


	// TopLeft

	if (LineCase > 0 && ColumnCase > 0) {

		vector<int> TopLeft;

		TopLeft.push_back(LineCase - 1);
		TopLeft.push_back(ColumnCase - 1);



		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), TopLeft) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase - 1, ColumnCase - 1);
			}

		}

	}


	// Top

	if (LineCase > 0) {
		vector<int> Top;

		Top.push_back(LineCase - 1);
		Top.push_back(ColumnCase);




		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), Top) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase - 1, ColumnCase);
			}

		}
	}

	// TopRight

	if (LineCase > 0 && ColumnCase < nbColumn - 1) {
		vector<int> TopRight;

		TopRight.push_back(LineCase - 1);
		TopRight.push_back(ColumnCase + 1);




		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), TopRight) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase - 1, ColumnCase + 1);
			}

		}
	}

	// Left

	if (ColumnCase > 0) {
		vector<int> Left;

		Left.push_back(LineCase);
		Left.push_back(ColumnCase - 1);



		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), Left) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase, ColumnCase - 1);
			}

		}
	}

	// Right

	if (ColumnCase < nbColumn - 1) {
		vector<int> Right;

		Right.push_back(LineCase);
		Right.push_back(ColumnCase + 1);




		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), Right) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase, ColumnCase + 1);
			}

		}


	}

	// BottomLeft

	if (LineCase < nbLine - 1 && ColumnCase > 0) {
		vector<int> BottomLeft;

		BottomLeft.push_back(LineCase + 1);
		BottomLeft.push_back(ColumnCase - 1);



		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), BottomLeft) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase + 1, ColumnCase - 1);
			}

		}
	}

	// Bottom

	if (LineCase < nbLine - 1) {
		vector<int> Bottom;

		Bottom.push_back(LineCase + 1);
		Bottom.push_back(ColumnCase);



		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), Bottom) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase + 1, ColumnCase);
			}

		}
	}

	// BottomRight

	if (LineCase < nbLine - 1 && ColumnCase < nbColumn - 1) {
		vector<int> BottomRight;

		BottomRight.push_back(LineCase + 1);
		BottomRight.push_back(ColumnCase + 1);


		if (BombClose == 0) {

			if (find(AlreadyChecked.begin(), AlreadyChecked.end(), BottomRight) != AlreadyChecked.end()) {
			}

			else
			{
				GetCase(LineCase + 1, ColumnCase + 1);
			}

		}
	}


	BoardToDisplay[LineCase][ColumnCase] = BombClose;

	if (BombClose == 0) {

		BoardToDisplay[LineCase][ColumnCase] = 8;
	}
}


bool Board::CheckWin() {

	int nbUnknownCases = 0;

	bool win;
	for (size_t i = 0; i < BoardToDisplay.size(); i++) {
		vector<int> LineTemp = BoardToDisplay[i];
		for (size_t j = 0; j < LineTemp.size(); j++)
		{
			int ValueTemp = LineTemp[j];


			if (ValueTemp == 0) {

				nbUnknownCases++;
			}

			
		}
	}

	if (nbUnknownCases == nbMine) {
		cout << "You Win";
		win = true;

	}

	else {
		win = false;
	}

	return win;


}

