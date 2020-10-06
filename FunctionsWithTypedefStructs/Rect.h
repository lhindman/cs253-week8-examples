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
	Point p1;
	Point p2;
};
/* Definition of Rect type */
typedef struct rect Rect;

/* PointInRect: return 1 if p in r, 0 if not */
int PointInRect(Point p, Rect r);

/* canonrect: canonicalize coordinates of rectangle */
Rect CanonRect(Rect r);

#endif /* __RECT_H */