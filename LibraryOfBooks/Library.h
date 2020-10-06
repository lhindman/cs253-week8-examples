/*
 * File: Library.h
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 10:59:16 AM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of structs
 *    in C. 
 */
#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "Book.h"

const int MAX_LIBRARY_FIELD_SIZE = 60;
const int MAX_LIBRARY_BOOKS = 8;

/* define library struct */
struct library {
    char name[MAX_LIBRARY_FIELD_SIZE];  /* The name of this library :) */
    Book books[MAX_LIBRARY_BOOKS];     /* Array of book structs */
    bool isAvail[MAX_LIBRARY_BOOKS];   /* Availability status of cooresponding book by index */
    int numBooks = 0; /* Number of books currently stored in library */
};

/* define Library type */
typedef struct library Library;


int SetLibraryName(Library * libraryPtr, const char name[]);
int AddLibraryBook(Library * libraryPtr, Book * bookPtr);
int RemoveLibraryBook(Library * libraryPtr, int bookIndex);
Book * CheckoutLibraryBook(Library * libraryPtr, int bookIndex);
int ReturnLibraryBook(Library * libraryPtr, Book * bookPtr);
void DisplayLibraryBooks(Library * libraryPtr);

#endif /* __LIBRARY_H */