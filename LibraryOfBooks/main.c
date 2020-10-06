/*
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 03:41:05 PM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of struct in C. 
 */

#include <stdio.h>
#include "Library.h"
#include "Book.h"

/* Declare our library as a global variable so that
 *    it is allocated in the Data Segment */
Library mylib;

int main(void) {

	InitLibrary(&mylib,"Hindman Public Library");
	
}