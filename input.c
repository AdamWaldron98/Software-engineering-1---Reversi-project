/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "declare.h"

//Function to get input from user.
void input(void)
{
	printf("Player One please enter your first name: ");
	scanf("%s",pOne.name);
	printf("Player Two please enter your first name: ");
	scanf("%s",pTwo.name);
	system("cls");
}
