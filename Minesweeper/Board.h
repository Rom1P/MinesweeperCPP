#pragma once
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <list>

#include <stdlib.h>
#include <vector>


using namespace std;

class Board
{
public:

	int nbLine;
	int nbColumn;
	int nbMine;

	vector<vector<int>> BoardToDisplay;

	vector<vector<int>> ListOfMines;


	vector<vector<int>> AlreadyChecked;
	Board();

	~Board();


	void GetCase(int LineCase, int ColumnCase);

	bool CheckWin();

	void CreateBoard(int nbLine, int nbColumn);
	void Display(vector<vector<int>> BoardToDisplay);
	void DisplayMines(vector<vector<int>> Mines);
	void CreateListOfMines();

};
