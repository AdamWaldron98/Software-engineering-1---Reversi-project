/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

//Define the set function
void set(int x,int y,int x_1,int y_1, int pT)
{
	int i,j;
	
	// set function places the current players disk type on the board.
	// set function will only be called by the check function when a valid move has been choosen by the current player.
	

	// placing disks in diagonal directions requires different code to horizontial or vertical directions.
	if(x != x_1 && y != y_1 )
	{
		// up and right
		if(y < y_1)
		{
			for(i = x,j = y;i <= x_1;i++,j++)
			{
					if(pT == 1)
						b.board[i][j] = '1';
					else
						b.board[i][j] = '0'; 
			}
		}
		// down and right.
		else
		{
			for(i = x,j = y;i <= x_1;i++,j--)
			{
					if(pT == 1)
						b.board[i][j] = '1';
					else
						b.board[i][j] = '0';
			}
		}
	}	
	// horizontial and vertical.
	else
	{
		for(i = x;i <= x_1;i++)
		{
			for(j = y;j <= y_1;j++)
			{
				if(pT == 1)
					b.board[i][j] = '1';
				else
					b.board[i][j] = '0';
			}
		}
	}
}