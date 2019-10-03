/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

// declare and define the main function
int main(void)
{
	system("cls");

	// initialising variables
	int game = 1;
	int playerTurn = 1;
	b.totalRemaining = size * size - 4;

	//Initialise player scores to 0
	pOne.score = 2;
	pTwo.score = 2;


	// call the input function
    input();

	// initially fill the 'empty spaces on the board' with x's
	for(int i = 0;i < size;i++)
		for(int j = 0;j < size;j++)
			b.board[i][j] = ' ';

	// initialise the game with the starting positons
	b.board[3][4] = '1';
	b.board[4][3] = '1';
	b.board[3][3] = '0';
	b.board[4][4] = '0';

// test setup.	
	
	// assign player one and two '1' and '0' respectively
	pOne.diskType = '1';
	pTwo.diskType = '0';

	// initial print of the board
	print();

	// implimenting game logic
	while(game)
	{	
		int x,y;
		int valid;
		endGameState[0] = 0;
		endGameState[1] = endGameState[0];

		free(startPtr);
		startPtr = NULL;

		// shows the player possible moves
		printf("Possible moves:\n");

		// nested for loops run through all empty posititons on the board by calling the check function.
		for(x = 0;x < size;x++)
			for(y = 0;y < size;y++)
				if(b.board[x][y] == ' ')
					endGameState[0] += check(x, y, playerTurn, 0, 1);

		printList(startPtr);

		if(endGameState[1] == 0 && endGameState[0] == 0)
			break;

		//Ask the current player to enter a valid position
		if(playerTurn == 1)
			printf("%s, enter one of the valid positions listed above:\n", pOne.name);
		else
			printf("%s, enter one of the valid positions listed above:\n", pTwo.name);

		scanf("%d,%d", &x, &y);
		x--;y--;
		// call the check function with turn value 1 to actually place the piece
		check(x, y, playerTurn, 1, 0);

		scoreUpdate();

		print();

		// after the the logic for one players turn is finished it swaps to the other players turn.
		playerTurn *= -1;
	}

	gameOver();

	return 0;
}