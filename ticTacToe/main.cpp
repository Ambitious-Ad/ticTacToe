#include <iostream>
#include <random>
#include <conio.h>

// TODO: Add player 2
// TODO: Add play again option

int randomNumber()
{
	std::random_device rd;
	std::mt19937 md(rd());
	std::uniform_int_distribution<> random(1, 9);

	return random(md);
}

void printBoard(const int& row,const int& column, const char gameBoard[][3])
{
	system("cls");
	std::cout << "===== Tic-Tac-Toe =====\n";

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (j < 1)
				std::cout << "       ";
			std::cout << gameBoard[i][j];
			if (j < 2)
				std::cout << " | ";

		}

		std::cout << "\n";
		if (i < 2)
		{
			std::cout << "      ---+---+---\n";
		}
	}

	std::cout << "=======================\n";
}

bool checkForWin(int row, const char gameBoard[][3], char& selectShape)
{

	bool gameStart = true;

	// Check to see who wins
	for (int i = 0; i < row; ++i)
	{
		// Horizontal check
		if (gameBoard[0][i] == selectShape && gameBoard[1][i] == selectShape && gameBoard[2][i] == selectShape)
		{
			gameStart = false;
		}

		// Vertical check
		if (gameBoard[i][0] == selectShape && gameBoard[i][1] == selectShape && gameBoard[i][2] == selectShape)
		{
			gameStart = false;
		}
	}

	// Diagonal left to right
	if (gameBoard[0][0] == selectShape && gameBoard[1][1] == selectShape && gameBoard[2][2] == selectShape)
	{
		gameStart = false;
	}

	// Diagonal right to left
	if (gameBoard[0][2] == selectShape && gameBoard[1][1] == selectShape && gameBoard[2][0] == selectShape)
	{
		gameStart = false;
	}
	return gameStart;
}

int selectPosition()
{
	int selection{ 1 };
	std::cout << "Select position:\n 1, 2, 3, \n 4, 5, 6, \n 7, 8, 9 - ";
	std::cin >> selection;
	return selection;
}

char selectShape()
{
	char selectShape{ 'X' };
	std::cout << "Select shape X|O - ";
	std::cin >> selectShape;
	selectShape = toupper(selectShape);
	return selectShape;
}

bool isSpaceTaken(const char gameBoard[][3], int r, int c)
{
	bool isTaken{ true };

	// TODO: Check if position is already taken	
	
	return isTaken;
}

int computerChoice()
{

	// TODO: add ai player

	return 0;
}

int main()
{
	const int row{ 3 };
	const int column{ 3 };

	std::cout << "Welcome to Tic-Tac-Toe!\n";
	std::cout << "Player one select your shape!\n";

	bool gameStart{ true };
	char gameBoard[row][column] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '},
	};

	char selectedShape{ selectShape() };
	
	while (gameStart)
	{

		printBoard(row, column, gameBoard);

		int selectedPostion{ selectPosition() };

		int r = (selectedPostion - 1) / column;
		int c = (selectedPostion - 1) % column;

		if (gameBoard[r][c] != ' ')
		{
			std::cout << "Already taken!\n";
		}

		gameBoard[r][c] = selectedShape;

		gameStart = checkForWin(row, gameBoard, selectedShape);
	}
	
	return 0;
}