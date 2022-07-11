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
    printMenu();
    printf("\nPlease, enter the number from 0 to 6.\n");
    controlMenu(head);
    return 0;
}

/*User interface*/
void printMenu()
{
    printf("Menu:\n");
    printf("0   create a list \n");
    printf("1   print the list\n");
    printf("2   remove the smallest node\n");
    printf("3   clear command prompt\n");
    printf("4   list size\n");
    printf("5   delete list\n");
    printf("6   exit\n");
}

/*Main logic*/
void controlMenu(Node *head){   
    int num;
    
    int size;
    int len;
    do{       
        readNum(&num);
        switch (num){
            case 0:
            	//creating the list
                printf("Please enter list length (0; 10]: ");
                while(1){
                	//validation
                	int scan = scanf("%d",&len);
                	if ((scan != 1) || (len > MAX_SIZE) || (len <= 0) || (!isspace(getchar()))){
                		printf("Wrong input! Try again. The length is:\n");
                		scanf("%*[^\n]");
					}
					else{
						break;
					}
				}
				
                int *numbers =(int*) malloc(len * sizeof(int));
                
                for (int i = 0; i < len; ++i){
            	    while(1){
            		//validation
            	        int scan = scanf("%d",&numbers[i]);
            		    if ((scan != 1) || (numbers[i] > MAX_DATA_VAL) || (numbers[i] < MIN_DATA_VAL) || (!isspace(getchar()))){
            			    printf("Wrong input! Try again.\n");
            			    scanf("%*[^\n]");
					    }
					    else{
						    break;
					    }
				    }
			    }
			    
                fillTheList(len, numbers, &head);    
                break;

            case 1:
                //printing
                printList(head);
                break;

            case 2:
                //deleting the smallest node
                printf("Removing the smallest node...\n");
                int numeris;
                deleteSmallestNode(&head, numeris);
                break;

            case 3:
                //clear cmd
                system("cls");
                printMenu();
                break;

            case 4:
                //print list size
                size = sizeOfList(head);
                printf("Size of list: %d\n", size);
                break;

            case 5:
            	//deleting the list
                if (head != NULL){
                	printf("The list was succesfully deleted!");
                	free(numbers);
                	len = 0;
                    deleteList(&head);   
                }
                else{
                	printf("The list doesn't exist!");
				}
                break;
            case 6:
            	//exit
                printf("End\n");
                if (head != NULL){
                    deleteList(&head);   
                }
                exit(0);
            default:
                //the wrong menu input (not between 0 and 6)
                printf("Bad menu input!\n");
                break;
        }
        printf("\nPlease, enter the number from 0 to 6.\n");
    } while (num != 6);    
}
//
void readNum(int *num){
    while (scanf("%d", num) != 1 || getchar() != '\n'){
        scanf("%*[^\n]");
        printf("Bad input!\n");
    }
}
