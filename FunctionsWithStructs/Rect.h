/*
 * File: Rect.h
 * Author: Luke Hindman
 * Date: Jan 15, 2019
 * Description: Adapted from the struct example from K&R chapter 6
 */
#ifndef __RECT_H
#define __RECT_H

#include "Point.h"

/* Definition of rect struct */
struct rect {
	struct point p1;
	struct point p2;
};

/* PointInRect: return 1 if p in r, 0 if not */
int PointInRect(struct point p, struct rect r);

/* canonrect: canonicalize coordinates of rectangle */
struct rect CanonRect(struct rect r);

#endif /* __RECT_H */