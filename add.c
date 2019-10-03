/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

int add(list *sPtr, int x, int y){

	list newPtr = malloc(sizeof(node));
	
	if(newPtr != NULL)
	{
		newPtr->x = x;
		newPtr->y = y;
		newPtr->nextPtr = NULL;

		list previousPtr = NULL;
		list currentPtr = *sPtr;
		// runs through the list until the end or conditions inside the loop are met.
        while(currentPtr != NULL)
        {
        	previousPtr = currentPtr;
        	currentPtr = currentPtr->nextPtr;
        	// if the x and y values being checked are in the list already the functions ends. This stops duplicates being put in the list.
        	if(newPtr->x == previousPtr->x && newPtr->y == previousPtr->y)
        		return 0;
        }
        // this code will only run if the x and y arent in the list already.
		while(currentPtr != NULL && x >= currentPtr->x)
		{	
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}
		// for first in list.
		if(previousPtr == NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		// not first in list.
		else
		{
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
}