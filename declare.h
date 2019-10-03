/*
*
* Created by Luke Murphy --17426404-- & Adam Waldron --17380553--
*
*/
#define size 8

// declaration of global variables.
int endGameState[2];

//struct to represent our players.
typedef struct player{
	char name[20];
	char diskType;
	int numOfDiscsPlaced;
	int score;

}player;

//Declaration of player variable synonyms
player pOne;
player pTwo;

//Struct to represent board
typedef struct game{
	char board[size][size];
	int totalRemaining;
}game;

//Declaration of game variable synonym
game b;

//Struct to represent the disks.
typedef struct disk{
	int disk;
	int diskPositionAndType[8][8][1];
}disk;

typedef struct node {
	int x;
	int y;
	struct node *nextPtr;
}node;
/*typedef struct node node;*/
typedef node *list;

list startPtr;

//Declaration of functions.
void input(void);
void print();
int check(int x, int y, int pT, int turn, int endGameCheck);
void set(int x,int y,int x_1,int y_1, int pT);
void scoreUpdate(void);
void gameOver(void);
int add(list *sPtr, int x, int y);
void printList(list currentPtr);