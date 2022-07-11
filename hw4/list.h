//Guard
#ifndef LIST_H_INCLUDED 
#define LIST_H_INCLUDED
//
typedef struct Node {
    int data; //value
    struct Node *next; //pointer to the next element
} Node;
//
void printMenu();
//
void controlMenu();
//
void readNum(int *num);
//
void fillTheList(int len, int numbers[], Node **);
//
int checkNewList(Node **);
//
void createNewList (int len, int numbers[], Node *);
//
void deleteSmallestNode (Node **, int );
//
int sizeOfList(Node *);
//
void printList(Node *);
//
void deleteList(Node **);
//
#endif
