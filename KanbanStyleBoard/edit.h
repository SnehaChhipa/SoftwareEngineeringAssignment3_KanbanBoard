#include "types.h"

#ifndef KANBANSTYLEBOARD_EDIT_H
#define KANBANSTYLEBOARD_EDIT_H
boardPtr editBoard(boardPtr startNode); //This function returns a pointer to the head of the updated linked list. The 'startNode'
// is main.c is then updated with the new pointer returned from this function.
void editList(boardPtr startNode);
#endif //KANBANSTYLEBOARD_EDIT_H
