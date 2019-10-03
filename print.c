/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"
void print(void)
{
	//Clears the console
	system("cls");

    //Loop to print the empty board
	for(int j=size-1;j>=0;j--)
	{
		printf("%d |",j+1);

		//Loop to print the starting positions
		for(int i=0;i<size;i++)
		{
			printf("%2c |",b.board[i][j]);
		}
		printf("\n\n");
	}

	//Prints the outline of the board
    printf("%5d%4d%4d%4d%4d%4d%4d%4d\n",1,2,3,4,5,6,7,8);

	//Prints current status of the game
	printf("\n\n\tPlayer One: %s\t\tScore: %2d",pOne.name, pOne.score);
	printf("\n\tPlayer Two: %s\t\tScore: %2d",pTwo.name, pTwo.score);
	printf("\n\tTotal Remaining places: %d\n",b.totalRemaining);
}