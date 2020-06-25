/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* Converts the input bag into a set using dynamic arrays 
	param: 	da -- pointer to a bag 	
	return value: void
        result: after exiting the function da points to a set 		
*/
void bag2set(struct DynArr *da)
{
    

     /* FIX ME */
     struct DynArr newArray;
     initDynArr(&newArray, sizeDynArr(da));
     int oldSize = sizeDynArr(da);
     int i;
     for (i = 0; i < oldSize; ++i) {
     	TYPE oldElement = getDynArr(da, i);
     	if (sizeDynArr(&newArray)) {
     		if (containsDynArr(&newArray, oldElement) == -1) {
     			addDynArr(&newArray, oldElement);
     		}
     	} else {
     		addDynArr(&newArray, oldElement);
     	}
     	
     }
     
     freeDynArr(da);
     *da = newArray;
}



/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr da;  /* bag */
        
        initDynArr(&da, 100);
        da.size = 10;
        da.data[0] = 1.3;
	for (i=1;i<da.size;i++){
	    da.data[i] = 1.2;
	 }

        printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
          printf("%g  \n", da.data[i]);
        }
        
        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
	for (i=0;i<da.size;i++){
          printf("%g ", da.data[i]);
          printf("\n");
        }
        printf("\n");
        
    freeDynArr(&da);
	return 0;	
}

