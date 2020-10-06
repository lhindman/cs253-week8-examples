/*
 * File: Book.c
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 10:59:16 AM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of structs
 *    in C. 
 */
#include "Book.h"

int SetBookAuthor(Book * bookPtr, const char author[]) {
    /* basic parameter validation */
    if (bookPtr == NULL || author == NULL) {
        return -1;
    }

    /* check the man page for strncpy to see what will happen
     *    if author is larger than MAX_BOOK_FIELD_SIZE-1 */
    strncpy(bookPtr->author, author, MAX_BOOK_FIELD_SIZE-1);
    
    /* handle the situation where bookPtr->author is not
     *   null terminated after strncpy. This has no effect
     *   on when total copied is less than MAX_BOOK_FIELD_SIZE. */
    bookPtr->author[MAX_BOOK_FIELD_SIZE-1] = '\0';

    return strlen(bookPtr->author);
}

int SetBookTitle(Book * bookPtr, const char title[]) {
    /* basic parameter validation */
    if (bookPtr == NULL || title == NULL) {
        return -1;
    }

    /* check the man page for strncpy to see what will happen
     *    if author is larger than MAX_BOOK_FIELD_SIZE-1 */
    strncpy(bookPtr->title, title, MAX_BOOK_FIELD_SIZE-1);
    
    /* handle the situation where bookPtr->author is not
     *   null terminated after strncpy. This has no effect
     *   on when total copied is less than MAX_BOOK_FIELD_SIZE. */
    bookPtr->author[MAX_BOOK_FIELD_SIZE-1] = '\0';

    return strlen(bookPtr->title);
}

int SetBookPages(Book * bookPtr, unsigned int pages) {
    /* basic parameter validation */
    if (bookPtr == NULL) {
        return -1;
    }

    /* Dereference and update pages field in Book struct */
    bookPtr->pages = pages;

    return 0;
}

int BookToString(Book * bookPtr, char buffer[], size_t bufferSize) {
    /* basic parameter validation */
    if (bookPtr == NULL || buffer == NULL) {
        return -1;
    }

    /* Format the fields from Book and write them to the buffer using 
     *    snprintf.  Check the manpage for snprintf for more details 
     *    on how this function works and what it returns. */
    return snprintf(buffer,bufferSize,"%s by %s has %d pages", 
                bookPtr->title, bookPtr->author, bookPtr->pages);

}