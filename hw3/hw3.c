/*

Aleksandra Kondratjeva

Parasyti funkcija, kuri duoto teksto kiekvienos eilutes zodzius perraso atvirksscia tvarka (simboliu tvarka zodyje nesikeicia,
bet keiciasi zodziu tvarka; tarpu skaicius turi likti nepakites).

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//
#define BUFFER_SIZE 1024
//
void parameters(int argc, char *argv[], int *flag, char fileName[], FILE **fd, FILE **fr);
//
void reverse(char *s);
//
void allocate(char **ptr, int size);
// 
void close_files(FILE **rd, FILE **rf);
//
int main (int argc, char *argv[]){
	
   FILE *fd; 
   FILE *fr; 

   int flag = 0;

   char *buff;
   char *fileName;
   
   if (argc == 1)
   allocate(&fileName, 30);
   
   parameters(argc, argv, &flag, fileName, &fd, &fr);
   allocate(&buff, BUFFER_SIZE);
   
    //Input and Output
    while(fgets(buff, BUFFER_SIZE, fd) != NULL){

        reverse(buff);

        if (flag == 0){
            fputs(buff, fr);
            fprintf(fr, "\n");
        }
        else{
            printf("%s\n", buff);
        }
    }

    if (argc == 1)
       free(fileName);
    free(buff);
    close_files(&fd, &fr);

    return 0;
}
//
void parameters(int argc, char *argv[], int *flag, char *fileName, FILE **fd, FILE **fr){ 

    if (argc == 1){
        while(1){
            printf("Please enter data file name: ");
            scanf("%s", fileName);
            *fd = fopen(fileName, "r");
            if(*fd != NULL){
                break; 
            }

        }
    }
    else if(argc >= 2){
    	*fd = fopen(argv[1], "r");
    	if (*fd == NULL){ 
    		printf("Error opening data file!\n"); 
    	    exit(1);
        }
	}
   if (argc == 3){
   	    *fr = fopen(argv[2], "w");
   }
   else{
   	    *flag = 1;
   }
}
//
void reverse (char *s){ //

    size_t len = strlen(s);

    if (s[len - 1] == '\n')
    len--;

    //Transfering chars from the end of the string to the front
    for ( size_t i = 0; i < len/2; i++ ){ //labas vakaras ---> sarakav sabal
        char temp = s [i]; 
        s[i] = s [len - i - 1];
        s [len - i - 1] = temp;

    }
    s[len] ='\0';

    //Transfering chars from the end of the word to the front (i - length of the string, j - length of the word)
    for ( size_t i = 0, j = 0; i <= len; ++i, ++j ) 
        if ( s[i] == ' '  || s[i] == '\0' ){ 
            for ( size_t t = 0; t < j/2; ++t ){  //t - how many chars were transferred, j/2 - half of the word
                char temp = s [i - t - 1];  // sarakav ----> vakaras
                s [i - t - 1] = s[i - j + t];
                s [i - j + t] = temp;
        }
            ++i; //moving to the next char in the string (the word is reversed)
            j = 0; //length of the word == 0
    }
}
//
void allocate(char **ptr, int size){
    *ptr = (char*)malloc(size * sizeof(char));
    if (*ptr == NULL){
        printf("\nError allocating data!\n");
        exit(1);
    }
}
//
void close_files(FILE **rd, FILE **rf){
        fclose(*rd);
        fclose(*rf);
}
