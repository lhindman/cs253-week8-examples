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

	Book a = {"Eye Of The World", "Robert Jordan", 782};
	AddLibraryBook(&mylib,&a);

	Book b = {"Great Hunt", "Robert Jordan", 706};
	AddLibraryBook(&mylib,&b);

	Book c = {"Dragon Reborn", "Robert Jordan", 624};
	AddLibraryBook(&mylib,&c);

	Book d = {"Shadow Rising", "Robert Jordan", 1007};
	AddLibraryBook(&mylib,&d);

	Book * lightReadingPtr = CheckoutLibraryBook(&mylib,2);

	DisplayLibraryBooks(&mylib);

	ReturnLibraryBook(&mylib,lightReadingPtr);
	
	DisplayLibraryBooks(&mylib);

	RemoveLibraryBook(&mylib,0);

	DisplayLibraryBooks(&mylib);

}