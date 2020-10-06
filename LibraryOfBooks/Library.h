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

#include <stdbool.h>
#include "Book.h"

#define MAX_LIBRARY_FIELD_SIZE 60
#define MAX_LIBRARY_BOOKS 8

/* define library struct */
struct library {
    char name[MAX_LIBRARY_FIELD_SIZE];  /* The name of this library :) */
    Book books[MAX_LIBRARY_BOOKS];      /* Array of book structs */
    bool isAvail[MAX_LIBRARY_BOOKS];    /* Availability status of cooresponding book by index */
    int numBooks;                       /* Number of books currently stored in library */
    
};

/* define Library type */
typedef struct library Library;

/* 
 * InitLibrary: Initialize the specified library struct
 *      to set all the fields to good values.
 * libraryPtr: Pointer to library struct to be initialized
 * name: Null terminated string 
 * 
 * return: 0 on success, -1 on error  
 */
int InitLibrary(Library * libraryPtr, const char name[]);

/* 
 * AddLibraryBook: Make of copy of the Book struct referenced
 *    by bookPtr and store it in the Library struct referenced by
 *    libraryPtr.
 * libraryPtr: Pointer to library struct to be initialized
 * bookPtr: Pointer to book struct to be copied into library
 * 
 * return: 0 on success, -1 on error  
 */
int AddLibraryBook(Library * libraryPtr, Book * bookPtr);

/* 
 * RemoveLibraryBook: Remove the book at the specified index
 *     from the library.  This will require shifting all of
 *     the subsequent books down by one to fill the gap.
 * libraryPtr: Pointer to library struct 
 * bookIndex: Index of book to be removed.
 * 
 * return: 0 on success, -1 on error  
 */
int RemoveLibraryBook(Library * libraryPtr, int bookIndex);

/* 
 * CheckoutLibraryBook:  Determine if the book at the specified
 *     index is available and if so, mark it as unavailable and
 *     teturn a pointer to the book struct
 *     at the specified index. Return NULL if unavailable or error 
 * libraryPtr: Pointer to library struct 
 * bookIndex: Index of book to be checked out
 * 
 * return: Book pointer or NULL if unavailable/error  
 */
Book * CheckoutLibraryBook(Library * libraryPtr, int bookIndex);

/* 
 * ReturnLibraryBook: Lookup the Book specified by bookPtr
 *      and set its status to available.
 * libraryPtr: Pointer to library struct 
 * bookPtr: Pointer to book struct to be returned
 * 
 * return: 0 on success, -1 on error  
 */
int ReturnLibraryBook(Library * libraryPtr, Book * bookPtr);

/* 
 * DisplayLibraryBooks: Print the list of library books
 *       along with their availability status to stdout.
 * libraryPtr: Pointer to library struct 
 * 
 * return: 0 on success, -1 on error  
 */
int DisplayLibraryBooks(Library * libraryPtr);

#endif /* __LIBRARY_H */