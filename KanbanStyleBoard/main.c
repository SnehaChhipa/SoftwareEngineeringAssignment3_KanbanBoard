#include <stdio.h>
#include "edit.h"
#include "loadSaveDisplay.h"
#include "sampleTestData.h"
#include "types.h"

//We have two different test data included in our project. One set of data is the manually coded in data directly in linked
// lists, in sampleTestData.c .The second set of data is a text file, from which sample test data can be loaded. The name of
//the txt file is "loadingtest.txt"

int main(void) {
    boardPtr startNode; //Head of linked list.
    int userChoice;

    startNode = sampleBoardContent(); //Initializing starting node of Linked List with sample the sample data stored in sampleTestData.c


    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Display board\n");
        printf("2. Load board from a file\n");
        printf("3. Edit list\n");
        printf("4. Edit board\n");
        printf("5. Save board to a file\n");
        printf("6. Quit\n");
        printf("Enter your choice (1-6):");

        scanf("%d", &userChoice);

        while(userChoice<1 || userChoice > 6)
        {
            printf("\nInvalid input\n");
            printf("Enter your choice (1-6):");
            scanf("%d", &userChoice);
        }

        switch(userChoice)
        {
            case 1:
                displayBoard(startNode);
                break;

            case 2:
                startNode = loadDataFromFile();
                break;

            case 3:
                editList(startNode);
                break;

            case 4:
                startNode = editBoard(startNode);
                break;

            case 5:
                savingBoardToFile(startNode);
                break;

            case 6:
                printf("\nEnding program...\n");
                break;
        }

        if(userChoice==6)
        {
            printf("_______________________$$$$$$$$___________________\n");
            printf("_______________________$$$$$$$$$$$$$______________\n");
            printf("___________$$__________$$$$$____$$$$______________\n");
            printf("_________$$$$$_________$$$$$$$$$$$$$______________\n");
            printf("________$$$$$$$________$$$___$$$$$$$____$$$_______\n");
            printf("_______$$$__$$$________$$$________$$$___$$$_______\n");
            printf("______$$$___$$$_________$$________$$$____$$$______\n");
            printf("______$$$__$$$$_________$$_________$$_____$$$_____\n");
            printf("______$$$_$$$$______$$__$$$________$$$_____$$$____\n");
            printf("_______$$$$$$_____$$$$$$$$$________$$$______$$$___\n");
            printf("______$$$$$$_____$$$$$$$$$$__$$$$$$$$$_______$$$__\n");
            printf("____$$$$$$_______$$$$$$$$$$_$$$$$$$$$$________$$$_\n");
            printf("___$$$$$$$________$$$$$$$___$$$$$$$$$$_________$$_\n");
            printf("__$$$$__$$$$$$$$_____$$______$$$$$$$$______$$$$$$$\n");
            printf("_$$$$__$$$$$$$$$$$___$$$$$_____$$$________$$$$$$$$\n");
            printf("$$$$__$$$$$$$$$$$$$__$$$$$$$$____________$$$$$$$$$\n");
            printf("$$$$_$$$$$$$___$$$$___$$$$$$$$$$_________$$$$$$$$$\n");
            printf("$$$__$$$__$$____$$$____$$$_$$$$$$$________$$$$$$$$\n");
            printf("$$$$__$$__$$$___$$$____$$$____$$$$$$__________$$__\n");
            printf("_$$$$_____$$$__$$$$_____$$$_____$$$$______________\n");
            printf("_$$$$$$$___$$$$$$$_______$$$_____$$$______________\n");
            printf("___$$$$$$$$$$$$_________$$$______$$_______________\n");
            printf("_______$$$$$$$____________$$$_____$_______________\n");
            printf("____________$$$____________$$$____________________\n");
            printf("____$$$$$$__$$$________$$$$$$$____________________\n");
            printf("____$$$$$$$_$$$______$$$$$$$$$$___________________\n");
            printf("____$$$$$$_$$$______$$$$$$$$$$$$__________________\n");
            printf("_____$$$$$$$$$______$$$$$$$$$$$___________________\n");
            printf("_______$$$$$_________$$$$$$$$$____________________\n");
            printf("______________________$$$$$$______________________\n");
            break;
        }
    }
}
