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

/* Declarations for point struct related functions */
struct point MakePoint(int x, int y);
struct point AddPoint(struct point p1, struct point p2);

#endif /* __POINT_H */