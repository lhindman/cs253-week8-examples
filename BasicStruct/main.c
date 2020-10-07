/*
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 09:01:40 AM PDT
 * Description: Adapted from the struct example from K&R chapter 6
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Definition of point struct */
struct point {
	int x;
	int y;
};

int main(void) {

    printf("Fun With Structs!\n");

	/* Create a point and store some data in it. */
	struct point a = {0,0},b = {15,20};
	printf("Point A: x = %d, y = %d\n",a.x,a.y);
	printf("Point B: x = %d, y = %d\n",b.x,b.y);

	/* Size of a struct */
	printf("The size of the point struct is: %ld bytes\n", sizeof (struct point));

	/* Experiment with pointers to structs */
	struct point origin = {0,0};
	struct point * originPtr = NULL;
	originPtr = &origin;
	printf("Point origin addr (stack): %p\n",originPtr);

	/* When have a pointer to a struct and we want to 
	 *    access its fields, we can use the generic dereference 
	 *    operator (*ptr) to get access to the struct itself and
	 *    then use the dot operator to access the individual fields. */
	printf("Point origin value: x = %d, y = %d\n", (*originPtr).x, (*originPtr).y);

	/* However, working with pointers to structs in C is such a 
	 *    common activity that the -> operator was added to 
	 *    combine both the dereference and the field access
	 *    into a single operation */
	printf("Point origin value: x = %d, y = %d\n", originPtr->x, originPtr->y);

   return 0;
}