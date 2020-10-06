/*
 * File: Library.c
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 10:59:16 AM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of structs
 *    in C. 
 */

#include <string.h>
#include "Library.h"


int InitLibrary(Library * libraryPtr, const char name[]) {
    /* basic parameter validation */
    if (libraryPtr == NULL || name == NULL) {
        return -1;
    }

    /* check the man page for strncpy to see what will happen
     *    if author is larger than MAX_LIBRARY_FIELD_SIZE-1 */
    strncpy(libraryPtr->name, name, MAX_LIBRARY_FIELD_SIZE-1);

    /* handle the situation where bookPtr->author is not
     *   null terminated after strncpy. This has no effect
     *   on when total copied is less than MAX_BOOK_FIELD_SIZE. */
    libraryPtr->name[MAX_LIBRARY_FIELD_SIZE-1] = '\0';

    libraryPtr->numBooks = 0;

    return 0;
}

int AddLibraryBook(Library * libraryPtr, Book * bookPtr) {
    /* basic parameter validation */
    if (libraryPtr == NULL || bookPtr == NULL) {
        return -1;
    }

    /* Check if the library is full */
    if (libraryPtr->numBooks >= MAX_LIBRARY_BOOKS) {
        return -1;
    }

    /* Add the book */
    int index = libraryPtr->numBooks;
    memcpy(&libraryPtr->books[index], bookPtr, sizeof(Book));
    libraryPtr->isAvail[index] = true;
    libraryPtr->numBooks++;

    return 0;
}

int RemoveLibraryBook(Library * libraryPtr, int bookIndex) {
    /* basic parameter validation */
    if (libraryPtr == NULL) {
        return -1;
    }

    /* Check if the bookIndex is out of range */
    if (bookIndex < 0 || bookIndex >= libraryPtr->numBooks) {
        return -1;
    }

    /* Remove the book by shifting books positioned after the
     *    specified index down by one */
    for (int i = bookIndex + 1; i < libraryPtr->numBooks; i++) {
        memcpy(&libraryPtr->books[i-1], &libraryPtr->books[i], sizeof(Book));
        libraryPtr->isAvail[i-1] = libraryPtr->isAvail[i-1];
    }
    libraryPtr->numBooks--;

    return 0;

}

Book * CheckoutLibraryBook(Library * libraryPtr, int bookIndex) {
    /* basic parameter validation */
    if (libraryPtr == NULL) {
        return NULL;
    }

    /* Check if the bookIndex is out of range */
    if (bookIndex < 0 || bookIndex >= libraryPtr->numBooks) {
        return NULL;
    }

    /* Check if book is available */
    if (libraryPtr->isAvail[bookIndex] == false) {
        return NULL;
    }

    /* Checkout the book */
    libraryPtr->isAvail[bookIndex] = false;
    return &libraryPtr->books[bookIndex];
}

int ReturnLibraryBook(Library * libraryPtr, Book * bookPtr) {
    /* basic parameter validation */
    if (libraryPtr == NULL || bookPtr == NULL) {
        return -1;
    }

    /* find the index of the book specified by bookPtr within the library */
    int index = -1;
    for (int i = 0; i < libraryPtr->numBooks; i++) {
        if (&libraryPtr->books[i] == bookPtr) {
            index = i; 
            break;
        }
    }

    /* Check if book was found */
    if (index < 0) {
        return -1;
    }

    /* Return the book */
    libraryPtr->isAvail[index] = true;

    return 0;
}

int DisplayLibraryBooks(Library * libraryPtr) {
    /* basic parameter validation */
    if (libraryPtr == NULL) {
        return -1;
    }
    int rc;
    const int BOOK_BUFFER_SIZE = 100;
    char bookBuffer[BOOK_BUFFER_SIZE];

    printf("**************************************\n");
    printf("%s\n",libraryPtr->name);
    printf("**************************************\n");
    for(int i = 0; i < libraryPtr->numBooks; i++) {
        rc = BookToString(&libraryPtr->books[i], bookBuffer, BOOK_BUFFER_SIZE);
        if (rc < 0) {
            printf("Error reading book at index: %d\n", i);
        } else {
            printf("%s\n",bookBuffer);
        }
    }
}