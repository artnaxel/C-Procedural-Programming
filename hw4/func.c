#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10
#define MAX_DATA_VAL 1000
#define MIN_DATA_VAL -1000

#include "list.h"

void fillTheList(int len, int numbers[],  Node **head){   
    //Check if the list was created
    if (checkNewList(head)){
        createNewList(len, numbers, *head);
    }

    //If the list exists
    else{
    	printf("The list already exists! Delete it and try again.");
    }
    assert(*head!= NULL);
}

/*Create the list if it doesn't exist*/
int checkNewList(Node **head){
    if (*head == NULL){
    	//allocating the memory for the list
        *head = (Node*)malloc(sizeof(Node));
        printf("The list was created.\n");
        return 1;
        assert(*head != NULL);
    }
    return 0;
}

/*Filling the list with data*/
void createNewList(int len, int numbers[], Node *head){   
    int number;
    
    Node *current = head;
    Node *ending = head;
    
        current -> data = numbers[0];
        current -> next = NULL;
        //head = current;
        //ending = current;

    for (int i = 1; i < len; ++i){
        current = (Node*)malloc(sizeof(Node));
        current->data = numbers[i];
        current->next = NULL;
        ending->next = current;
        ending = current;
    }
    assert(current != NULL);
    assert(head != NULL);   
}

/*Delete the smallest node*/
void deleteSmallestNode(Node **head, int number){  

    //checking if the list exists 
    assert(*head != NULL);
    if (*head == NULL){
        printf("The list doesn't exist.\n");
        return;
    }

    int size;

    assert(&number != NULL);

    //getting the list size
    size = sizeOfList(*head);
    
    //algorithm of finding the smallest node
    Node *current = *head;
    int min = current->data;
    number = 1; //position of smallest
    int currentNum = 1;
    
    while (current != NULL){   
        if(current->data < min){
            min = current->data;
            number = currentNum;
        }
        current = current->next; //moving to the next node
        currentNum++;
    }
    printf("The smallest node was found! The value is %d, and it's number is %d\n", min, number);
    current = *head;

    //Deleting the element with position 'number'
    if (number > 0 && number <= size){   
        //If we want to delete the first node
        if (number == 1){
            *head = current -> next;
            free(current);
            return;
        }
        else{   
            //Deleting the node and connecting parts of the list
            for (int i = 0; i < number - 2; ++i){
                current = current -> next;
            }
            Node *newNode = current -> next -> next;

            free(current -> next);
            current -> next = newNode;
        }     
    }
    else{
       printf("Item with this number doesn't exist.'\n");
    }
}

/*Find the size of list */
int sizeOfList(Node *head){
	assert(head != NULL);
    int size = 0;
    while (head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

/*Print the whole list*/
void printList(Node *head){
    assert(head != NULL);
    int i = 1;
    
    puts("*****************************************");
    puts("List:");

    while (head != NULL){
        printf( "%d element is %d\n", i, head->data );
        head = head -> next;
        ++i;
    }
}

/*Delete the list*/
void deleteList(Node **head){
	assert(*head != NULL);
    Node *current;
    Node *ending = *head;

    // The list will be deleted from the end, therefore me must find the address of last node
    while (ending -> next != NULL){
        ending = ending -> next;
    }

    //Deleting from the end
    while (*head != NULL){
        current = *head;
        if (ending!= *head){
            while (current -> next != ending){
                current = current -> next;
            }
            ending = current;
            free(current -> next);
        }

        //Delete the last element
        else{   
            free(current);
            *head = NULL;
            ending = NULL;
        }
    }
}

