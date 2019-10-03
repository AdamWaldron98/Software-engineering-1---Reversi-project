/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

void scoreUpdate(void){
	int pOne_temp = 0, pTwo_temp = 0, totalRemaining_temp = 0;
	int i, j;

	// scans the board to check for 1's and 0's.
	for(i = 0;i < size;i++)
	{
		for(j = 0;j < size;j++)
		{
			if(b.board[i][j] == '1')
				pOne_temp++;
			else if(b.board[i][j] == '0')
				pTwo_temp++;
			else
				totalRemaining_temp++;
		}
	}

	// storing the temp values in the score variables.
	pOne.score = pOne_temp;
	pTwo.score = pTwo_temp;
	b.totalRemaining = totalRemaining_temp;
}