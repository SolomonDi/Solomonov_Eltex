#ifndef PHONEBOOK
#define PHONEBOOK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LEN 256
#define PHONE_FILE contacts_book.txt

typedef struct {

    char **data;
    size_t count;
    size_t capacity;

} String;


typedef struct Contact {

    char *fullName;
    String phoneNumber;
    String email;
    struct Contact *left;
    struct Contact *right; 

}Contacts;

typedef struct {

    Contact *root;
    size_t size;

}PhoneBook;




















#endif