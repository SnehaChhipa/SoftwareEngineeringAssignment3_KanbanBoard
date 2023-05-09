#include "types.h"

#ifndef KANBANSTYLEBOARD_LOADSAVEDISPLAY_H
#define KANBANSTYLEBOARD_LOADSAVEDISPLAY_H

boardPtr loadDataFromFile(); //This function returns a pointer to the head of the new linked list. The 'startNode'
// is main.c is then updated with the new pointer returned from this function.
void displayBoard(boardPtr startNode);
void savingBoardToFile(boardPtr startNode);
#endif //KANBANSTYLEBOARD_LOADSAVEDISPLAY_H
