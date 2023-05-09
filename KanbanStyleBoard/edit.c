#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "edit.h"
#include "types.h"

int inputLength;
extern boardPtr fileData_StartNode;


void editList(boardPtr startNode) {
    char listName[30], itemName[30]; //Arrays to hold user input.
    int userChoice;
    bool listFound = false;
    bool initialNullNode = false;

    fpurge(stdin); //Clears stream before taking any input.
    printf("\nEnter the name of the list to edit:");
    fgets(listName, 30, stdin);
    inputLength = strlen(listName);
    listName[inputLength-1] = '\0'; //Replacing the new line character with the null terminator.

    //Declaring linked list pointers:
    boardPtr currentNode = startNode;
    boardPtr listNode;
    itemPtr currentItemNode;
    itemPtr itemNode;

    while(currentNode!=NULL) {
        if (strcmp(listName, currentNode->boardName)==0) {
            listNode = currentNode;
            listFound = true; //The struct pointer to the desired listNode has been found!
            break;
        }
        else {
            currentNode = currentNode->nxtBoard;
        }
    }

    if (listFound == false) {
        printf("Can't find list.\n");
    }
    else //if listNode is successfully found:
    {
        while(1) {
            bool itemFound = false;
            currentItemNode = listNode->itemList; //Pointer variable which is initialised to point to the first item of the selected list.
            itemNode = NULL; //In the beginning, the itemNode is not yet found.

            printf("\nOptions:\n");
            printf("1. Edit an Item.\n");
            printf("2. Add a new Item.\n");
            printf("3. Delete an Item.\n");
            printf("4. Return to main menu.\n");
            printf("Enter your option: ");
            fpurge(stdin);
            scanf("%d", &userChoice);

            while(userChoice<1 || userChoice > 4)
            {
                printf("\nInvalid input\n");
                printf("Enter your option (1-4):");
                fpurge(stdin);
                scanf("%d", &userChoice);
            }

            switch (userChoice)
            {
                case 1:
                    itemFound = false;
                    printf("Enter the name of the item to edit:");
                    fpurge(stdin);
                    fgets(itemName, 30, stdin);
                    inputLength = strlen(itemName); //Adding the null terminator
                    itemName[inputLength-1] = '\0';

                    while(currentItemNode!=NULL) { //Searching for the list name which the user wants to edit.
                        if (strcmp(itemName, currentItemNode->itemName)==0) {
                            itemNode = currentItemNode;
                            itemFound = true;
                            break;
                        }
                        else {
                            currentItemNode = currentItemNode->nxtItem;
                        }
                    }

                    if (itemFound == false) {
                        printf("Item can't be found.\n");
                    }
                    else {
                        char newItemName[30];
                        printf("Enter new name for item '%s':", itemName);
                        fpurge(stdin);
                        fgets(newItemName, 30, stdin);
                        inputLength = strlen(newItemName); //Adding the null terminator
                        newItemName[inputLength-1] = '\0';
                        strcpy(itemNode->itemName, newItemName);

                    }
                    break;

                case 2:
                    initialNullNode = false;
                    if (currentItemNode == NULL) { //If the board has no list items (an empty Item Structure)
                        initialNullNode = true;
                    }
                    else {
                        while(currentItemNode->nxtItem != NULL) { //Finding the last node:
                            currentItemNode = currentItemNode->nxtItem;
                        }
                    }

                    itemPtr newItem = malloc(sizeof(Item));

                    char newItemName[30];
                    printf("Enter the name of the new item:");
                    fpurge(stdin);
                    fgets(newItemName, 30, stdin);
                    inputLength = strlen(newItemName); //Adding the null terminator
                    newItemName[inputLength-1] = '\0';

                    if (initialNullNode == true) { //If the board has no list items (an empty Item Structure):
                        strcpy(currentItemNode->itemName, newItemName); //Filling in the first item structure.
                    }
                    else {
                        strcpy(newItem->itemName, newItemName);
                    }

                    newItem->nxtItem = NULL;

                    if (initialNullNode == true) { //Filling in the first item structure.
                        newItem->prevItem = NULL;
                        newItem->nxtItem = NULL;
                        currentItemNode = newItem;
                        listNode->itemList = currentItemNode;
                    }
                    else {
                        currentItemNode->nxtItem = newItem; //New node is linked to the linked list.
                        newItem->prevItem = currentItemNode;
                    }

                    break;

                case 3:
                    itemFound = false;
                    printf("Enter the name of the item to delete:");

                    char deleteItemName[30];
                    fpurge(stdin);
                    fgets(deleteItemName, 30, stdin); //Receiving user input.
                    inputLength = strlen(deleteItemName); //Adding the null terminator
                    deleteItemName[inputLength-1] = '\0';

                    itemPtr tempPtr;
                    itemPtr prevItemPtr;

                    if (strcmp(currentItemNode->itemName, deleteItemName)==0) { //If the item to be deleted is the first item in the list:
                        listNode->itemList = currentItemNode->nxtItem; //Changing links. Detaching the unwanted node.
                        tempPtr = currentItemNode;
                        free(tempPtr);
                    }
                    else {
                        while(currentItemNode!=NULL) { //Searching in the list for the node of the item to be deleted.
                            if (strcmp(deleteItemName, currentItemNode->itemName)==0) {
                                itemNode = currentItemNode;
                                itemFound = true; //Item found!
                                break;
                            }
                            else {
                                currentItemNode = currentItemNode->nxtItem;
                            }
                        }
                        if (itemFound == false) {
                            printf("Item can't be found.\n");
                        }
                        else {
                            tempPtr = itemNode;
                            prevItemPtr = itemNode->prevItem;
                            prevItemPtr->nxtItem = itemNode->nxtItem; //Changing links. Detaching the unwanted node.
                            free(tempPtr);
                        }
                    }

                    break;

                case 4:
                    printf("Returning to main menu.\n");
                    break;
            }

            if (userChoice == 4) {
                break;
            }

        }

    }
}


boardPtr editBoard(boardPtr startNode) {
    int userChoice;
    bool listFound;
    //Declaring Pointers:
    boardPtr currentNode = startNode;
    boardPtr listNode;

    printf("\nOptions:\n");
    printf("1. Edit the name of a list.\n");
    printf("2. Add a new list.\n");
    printf("3. Delete a list.\n");
    printf("4. Return to main menu.\n");
    printf("Enter your option: ");
    fpurge(stdin);
    scanf("%d", &userChoice);

    while(userChoice<1 || userChoice > 4)
    {
        printf("\nInvalid input\n");
        printf("Enter your option (1-4):");
        fpurge(stdin);
        scanf("%d", &userChoice);
    }

    switch (userChoice)
    {
        case 1:
            listFound = false;

            printf("Enter the name of the list to edit:");
            char listName[30], newListName[30];
            fpurge(stdin);
            fgets(listName, 30, stdin);
            inputLength = strlen(listName); //Adding the null terminator
            listName[inputLength-1] = '\0';


            while(currentNode!=NULL) { //Searching for the node of the Board name:
                if (strcmp(listName, currentNode->boardName)==0) {
                        listNode = currentNode;
                        listFound = true; //The struct pointer to the desired listNode has been found!
                    break;
                }
                else {
                    currentNode = currentNode->nxtBoard; //
                }
            }

            if (listFound == false) {
                printf("Can't find list.\n");
            }
            else //if listNode is successfully found:
            {
                printf("Enter new name for list '%s' :", listName);
                fpurge(stdin);
                fgets(newListName, 30, stdin);
                inputLength = strlen(newListName); //Adding the null terminator
                newListName[inputLength-1] = '\0';

                strcpy(listNode->boardName, newListName);
            }

            break;

        case 2:
            currentNode = startNode;

            while(currentNode->nxtBoard != NULL) { //Finding the last node:
                currentNode = currentNode->nxtBoard;
            }

            boardPtr newBoard = malloc(sizeof(Board));

            currentNode->nxtBoard = newBoard; //New node is linked to the linked list.
            newBoard->prevBoard = currentNode; //Setting values in the new board.
            newBoard->itemList = NULL; //Initially the board has no items.

            char newBoardName[30];
            printf("Enter the name of the new list:");
            fpurge(stdin);
            fgets(newBoardName, 30, stdin);
            inputLength = strlen(newBoardName); //Adding the null terminator
            newBoardName[inputLength-1] = '\0';

            strcpy(newBoard->boardName, newBoardName);
            newBoard->nxtBoard = NULL;

            break;

        case 3:
            currentNode = startNode;
            listFound = false;

            char deleteBoardName[30];
            boardPtr tempPtr, prevBoardPtr; //declaring some pointers

            printf("Enter the name of the list to delete:");
            fpurge(stdin);
            fgets(deleteBoardName, 30, stdin);
            inputLength = strlen(deleteBoardName); //Adding the null terminator
            deleteBoardName[inputLength-1] = '\0';


            if (strcmp(currentNode->boardName, deleteBoardName)==0) {  //If the Board to be deleted is the first board in the list.
                startNode = currentNode->nxtBoard; //Changing links. Detaching the unwanted node.
                tempPtr = currentNode;
                free(tempPtr);
            }
            else {
                while(currentNode!=NULL) { //Searching for the node in the list of the board to be deleted.
                    if (strcmp(deleteBoardName, currentNode->boardName)==0) {
                        listNode = currentNode;
                        listFound = true;
                        break;
                    }
                    else {
                        currentNode = currentNode->nxtBoard;
                    }
                }
                if (listFound == false) {
                    printf("List can't be found.\n");
                }
                else {
                    tempPtr = listNode;
                    prevBoardPtr = listNode->prevBoard;
                    prevBoardPtr->nxtBoard = listNode->nxtBoard; //Changing links. Detaching the unwanted node.
                    free(tempPtr);
                }
            }
            break;

        case 4:
            printf("Returning to main menu.\n");
            break;

    }

    return startNode;
}

