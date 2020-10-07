/*
 * File: Book.h
 * Author: Luke Hindman
 * Date: Tue 06 Oct 2020 10:59:16 AM PDT
 * Description: Partial implementation of the LibraryOfBooks
 *    project from CS121 to demonstrate the use of structs
 *    in C. 
 */
#ifndef __BOOK_H
#define __BOOK_H
#include <stdio.h>

#define MAX_BOOK_FIELD_SIZE 60

/* Define book struct */
struct book {
    char title[MAX_BOOK_FIELD_SIZE];
    char author[MAX_BOOK_FIELD_SIZE];
    unsigned int pages;
};

/* Define Book type */
typedef struct book Book;

/* 
 * SetBookAuthor: Update the author field of specified 
 *      Book struct to the specified value. If value
 *      exceeds MAX_BOOK_FIELD_SIZE, value will be 
 *      truncated to fit.
 * bookPtr: Pointer to book struct to be modified
 * author: Null terminated string 
 * 
 * return: number of characters copied, -1 on error  
 */
int SetBookAuthor(Book * bookPtr, const char author[]);

/* 
 * SetBookTitle: Update the title field of specified 
 *      Book struct to the specified value. If value
 *      exceeds MAX_BOOK_FIELD_SIZE, value will be 
 *      truncated to fit.
 * bookPtr: Pointer to book struct to be modified
 * title: Null terminated string 
 * 
 * return: number of characters copied, -1 on error  
 */
int SetBookTitle(Book * bookPtr, const char title[]);

/* 
 * SetBookPages: Update the pages field of specified 
 *        Book struct to the specified value.
 * bookPtr: Pointer to book struct to be modified
 * title: Null terminated string 
 * 
 * return: 0 on success, -1 on error  
 */
int SetBookPages(Book * bookPtr, unsigned int pages);

/* 
 * BookToString: Generate a null terminated string
 *     representation of the specified Book struct
 *     and store it in the provided char buffer.
 * bookPtr: Pointer to book struct 
 * buffer: Reference (aka pointer) to char buffer of sufficient
 *     size to store string representation of Book
 * bufferSize: The size of the buffer in bytes
 * 
 * return: number of characters copied, -1 on error 
 */
int BookToString(Book * bookPtr, char buffer[], size_t bufferSize);



#endif /* __BOOK_H */