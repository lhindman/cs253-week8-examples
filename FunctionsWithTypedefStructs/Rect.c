/*
 * File: Rect.c
 * Author: Luke Hindman
 * Date: Jan 15, 2019
 * Description: Adapted from the struct example from K&R chapter 6
 */
#include "Rect.h"
#include "Point.h"

/* Define pre-processor macros to calculate min and max */
#define min(a, b) ((a) < (b) ? (a):(b))
#define max(a, b) ((a) > (b) ? (a):(b))

int PointInRect(Point p, Rect r) {
	return p.x >= r.p1.x && p.x < r.p2.x
			&& p.y >= r.p1.y && p.y < r.p2.y;
}

Rect CanonRect(Rect r) {
	Rect tmp;

	tmp.p1.x = min(r.p1.x, r.p2.x);
	tmp.p1.y = min(r.p1.y, r.p2.y);
	tmp.p2.x = max(r.p1.x, r.p2.x);
	tmp.p2.y = max(r.p1.y, r.p2.y);

	return tmp;
}