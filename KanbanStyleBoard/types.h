#ifndef KANBANSTYLEBOARD_TYPES_H
#define KANBANSTYLEBOARD_TYPES_H
#define MAX_CHAR 30

struct item {
    struct item *prevItem;
    char itemName[30];
    struct item *nxtItem;
};

struct board{
    struct board *prevBoard;
    char boardName[30];
    struct item *itemList;
    struct board *nxtBoard;
};

typedef struct board Board;
typedef Board* boardPtr;

typedef struct item Item;
typedef Item *itemPtr;


#endif //KANBANSTYLEBOARD_TYPES_H
