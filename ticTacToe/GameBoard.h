#pragma once

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

private:
	const int row{ 3 };
	const int column{ 3 };
	char gameBoard[3][3] = {
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	};
};

