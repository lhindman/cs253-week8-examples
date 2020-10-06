/*
 * File: structfun.c
 * Author: platypus
 * Date: Jan 15, 2019
 * Description: Playing with a few of the
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct point {
	int x;
	int y;
};

struct rect {
	struct point p1;
	struct point p2;
};

struct point makepoint(int x, int y);
struct point addpoint(struct point p1, struct point p2);
int ptinrect(struct point p, struct rect r);
struct rect canonrect(struct rect r);

int main (void) {

	printf("Struct Fun\n");

	/* Create a point and store some data in it. */
	struct point a = {0,0},b = {15,20};
	printf("Point A: x = %d, y = %d\n",a.x,a.y);
	printf("Point B: x = %d, y = %d\n",b.x,b.y);

	/* Create a rect and store points a,b within it */
	struct rect r = {a,b};

	double area = abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
	printf("Rectangle Area: %0.2f\n", area);

	/* Create a point using the makepoint function() */
	struct point c = makepoint(3,7);
	struct point d = makepoint(7,15);

	/* Use the addpoint function to create a new point */
	struct point e = addpoint(c,d);

	/* Use the canonrect function to place p1 in the upper
	 * left corner of the rectangle using standard GUI frame with
	 * origin 0,0 in the upper left corner of the screen. p2 is
	 * placed in the lower right corner.
	 */
	r = canonrect(r);

	/* Use ptinrect to determine if a point lies within the rect r */
	if (ptinrect(c,r) ) {
		printf("Point C: x = %d, y = %d\tinside\n",c.x,c.y);
	} else {
		printf("Point C: x = %d, y = %d\toutside\n",c.x,c.y);
	}

	if (ptinrect(d,r) ) {
		printf("Point D: x = %d, y = %d\tinside\n",d.x,d.y);
	} else {
		printf("Point D: x = %d, y = %d\toutside\n",d.x,d.y);
	}

	if (ptinrect(e,r) ) {
		printf("Point E: x = %d, y = %d\tinside\n",e.x,e.y);
	} else {
		printf("Point E: x = %d, y = %d\toutside\n",e.x,e.y);
	}

	/* Experiment with points to structs */
	struct point origin = {0,0};
	struct point *p;
	p = &origin;
	printf("Point Origin: x = %d, y = %d\n",p->x,p->y);

}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y) {
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
struct point addpoint(struct point p1, struct point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r) {
	return p.x >= r.p1.x && p.x < r.p2.x
			&& p.y >= r.p1.y && p.y < r.p2.y;
}

#define min(a, b) ((a) < (b) ? (a):(b))
#define max(a, b) ((a) > (b) ? (a):(b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r) {
	struct rect tmp;

	tmp.p1.x = min(r.p1.x, r.p2.x);
	tmp.p1.y = min(r.p1.y, r.p2.y);
	tmp.p2.x = max(r.p1.x, r.p2.x);
	tmp.p2.y = max(r.p1.y, r.p2.y);

	return tmp;
}
