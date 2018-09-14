/* -------------------------------------------
Name: Callum Dodge
Student number: 100229178
Email: cdodge1@myseneca.ca
Section: IPC144SOO
Date: March 31, 2018
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int min, int max);

// yes:
int yes(void);

// menu:
int menu(void);

// ContactManagerSystem:
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char[]);

// findContactIndex:
int findContactIndex(const struct Contact[], int, const char[]);


// displayContactHeader
void displayContactHeader(void);


// displayContactFooter
void displayContactFooter(int display);


// displayContact:
void displayContact(const struct Contact *contact);


// displayContacts:
void displayContacts(const struct Contact contact[], int display);


// searchContacts:
void searchContacts(const struct Contact contact[], int max);


// addContact:
void addContact(struct Contact contact[], int max);


// updateContact:
void updateContact(struct Contact contact[], int max);


// deleteContact:
void deleteContact(struct Contact contact[], int display);


// sortContacts:
void sortContacts(struct Contact contact[], int display);