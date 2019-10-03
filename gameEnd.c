/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void gameOver(void)
{
	printf("\n\n\n\t\t\tPlayer 1: %s\tpoints: %2d\n\t\tPlayer 2: %s\tpoints: %2d",pOne.name,pOne.score,pTwo.name,pTwo.score);
	printf("\n\t\t\tThe winner of the game is ");
		if(pOne.score > pTwo.score)
			printf("%s",pOne.name);
		else
			printf("%s",pTwo.name);
	//Output to a file the result of the game
	FILE *goPtr;

	if((goPtr = fopen("GameResult.txt", "w")) == NULL)
	{
		printf("File could not be opened.");
	}

	else
	{
		fprintf(goPtr, "Player1 %s, Points: %d", pOne.name, pOne.score);
		fprintf(goPtr, "Player2 %s, Points: %d", pTwo.name, pTwo.score);

		//Check who the winner us
		if(pOne.score > pTwo.score)
		{
			fprintf(goPtr, "The winner is: %s\n ", pOne.name);

		}
		else
		{
			fprintf(goPtr, "The winner is: %s\n",pTwo.name);
		}
		
		fclose(goPtr);
	}			
}