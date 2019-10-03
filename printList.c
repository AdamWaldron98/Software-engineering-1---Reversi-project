/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

//Prints the list of co-ordinates available
void printList(list currentPtr)
{

	while(currentPtr != NULL)
	{
		printf("\t\t%d,%d\n",currentPtr->x+1,currentPtr->y+1);
		currentPtr = currentPtr->nextPtr;
	}
}