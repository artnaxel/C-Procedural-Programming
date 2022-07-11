/*

Aleksandra Kondratjeva

Ivesti sveika skaiciu N. Ivesti N*N sveiku skaiciu, kurie sudarys kvadratine matrica. Patikrinti, ar ji yra magiskas kvadratas, t.y. visu stulpeliu, eiluciu
ir istrizainiu sumos vienodos.

*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
//
int checkTheNumber();
//
bool isMagicSquare(int n, int matrix[][n]);
//
int main (){	
	int n;
	
	printf("Please, enter an integer N: ");
	n = checkTheNumber();
	
	if (n == 0){  
		printf("The matrix is empty.\n");
	}
	
	else{
	    printf("Please, enter %d x %d elements of matrix:\n", n, n );
        
		//Jei n neigiamas naikinamas jo zenklas	
	    if (n < 0){
		    n *= -1;
	    }
	    
	    
	    int matrix[n][n]; 
	    
	    for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("Enter element matrix[%d][%d]: ", i + 1, j + 1);
                matrix[i][j] = checkTheNumber();
            }
        }
        
        printf("\nMatrix is:\n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
        	    printf("%2d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        //Check if the matrix is a magic square
        if(isMagicSquare(n, matrix)){
    	   printf("This matrix is a magic square.");
	    }
	    else{
		   printf("This matrix is not a magic square.");
	    }
	}
	
 	return 0;
}
 //
 int checkTheNumber(){
 
	int num;
	while(1){
		if ((scanf ("%d", &num) == 1) && (getchar() == '\n')){
		    return num;
	    }
		else{
			while ((getchar()) != '\n');
			printf ("Invalid input! Try again!\n");
		}
	}
}
//
bool isMagicSquare(int n, int matrix[][n]){
	
	//Main diagonal sum
	int mainDiagonal = 0;
    for(int i = 0; i < n; i++)
        mainDiagonal += matrix[i][i];
    
	//Sub diagonal sum  
    int subDiagonal = 0;
    for(int i = 0; i < n; i++)
        subDiagonal += matrix[i][n-i-1];
        
    if(mainDiagonal != subDiagonal)
        return false;
    
	//Column and row sum   
    for (int i = 0; i < n; i++){
        int row = 0, column = 0;   
        for (int j = 0; j < n; j++){
            row += matrix[i][j];
            column += matrix[j][i];
        }
        if (row != column || column != mainDiagonal)
            return false;
    }
   return true;    
}
