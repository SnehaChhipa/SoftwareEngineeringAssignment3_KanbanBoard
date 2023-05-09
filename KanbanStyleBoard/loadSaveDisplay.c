#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadSaveDisplay.h"
#include "types.h"

boardPtr fileData_StartNode;


boardPtr loadDataFromFile(){

    char fileName[MAX_CHAR];
    char string[MAX_CHAR];
    int length, boardCounter = 0, itemCounter = 0;

    boardPtr newBoardNode, prevBoardNode;
    itemPtr newItemNode, prevItemNode;

    FILE *loadFile;

    getchar(); //Stores the unnecessary '\n' character, after receiving userChoice input.

    printf("\nPlease enter filename to load data from:\n");
    fgets(fileName, MAX_CHAR, stdin);
    length=strlen(fileName);
    fileName[length-1]='\0';

    loadFile=fopen(fileName, "r");

    if(loadFile==NULL){
        printf("\nError opening file.\n");
    }

    else{
        printf("\nFile successfully read.\n");

        while(fgets(string, MAX_CHAR, loadFile) != NULL) {

            length=strlen(string);
            string[length-1]='\0'; //Adding the null terminator

            if (strchr(string, ':')!=NULL) { //If the string is containing a ':', this suggests that the string is a board name.
                newBoardNode= malloc(sizeof(Board));
                boardCounter++;
                itemCounter = 0; //When a new board is created, initially it has no items, therefore itemCounter is re-set to 0.

                if (boardCounter == 1) { //i.e. first node!
                    newBoardNode->prevBoard=NULL;
                    strcpy(newBoardNode->boardName, string);
                    prevBoardNode = newBoardNode;
                }
                else {
                    prevBoardNode->nxtBoard = newBoardNode; //Linking the new board created with the previous board.
                    if (boardCounter == 2) {
                        fileData_StartNode = prevBoardNode; //Storing head of list in 'fileData_StartNode'
                    }
                    newBoardNode->prevBoard = prevBoardNode;
                    strcpy(newBoardNode->boardName, string);
                    prevBoardNode = newBoardNode;
                }
            }
            else {
                newItemNode=malloc(sizeof(struct item));
                itemCounter++;

                if (itemCounter == 1) {
                    if (boardCounter > 1) {
                        prevItemNode->nxtItem = NULL; //Closing the previous item list, when a new item list is created (when itemCounter is only 1).
                    }
                    prevBoardNode->itemList = newItemNode; //Linking item to Board.
                    newItemNode->prevItem = NULL;
                    strcpy(newItemNode->itemName, string);
                    prevItemNode = newItemNode;
                }
                else {
                    prevItemNode->nxtItem = newItemNode;
                    newItemNode->prevItem = prevItemNode;
                    strcpy(newItemNode->itemName, string);
                    prevItemNode = newItemNode;
                }

            }

        }

        prevBoardNode->nxtBoard = NULL;
        prevItemNode->nxtItem = NULL;

    }

    fclose(loadFile);
    return fileData_StartNode;
}



void savingBoardToFile(boardPtr startNode) { // Takes the file pointer and the "head" of the board linked list as parameters
    int length;
    char fileName[MAX_CHAR];

    // declaring the pointer to board struct
    boardPtr head = startNode;

    // take the previous
    getchar();
    printf("\nPlease enter filename to write data to:\n");
    fgets(fileName, MAX_CHAR, stdin);
    length=strlen(fileName);
    fileName[length-1]='\0';

    // declare file pointer and open in write mode
    FILE *writeFile;
    writeFile=fopen(fileName, "w");

    // check if file cannot be opened
    if(writeFile==NULL)
    {
        // print error message
        printf("\nError opening file.\n");
    }

    else
    {
        // declare the pointer to the item linked list
        itemPtr itemListNode;

        // loop will keep going until it reaches the end of the board linked list
        while(head!=NULL){

            // write the board name string into file
            fprintf(writeFile, "%s\n", head->boardName);

            // initialise the item list pointer to the current board node's item list
            itemListNode=head->itemList;
            // loop will keep going until it reaches the end of the item linked list
            while(itemListNode!=NULL){
                // write the item list name string into file
                fprintf(writeFile, "\t%s\n", itemListNode->itemName);
                // move on to the next node in item linked list
                itemListNode=itemListNode->nxtItem;
            }

            // move on to the next node in board linked list
            head = head->nxtBoard;
        }
    }

    // close file after writing is finished
    fclose(writeFile);
}




void displayBoard(boardPtr startNode) {
    boardPtr head = startNode;
    //printf("prev = %s\n", head->prevBoard->boardName);
    itemPtr itemListNode;

    printf("\n");
    while(head!=NULL){
        printf("%s\n", head->boardName);
        itemListNode=head->itemList;

        while(itemListNode!=NULL){
            printf("\t%s\n", itemListNode->itemName);

            itemListNode=itemListNode->nxtItem;
        }
        head=head->nxtBoard;
    }
}
