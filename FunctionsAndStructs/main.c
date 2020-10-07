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

/* Declarations for point struct related functions */
struct point MakePoint(int x, int y);
struct point AddPoint(struct point p1, struct point p2);
void PrintPoint(struct point p);

int main(void) {

    printf("Fun With Structs!\n");

	/* Create a point and store some data in it. */
	struct point a = {0,0},b = {15,20};
	printf("Point A: x = %d, y = %d\n",a.x,a.y);
	printf("Point B: x = %d, y = %d\n",b.x,b.y);

	/* Create a point using the makepoint function() */
	struct point c = MakePoint(3,7);
	struct point d = MakePoint(7,15);
	printf("The value of point c: ");
	PrintPoint(c);

	printf("The value of point d: ");
	PrintPoint(d);

	/* Use the addpoint function to create a new point */
	struct point e = AddPoint(c,d);

	printf("The value of point e: ");
	PrintPoint(e);

	/* Experiment with points to structs */
	struct point origin = {0,0};
	struct point *p;
	p = &origin;
	printf("Point origin addr (stack): %p\n",p);
	printf("Point origin value: x = %d, y = %d\n",p->x,p->y);

   return 0;
}

/* makepoint: make a point from x and y components */
struct point MakePoint(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
struct point AddPoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* printpoint: display a point on stdout */
void PrintPoint(struct point p) {
	printf("(%d,%d)\n",p.x,p.y);
}