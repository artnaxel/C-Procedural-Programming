#include <stdio.h>
#include <ctype.h>

/*

Aleksandra Kondratjeva

Iveskite skaiciu seka, kurios pabaiga zymima skaiciumi 0. Isvesti nariu, kurie prasideda nelyginiu skaitmeninimi, skaiciu.

*/

int main(){
	int temp, num, k = 0;
	printf("Enter the sequence of integers ending with 0:\n");
	
	while(1){
		int scan = scanf ("%d", &num);
		
		while(isspace(getchar()) == 0) //if there are spaces, skip them
		    ;
		
		if ((scan == 1)){
			if (num == 0){
				printf("Succesfully ended the sequence!\n");
				break;
			}
			
		    if (num < 0){
		    	num *= -1;
			}
			
			temp = num * 10;
			while (num > 0){
				temp = temp / 10;
				
				num = num / 10;
			}
			if (temp % 2 != 0){
				++k;
			}
	    }
	}
	printf("Number of integers that start with an odd number: %d\n", k);
 return 0;
 }
