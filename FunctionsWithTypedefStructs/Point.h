/*
 * File: Point.h
 * Author: Luke Hindman
 * Date: Jan 15, 2019
 * Description: Adapted from the struct example from K&R chapter 6
 */
#ifndef __POINT_H
#define __POINT_H

/* Definition of point struct */
struct point {
	int x;
	int y;
};
/* Definition of Point type */
typedef struct point Point;


/* Declarations for point struct related functions */
Point MakePoint(int x, int y);
Point AddPoint(Point p1, Point p2);

#endif /* __POINT_H */