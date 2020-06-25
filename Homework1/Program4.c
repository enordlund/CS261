/* CS261- HW1 - Program4.c*/
/* Name: Erik Nordlund
 * Date: April 6, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/     
     while (n > 1) {
     	int i;
     	for (i = 0; (i + 1) < n; ++i) {
     		char firstInitial1 = students[i].initials[0];
     		char firstInitial2 = students[i+1].initials[0];
     		if (firstInitial1 > firstInitial2) {
     			/* Swapping values */
     			char lastInitial1 = students[i].initials[1];
     			char lastInitial2 = students[i+1].initials[1];
     			
     			int score1 = students[i].score;
     			int score2 = students[i+1].score;
     			
     			students[i].initials[0] = firstInitial2;
     			students[i].initials[1] = lastInitial2;
     			students[i].score = score2;
     			
     			students[i+1].initials[0] = firstInitial1;
     			students[i+1].initials[1] = lastInitial1;
     			students[i+1].score = score1;
     		} else if (firstInitial1 == firstInitial2) {
     			char lastInitial1 = students[i].initials[1];
     			char lastInitial2 = students[i+1].initials[1];
     			
     			if (lastInitial1 > lastInitial2) {
     				/* Swapping values */
     				int score1 = students[i].score;
     				int score2 = students[i+1].score;
     				
     				students[i].initials[0] = firstInitial2;
     				students[i].initials[1] = lastInitial2;
     				students[i].score = score2;
     				
     				students[i+1].initials[0] = firstInitial1;
     				students[i+1].initials[1] = lastInitial2;
     				students[i+1].score = score1;
     			}
     		}
     	}
     	
     	n = n - 1;
     }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student* students;
    students = NULL;
    students = (struct student *) malloc(n * sizeof(struct student));
    assert(students != NULL);
    
    /*Generate random IDs and scores for the n students, using rand().*/
    int i;
    for (i = 0; i < n; ++i) {
    	char c1 = rand() % 26 + 'A';
    	char c2 = rand() % 26 + 'A';
    	int s = rand() % 101;
    	
	    students[i].initials[0] = c1;
	    students[i].initials[1] = c2;
	    students[i].score = s;
    }
    /*Print the contents of the array of n students.*/
    for (i = 0; i < n; ++i) {
    	char i0 = students[i].initials[0];
    	char i1 = students[i].initials[1];
    	int s = students[i].score;
    	printf("%i. %c%c %i\n", i, i0, i1, s);
	}
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    /*Print the contents of the array of n students.*/
    printf("Sorted:\n");
    
    for (i = 0; i < n; ++i) {
    	char i0 = students[i].initials[0];
    	char i1 = students[i].initials[1];
    	int s = students[i].score;
    	printf("%i. %c%c %i\n", i, i0, i1, s);
	}
	
	free(students);
	
    return 0;
}
