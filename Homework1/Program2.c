/* CS261- HW1 - Program2.c*/
/* Name: Erik Nordlund
 * Date: April 6, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <assert.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students;
     students = NULL;
     students = (struct student *) malloc(10 * sizeof(struct student));
     assert(students != NULL);
     
     /*return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
    
    int i;
    for (i = 0; i < 10; ++i) {
    	char c1 = rand() % 26 + 'A';
    	char c2 = rand() % 26 + 'A';
    	int s = rand() % 101;
    	
	    students[i].initials[0] = c1;
	    students[i].initials[1] = c2;
	    students[i].score = s;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
    int i;
    for (i = 0; i < 10; ++i) {
    	char i0 = students[i].initials[0];
    	char i1 = students[i].initials[1];
    	int s = students[i].score;
    	printf("%i. %c%c %i\n", i, i0, i1, s);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int minimum = 100;
     int maximum = 0;
     double average;
     
     int sum = 0;
     
     int i;
     
     for (i = 0; i < 10; ++i) {
     	int s = students[i].score;
	    if (s < minimum) {
	    	minimum = s;
	    }
	    if (s > maximum) {
	    	maximum = s;
	    }
	    
	    sum = sum + s;
	 }
	 
	 average = (double)sum / 10.0;
	 
	 printf("Minimum score: %i\n", minimum);
	 printf("Maximum score: %i\n", maximum);
	 printf("Average score: %f\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
