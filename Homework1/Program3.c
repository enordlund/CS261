/* CS261- HW1 - Program3.c*/
/* Name: Erik Nordlund
 * Date: April 6, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/     
     
     while (n > 1) {
     	int i;
     	for (i = 0; (i + 1) < n; ++i) {
     		int firstInt = number[i];
     		int secondInt = number[i+1];
     		if (firstInt > secondInt) {
     			number[i] = secondInt;
     			number[i+1] = firstInt;
     		}
     	}
     	
     	n = n - 1;
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int* numbers = NULL;
    numbers = (int*) malloc(n * sizeof(int));
    assert(numbers != NULL);
    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; ++i) {
    	int number = rand();
    	numbers[i] = number;
    }
    /*Print the contents of the array.*/
    for (i = 0; i < n; ++i) {
    	int number = numbers[i];
    	printf("%i\n", number);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(numbers, n);
    /*Print the contents of the array.*/    
    printf("Sorted:\n");
    for (i = 0; i < n; ++i) {
    	int number = numbers[i];
    	printf("%i\n", number);
    }
    
    free(numbers);
    
    return 0;
}
