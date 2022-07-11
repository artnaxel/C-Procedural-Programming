/*
   Aleksandra Kondratjeva
   4 namu darbas
   Sudaryti vienpusi sarasa. Parasyti procedura, kuri ismeta is saraso maziausia elementa.
   
   Norint paleisti testus/Run tests:
   gcc -c -std=c99 main_1.c func.c
   gcc -o main_test main_1.o func.o
   main_test.exe
   
   Vartotojo sasaja/User interface:
   gcc -c -std=c99 main_2.c func.c
   gcc -o main main_2.o func.o
   main.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10
#define MAX_DATA_VAL 1000
#define MIN_DATA_VAL -1000

#include "list.h"
//
int main(){
	Node *head = NULL;
    int numbers []= {47, -57, 1000, 101, 55};
    
    fillTheList(5, numbers, &head); //The list was created.
    assert(head -> data == 47);
    
    deleteSmallestNode(&head, 1); //The smallest node is -57, number 2
    assert(head -> data == 47);
    assert(head -> next -> data == 1000); //now in the position 'number' there is 1000 
    
    deleteSmallestNode(&head, 1); //The smallest node is 47, number 1
    assert(head -> data == 1000); //now in the position 'number' there is 1000 
    assert(head -> next -> data == 101);
    
    deleteSmallestNode(&head, 1); //The smallest node is 55, number 3
    assert(head -> data == 1000);
    assert(head -> next -> data == 101);
    assert(sizeOfList(head) == 2);
    
    deleteList(&head);
    assert (head == NULL);
return 0;
}
