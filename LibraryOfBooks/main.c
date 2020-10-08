/*
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 03:41:05 PM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of struct in C. 
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include "Library.h"
#include "Book.h"

/* Declare our library as a global variable so that
 *    it is allocated in the Data Segment */
Library mylib;

/* Declare "private" helper functions */
void BufferPurge(void);
void DisplayMenu(void);
void UserPressAnyKey(void);
void UserAddBook(void); 
void UserRemoveBook(void);
Book * UserCheckoutBook(void);
Book * UserReturnBook(Book * myBookPtr);

int main(void) {

	/* Variables */
	bool running = true;
	char selection;
	Book * lightReadingPtr = NULL;

	/* Initialize the Library object*/
	InitLibrary(&mylib,"Hindman Public Library");

	/* Prepopulate the Library with books */
	Book a = {"Eye Of The World", "Robert Jordan", 782};
	AddLibraryBook(&mylib,&a);

	Book b = {"Great Hunt", "Robert Jordan", 706};
	AddLibraryBook(&mylib,&b);

	Book c = {"Dragon Reborn", "Robert Jordan", 624};
	AddLibraryBook(&mylib,&c);

	Book d = {"Shadow Rising", "Robert Jordan", 1007};
	AddLibraryBook(&mylib,&d);

	while (running) {
		DisplayMenu();

		/* Prompt the user to select an option */
		printf("Menu Selection: ");
		scanf("%c", &selection);
		selection = tolower(selection);
		BufferPurge();

		switch(selection) {
			case 'a':
				UserAddBook();
				UserPressAnyKey();
				break;
			case 'd':
				UserRemoveBook();
				UserPressAnyKey();
				break;
			case 'c':
				if (lightReadingPtr != NULL) {
					printf("Please return %s by %s before checking out another book\n", 
									lightReadingPtr->title, lightReadingPtr->author);
				} else {
					lightReadingPtr = UserCheckoutBook();
				}
				UserPressAnyKey();
				break;
			case 'r':
				if (lightReadingPtr == NULL) {
					printf("No book has been checked out\n");
				} else {
					lightReadingPtr = UserReturnBook(lightReadingPtr);
				}
				UserPressAnyKey();
				break;
			case 'l':
				DisplayLibraryBooks(&mylib);
				UserPressAnyKey();
				break;	
			case 'q':
				running = false;
				break;
			default:
				printf("Error: unknown option selected\n");
				printf("Please choose an option from the menu\n");
				UserPressAnyKey();
		}
	}

	/* Cleanup unused resources */

	exit(0);
}

void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

void DisplayMenu(void) {
	printf("-------------------\n");
	printf("|   Library Menu  |\n");
	printf("-------------------\n");
	printf("(A)dd a book (official use only)\n");
	printf("(D)elete a book (official use only)\n");
	printf("(C)heckout a book\n");
	printf("(R)eturn a book\n");
	printf("(L)ist books\n");
	printf("(Q)uit\n");
}

void UserAddBook(void) {
	/* Create a temporary book objects to store
	 *   the new book details */
	Book newBook;
	printf("Please enter the title:\n");
	scanf("%59[^\n]", newBook.title);
	BufferPurge();

	printf("Please enter the author:\n");
	scanf("%59[^\n]", newBook.author);
	BufferPurge();

	printf("Please enter the number of pages:\n");
	while (scanf("%d", &newBook.pages) < 1) {
		printf("Please enter an integer value");
		BufferPurge();
	}
	BufferPurge();

	/* Add book to library.  This works because the newBook object
	 *   is copied into the Library. Validate the return code to
	 *   ensure the book is added successfully. */
	if (AddLibraryBook(&mylib,&newBook) < 0) {
		printf("Error occurred while adding book to library\n");
	} else {
		printf("Book added successfully!\n");
	}
}

void UserRemoveBook(void) {
	int index;

	/* Prompt for index of book to remove and validate an integer
	 *    value has been specified */
	printf("Please enter the index number of the book to be removed:\n");
	while (scanf("%d", &index) < 1) {
		printf("Please enter an integer value");
		BufferPurge();
	}
	BufferPurge();

	/* Remove book and validate the return code to ensure the book 
	 *    is removes successfully */
	if (RemoveLibraryBook(&mylib,index) < 0) {
		printf("Error occurred while removing book from library\n");
	} else {
		printf("Book removed successfully!\n");
	}
}

Book * UserCheckoutBook(void) {
	int index;
	Book * myBookPtr = NULL;

	/* Prompt for index of book to checkout and validate an integer
	 *    value has been specified */
	printf("Please enter the index number of the book to be checked out:\n");
	while (scanf("%d", &index) < 1) {
		printf("Please enter an integer value");
		BufferPurge();
	}
	BufferPurge();

	/* Checkout book and validate the return code to ensure the book 
	 *    checkout completes successfully */
	if ( (myBookPtr = CheckoutLibraryBook(&mylib,index)) == NULL) {
		printf("Error occurred while checking out book from library\n");
	} else {
		printf("Successfully checked out %s\n", myBookPtr->title);
	}

	return myBookPtr;
}

Book * UserReturnBook(Book * myBookPtr ) {
	
	/* Checkout book and validate the return code to ensure the book 
	 *    checkout completes successfully */
	if (ReturnLibraryBook(&mylib, myBookPtr) < 0) {
		printf("Error occurred while returning book to library\n");
		return myBookPtr;
	} else {
		printf("Successfully returned %s\n", myBookPtr->title);
		return NULL;
	}
}

/* This gem is something I've kept around for more than 15 years
 *    as it allows me to replicate the functionality of
 *    the "Press any key to continue" pause function in DOS.
 * 
 *    This is specific to Linux / Unix type systems, and I while
 *    I am not the original author you are welcome to use it 
 *    in your own code */
void UserPressAnyKey(void) {
	struct termios oldt, newt;

	printf("Press any key to continue...\n");

	/* Store the terminal attributes for STDIN */
	tcgetattr ( STDIN_FILENO, &oldt );
	newt = oldt;
	/* Modify the STDIN attributes to disable line buffering */
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
	/* Retrieve a single keystoke from the keyboard without 
	 *    waiting for enter, but throw away the value. */
	getchar();
	/* Restore original terminal attributes for STDIN */
	tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );

}