/*
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 09:01:40 AM PDT
 * Description: Adapted from the struct example from K&R chapter 6
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Point.h"
#include "Rect.h"

int main(void) {

    printf("Fun With Structs!\n");

	/* Create a point and store some data in it. */
	struct point a = {0,0},b = {15,20};
	printf("Point A: x = %d, y = %d\n",a.x,a.y);
	printf("Point B: x = %d, y = %d\n",b.x,b.y);

	/* Create a rect and store points a,b within it */
	struct rect r = {a,b};

	double area = abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
	printf("Rectangle Area: %0.2f\n", area);

	/* Create a point using the makepoint function() */
	struct point c = MakePoint(3,7);
	struct point d = MakePoint(7,15);

	/* Use the addpoint function to create a new point */
	struct point e = AddPoint(c,d);

	/* Use the CanonRect function to place p1 in the upper
	 * left corner of the rectangle using standard GUI frame with
	 * origin 0,0 in the upper left corner of the screen. p2 is
	 * placed in the lower right corner.
	 */
	r = CanonRect(r);

	/* Use PointInRect to determine if a point lies within the rect r */
	if (PointInRect(c,r) ) {
		printf("Point C: x = %d, y = %d\tinside\n",c.x,c.y);
	} else {
		printf("Point C: x = %d, y = %d\toutside\n",c.x,c.y);
	}

	if (PointInRect(d,r) ) {
		printf("Point D: x = %d, y = %d\tinside\n",d.x,d.y);
	} else {
		printf("Point D: x = %d, y = %d\toutside\n",d.x,d.y);
	}

	if (PointInRect(e,r) ) {
		printf("Point E: x = %d, y = %d\tinside\n",e.x,e.y);
	} else {
		printf("Point E: x = %d, y = %d\toutside\n",e.x,e.y);
	}

	/* Experiment with points to structs */
	struct point origin = {0,0};
	struct point *p;
	p = &origin;
	printf("Point Origin: x = %d, y = %d\n",p->x,p->y);

   return 0;
}
