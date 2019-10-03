/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

//Check if there are available positions
int check(int x, int y, int pT, int turn, int endGameCheck)
{
	int i,j;
	int possibleMove = 0; 

	char currentPlayerDiskColour;
	char otherPlayerDiskColour;

	// storing disk types in variables at the start of function so the game logic below can remain the same when checking for different players turns.
	if(pT == 1)
	{
		currentPlayerDiskColour = pOne.diskType;
		otherPlayerDiskColour = pTwo.diskType;
	} 
	else
	{
		currentPlayerDiskColour = pTwo.diskType;
		otherPlayerDiskColour = pOne.diskType;	
	}

	// initialise valid and legal move to 0 and 1 respectively
	int valid = 0;
	int legalMove = 1;
	
	// first checks if the positiion is an empty cell.
	if(b.board[x][y] == ' ')
	{
		// code to check all the directions the move can be made.
		// all four segments below work identically but just check different directions so we will only explain how one works.
		valid = 0;
		for(i = x-1;i >= 0;i--)
		{
			// checks if the adjecent cell is filled by the other players disk; otherwise it deems this move invalid.
			// then checks the following cells in that direction until it comes across one of the current players type 
			// and deems it a valid move or it comes across an empty cell and deems the move invalid.
			if(b.board[x-1][y] != otherPlayerDiskColour)
				break;

			if(b.board[i][y] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][y] == ' ')
				break;

			if(b.board[i][y] == currentPlayerDiskColour && valid == 1)
			{
				// if this is the players actual choice and not just the program checking what moves can be made than the game
				// will change the board accordingly. other wise the program will just print out the co-ordinates of the vaild move.
				if(turn == 1)
				{
					possibleMove = 1;
					set(i,y,x,y,pT);
					break;
				}
				else
					add(&startPtr, x, y); // calls the function that adds a node to the linked list.
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		valid = 0;
		for(i=x+1;i<size;i++)
		{
			if(b.board[x+1][y] != otherPlayerDiskColour)
				break;

			if(b.board[i][y] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][y] == ' ')
				break;

			if(b.board[i][y] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(x,y,i,y,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		valid = 0;
		for(i=y-1;i>=0;i--)
		{
			if(b.board[x][y-1] != otherPlayerDiskColour)
				break;

			if(b.board[x][i] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[x][i] == ' ')
				break;

			if(b.board[x][i] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(x,i,x,y,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		valid = 0;
		for(i=y+1;i<size;i++)
		{
			if(b.board[x][y+1] != otherPlayerDiskColour)
				break;

			if(b.board[x][i] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[x][i] == ' ')
				break;

			if(b.board[x][i] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(x,y,x,i,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;
				
				legalMove = 0;
				valid = 0;

				break;
			}
		}
		valid = 0;
// diagional check.
		for(i = x + 1,j = y + 1;i < size,j < size;i++,j++)
		{
			if(b.board[x+1][y+1] != otherPlayerDiskColour)
				break;

			if(b.board[i][j] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][j] == ' ')
				break;

			if(b.board[i][j] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(x,y,i,j,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		for(i=x+1,j=y-1;i<size,j>=0;i++,j--)
		{
			if(b.board[x+1][y-1] != otherPlayerDiskColour)
				break;

			if(b.board[i][j] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][j] == ' ')
				break;

			if(b.board[i][j] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(x,y,i,j,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		for(i=x-1,j=y-1;i>=0,j>=0;i--,j--)
		{
			if(b.board[x-1][y-1] != otherPlayerDiskColour)
				break;

			if(b.board[i][j] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][j] == ' ')
				break;

			if(b.board[i][j] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(i,j,x,y,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
		for(i=x-1,j=y+1;i>=0,j<size;i--,j++)
		{
			if(b.board[x-1][y+1] != otherPlayerDiskColour)
				break;

			if(b.board[i][j] == otherPlayerDiskColour)
				valid = 1;
			else if(b.board[i][j] == ' ')
				break;

			if(b.board[i][j] == currentPlayerDiskColour && valid == 1)
			{
				if(turn == 1)
				{
					possibleMove = 1;
					set(i,j,x,y,pT);
					break;
				}
				else
					add(&startPtr, x, y);
				if(endGameCheck == 1)
					endGameState[0] += 1;

				legalMove = 0;
				valid = 0;

				break;
			}
		}
	}
	if((!possibleMove) && turn == 1)
	{
		int x_temp = 0,y_temp = 0;

		if(pT == 1)
			printf("%s, invalid move, please enter a valid one:\n", pOne.name);
		else
			printf("%s, invalid move, please enter a valid one:\n", pTwo.name);

		scanf("%d,%d", &x_temp, &y_temp);
		x_temp--;y_temp--;
		check(x_temp, y_temp, pT, turn, endGameCheck);
	}

	return endGameState[0];
}