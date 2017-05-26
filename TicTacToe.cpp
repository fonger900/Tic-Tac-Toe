// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define WIDTH 3;
#define HEIGHT 3;

enum Winner
{
	PLAYER1, PLAYER2, NO_WINNER, DRAW
};

enum WinState
{
	WIN, EQUAL
};

enum Movement
{
	MOVE_SUCCESS, MOVE_FAIL
};
void display(char **board) {
	printf("   | 1 | 2 | 3 |\n");
	printf("----------------\n");
	printf(" 1 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2] );
	printf("----------------\n");
	printf(" 2 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
	printf("----------------\n");
	printf(" 3 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
}

void welcome() {
	printf("Welcome to Tic Tac Toe!\n");
	printf("O: player1 | X: player2\n\n");
}

Movement setMove(char playerSymbol,int x,int y ,char **board) {
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
		x -= 1;
		y -= 1;
		if (board[x][y] != 'X' && board[x][y] != 'O') {
			board[x][y] = playerSymbol;
		}
		else {
			printf("Can't move here!\n");
			return MOVE_FAIL;
		}
	}
	else {
		printf("Positon out of range\n");
		return MOVE_FAIL;
	}
	return MOVE_SUCCESS;
	
}

void player1(char **board) {
	int choice;
	Movement movement;
	printf("turn: O\n");
	do
	{
		printf("Enter your move: ");
		scanf("%d", &choice);
		int x = choice / 10;
		int y = choice % 10;
		movement=setMove('O', x, y, board);
		if (movement == MOVE_FAIL)
			printf("Re-enter!\n");
	} while (movement==MOVE_FAIL);
	
}

void player2(char **board) {
	int choice;
	Movement movement;
	printf("turn: X\n");
	
	do
	{
		printf("Enter your move: ");
		scanf("%d", &choice);
		int x = choice / 10;
		int y = choice % 10;
		movement = setMove('X', x, y, board);
		if (movement == MOVE_FAIL)
			printf("Re-enter!\n");
	} while (movement == MOVE_FAIL);
}

WinState winPattern(char **board, char playerSymbol) {
	//rows
	if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2]==playerSymbol) {
		return WIN;
	}
	if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] ==playerSymbol) {
		return WIN;
	}
	if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2]==playerSymbol) {
		return WIN;
	}

	//column
	if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0]==playerSymbol) {
		return WIN;
	}
	if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1]==playerSymbol) {
		return WIN;
	}
	if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2]==playerSymbol) {
		return WIN;
	}

	//diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2]==playerSymbol) {
		return WIN;
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2]==playerSymbol) {
		return WIN;
	}
	return EQUAL;
}

Winner checkWin(int turn,char **board) {
	WinState win_state = winPattern(board,'O');
	if (turn % 2 == 0 ){
		win_state = winPattern(board, 'O');
		if (win_state == WIN) {
			return PLAYER1;
		}
	}
	if (turn % 2 != 0) {
		win_state = winPattern(board, 'X');
		if (win_state == WIN) {
			return PLAYER2;
		}
	}
	/*if (turn == 9) {
		return DRAW;
	}*/
	return NO_WINNER;
}

int main()
{
	char **tt_board = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		tt_board[i] = new char[3];
	}
	printf("%c", tt_board[0][0]);
	int choice;
	int turn=0;
	Winner winner;
	welcome();
	//Game start
	do
	{
		
		display(tt_board);
		if (turn % 2 == 0) {
			player1(tt_board);
		}
		else
		{
			player2(tt_board);
		}
		
		winner = checkWin(turn,tt_board);

		turn++;
		printf("%d\n", turn);
		
	} while ( turn < 9 && winner==NO_WINNER);

	display(tt_board);
	//annouce result
	if (winner == PLAYER1) {
		printf("Player1(O) win!\n");
	}
	else if(winner==PLAYER2)
	{
		printf("Player2(X) win!\n");
	}
	else if(turn == 9)
	{
		printf("Draw!\n");
	}
	
	system("pause");
    return 0;
}

