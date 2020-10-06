/*
 * File: Point.c
 * Author: Luke Hindman
 * Date: Jan 15, 2019
 * Description: Adapted from the struct example from K&R chapter 6
 */

#include "Point.h"

/* makepoint: make a point from x and y components */
Point MakePoint(int x, int y) {
	Point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpoint: add two points */
Point AddPoint(Point p1, Point p2) {
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}