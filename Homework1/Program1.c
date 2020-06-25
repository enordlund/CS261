/* CS261- HW1 - Program1.c*/
/* Name: Erik Nordlund
 * Date: April 4, 2018
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    (*a)++;
    /* Decrement  b */
    (*b)--;
    /* Assign a-b to c */
    c = (*a)-(*b);
    /* Return c */
    return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x, y, z;
    x = rand() % 11;
    y = rand() % 11;
    z = rand() % 11;
    /* Print the values of x, y and z */
    printf("x = %i, y = %i, z = %i\n", x, y, z);
    /* Call foo() appropriately, passing x,y,z as parameters */
    int fooResult = foo(&x, &y, z);
    /* Print the values of x, y and z */
    printf("x = %i, y = %i, z = %i\n", x, y, z);
    /* Print the value returned by foo */
    printf("foo() = %i\n", fooResult);
    /* Is the return value different than the value of z?  Why? */
    if (z == fooResult) {
    	printf("z = foo()\n(z = x - y)\n");
    } else {
    	printf("z != foo()\n(z != x - y)\n");
    }
    return 0;
}
    
    
