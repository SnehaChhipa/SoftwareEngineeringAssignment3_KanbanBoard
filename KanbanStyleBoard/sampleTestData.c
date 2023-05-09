#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sampleTestData.h"
#include "types.h"

boardPtr stPtr=NULL;

boardPtr sampleBoardContent() {

    boardPtr board1Ptr;
    board1Ptr = malloc(sizeof(Board)); // Allocate memory the size of struct "board" for boardPtr1
    stPtr = board1Ptr;  // set start pointer equal to address of board1Ptr


    // Start of board linked list, so previous node is NULL
    board1Ptr->prevBoard = NULL;
    // initialise first board name
    strcpy(board1Ptr->boardName, "Ford:");

    // Item linked list for first board node
    // Allocate memory the size of struct item for struct item
    itemPtr B1_item1Ptr = malloc(sizeof(Item));
    board1Ptr->itemList = B1_item1Ptr;
    // Start of item linked list, so previous node points to NULL
    B1_item1Ptr->prevItem = NULL;
    // initialise first item name
    strcpy(B1_item1Ptr->itemName, "Ford_Focus");
    itemPtr B1_item2Ptr = malloc(sizeof(Item));
    B1_item1Ptr->nxtItem = B1_item2Ptr;
    B1_item2Ptr->prevItem = B1_item1Ptr;
    // initialise second item name
    strcpy(B1_item2Ptr->itemName, "Ford_Galaxy");
    // End of item linked list, so next node points to NULL
    B1_item2Ptr->nxtItem = NULL;

    // Second node of board linked list

    // Allocate memory the size of struct "board" for boardPtr2
    boardPtr board2Ptr = malloc(sizeof(Board));
    // Initialise the next node of the board linked list
    board1Ptr->nxtBoard = board2Ptr;

    // Item linked list for second board node
    // linked second board node to first board node
    board2Ptr->prevBoard = board1Ptr;
    // initialise second board name in linked list
    strcpy(board2Ptr->boardName, "BMW:");

    // allocate memory for first item in second board
    itemPtr B2_item1Ptr = malloc(sizeof(Item));

    board2Ptr->itemList = B2_item1Ptr;
    // start of item linked list, so previous node points to NULL
    B2_item1Ptr->prevItem = NULL;
    // initialise first item name in linked list
    strcpy(B2_item1Ptr->itemName, "BMW iX");
    // allocate memory for second item in item list
    itemPtr B2_item2Ptr = malloc(sizeof(Item));
    B2_item1Ptr->nxtItem = B2_item2Ptr;
    B2_item2Ptr->prevItem = B2_item1Ptr;
    strcpy(B2_item2Ptr->itemName, "BMW i4 M50");
    // allocate memory for third item in item list
    itemPtr B2_item3Ptr = malloc(sizeof(Item));
    B2_item2Ptr->nxtItem = B2_item3Ptr;
    B2_item3Ptr->prevItem = B2_item2Ptr;
    strcpy(B2_item3Ptr->itemName, "BMW iX1");
    // end of item linked list, so next node points to NULL
    B2_item3Ptr->nxtItem = NULL;


    boardPtr board3Ptr = malloc(sizeof(Board));
    board2Ptr->nxtBoard = board3Ptr;

    board3Ptr->prevBoard = board2Ptr;
    strcpy(board3Ptr->boardName, "Toyota:");
    itemPtr B3_item1Ptr = malloc(sizeof(Item));
    board3Ptr->itemList = B3_item1Ptr;
    B3_item1Ptr->prevItem = NULL;
    strcpy(B3_item1Ptr->itemName, "Aygo X");
    itemPtr B3_item2Ptr = malloc(sizeof(Item));
    B3_item1Ptr->nxtItem = B3_item2Ptr;
    B3_item2Ptr->prevItem = B3_item1Ptr;
    strcpy(B3_item2Ptr->itemName, "Yaris");
    B3_item2Ptr->nxtItem = NULL;

    boardPtr board4Ptr = malloc(sizeof(Board));
    board3Ptr->nxtBoard = board4Ptr;

    board4Ptr->prevBoard = board3Ptr;
    strcpy(board4Ptr->boardName, "Mercedes:");
    itemPtr B4_item1Ptr = malloc(sizeof(Board));
    board4Ptr->itemList = B4_item1Ptr;
    B4_item1Ptr->prevItem = NULL;
    strcpy(B4_item1Ptr->itemName, "EQE Saloon");
    B4_item1Ptr->nxtItem = NULL;

    board4Ptr->nxtBoard = NULL;

    return stPtr;

}
