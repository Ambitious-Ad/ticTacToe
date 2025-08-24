#include <iostream>
#include <random>
#include <limits>

int randomNumber()
{
	std::random_device rd;
	std::mt19937 md(rd());
	std::uniform_int_distribution<> random(1, 9);

	return random(md);
}

void clearScreen()
{
	system("cls");
}

void printBoard(const int& row, const int& column, const char gameBoard[][3])
{
	clearScreen();
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

bool checkForWin(int row, const char gameBoard[3][3], char& selectShape)
{

	bool gameStart = true;

	// Check to see who wins
	for (int i = 0; i < row; ++i)
	{
		// Row check
		if (gameBoard[0][i] == selectShape && gameBoard[1][i] == selectShape && gameBoard[2][i] == selectShape)
		{
			gameStart = false;
		}

		// column check
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

void clearInputBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int selectPosition(const char gameBoard[3][3], const int& row, const int& column)
{

	bool spaceTaken{ true };
	int selectedPostion{ 1 };

	while (spaceTaken)
	{

		std::cout << " 1, 2, 3, \n 4, 5, 6, \n 7, 8, 9 - ";
		if (!(std::cin >> selectedPostion))
		{
			clearScreen();
			printBoard(row, column, gameBoard);
			std::cerr << "Not a number!\n";
			std::cin.clear();
			clearInputBuffer();
			continue;
		}
		else if (selectedPostion < 1 || selectedPostion > 9)
		{
			clearScreen();
			std::cout << "Please input a number between 1 and 9!\n";
			printBoard(row, column, gameBoard);
			clearInputBuffer();
			std::cin.clear();
			continue;
		}

		int r = (selectedPostion - 1) / column;
		int c = (selectedPostion - 1) % column;

		clearScreen();

		if (gameBoard[r][c] != ' ')
		{
			printBoard(row, column, gameBoard);
			std::cout << "That spot is taken please try again!\n";
		}

		else
		{
			spaceTaken = false;
		}

	}

	return selectedPostion;
}

char selectShape()
{
	char selectShape{ ' ' };
	while (selectShape != 'X' && selectShape != 'O')
	{
		std::cout << "Player one select your shape!\n";
		std::cout << "Select shape X|O - ";
		std::cin >> selectShape;
		selectShape = toupper(selectShape);

		clearScreen();

		if (selectShape != 'X' && selectShape != 'O')
		{
			std::cout << "Incorrect input please try again!\n";
		}
	}
	return selectShape;
}

int computerChoice()
{

	// TODO: add ai player

	return 0;
}

bool playAgain()
{
	bool replay = false;
	char userInput{ 'n' };
	std::cout << "Play again? (Y/N) - ";
	std::cin >> userInput;

	if (userInput == 'y' || userInput == 'Y')
	{
		replay = true;
	}

	return replay;
}

int main()
{
	const int row{ 3 };
	const int column{ 3 };
	int xWins{ 0 };
	int oWins{ 0 };

	std::cout << "Welcome to Tic-Tac-Toe!\n";

	bool gameStart{ true };
	char gameBoard[row][column] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '},
	};

	char playerOne{ selectShape() };
	char playerTwo{ 'O' };

	if (playerOne == 'O')
	{
		playerTwo = 'X';
	}

	int count{ 0 };
	int isPlayerOne{ 2 };
	char currentShape{ 'X' };

	while (gameStart)
	{

		printBoard(row, column, gameBoard);

		if (count % isPlayerOne == 0)
		{
			currentShape = playerOne;
			std::cout << "Player: " << currentShape << " make selection!\n";
		}
		else
		{
			currentShape = playerTwo;
			std::cout << "Player: " << currentShape << " make selection!\n";
		}

		int selectedPostion{ selectPosition(gameBoard, row, column) };

		int r = (selectedPostion - 1) / column;
		int c = (selectedPostion - 1) % column;

		gameBoard[r][c] = currentShape;
		gameStart = checkForWin(row, gameBoard, currentShape);

		count++;

		if (count >= 9 || gameStart == false)
		{
			printBoard(row, column, gameBoard);
			if (count >= 9)
			{
				std::cout << "Tie game!\n";
			}
			else
			{
				std::cout << currentShape << " wins the game!\n";
			}

			if (currentShape == 'X' && count < 9)
			{
				xWins++;
			}
			else if (currentShape == 'O' && count < 9)
			{
				oWins++;
			}

			std::cout << "X has won " << xWins << " games!\n";
			std::cout << "O has won " << oWins << " games!\n";

			gameStart = playAgain();
			count = 0;
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < column; ++j)
				{
					gameBoard[i][j] = ' ';
				}
			}
		}
	}

	return 0;
}