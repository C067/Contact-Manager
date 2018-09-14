/* -------------------------------------------
Name: Callum Dodge           
Student number: 100229178
Email: cdodge1@myseneca.ca         
Section: IPC144SOO       
Date: March 31, 2018          
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

void clearKeyboard(void)
{
	while (getchar() != '\n');	//Clear the buffer when the enter key is entered.
}

// pause:
void pause(void) {

	//Ask the user to press the 'Enter' key to continue.
	printf("(Press Enter to Continue)");
	//Call the clearKeyboard Function
	clearKeyboard();

}

// getInt:
int getInt(void) {

	int value;
	char NL = 'x';

	do {
		//Scan for a newline character and an integer.
		scanf("%d%c", &value, &NL);

		//Checks to see if a valid integer has been entered.
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

	} while (NL != '\n');

	return value;
}

// getIntInRange:
int getIntInRange(int min, int max) {

	int value;

	//Get value entered from getInt().
	value = getInt();

	//Loops until a value is in range of the min and max values.
	while (value < min || value > max) {

		if (value < min || value > max) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			value = getInt();
		}

	}

	return value;
}

// yes:
int yes(void) {

	char NL = ' ', option = ' ';
	int result = 0;

	//Scan for an option and check to see if the enter key was entered.
	scanf("%c%c", &option, &NL);

	//Loop until 'Y' or 'y' or 'N' or 'n' and a new line is entered.
	while ((option != 'Y' && option != 'y' && option != 'N' && option != 'n') || NL != '\n') {
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &option, &NL);
	}

	//result = 1 if option ='Y' or 'y'
	if (option == 'Y' || option == 'y') {
		result = 1;
	}

	//result = 0 if option ='N' or 'n'
	else if (option == 'N' || option == 'n') {
		result = 0;
	}

	//Return the result
	return result;

}

// menu:
int menu(void) {

	int option = 0;
	int max = 6;
	int result;

	//Display Contact Management menu
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");

	printf("Select an option:> ");

	//Check to see if the values are in range.
	result = getIntInRange(option, max);

	return result;

}

// ContactManagerSystem:
void ContactManagerSystem(void) {
	int option = 0, exit = 0, result;

	//Declare the Contact struct and assign it to an array with preset values.
	struct Contact contact[MAXCONTACTS] = { { { "Rick", {'\0'} , "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
{
	{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
{
	{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
{
	{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
{
	{" ", " ", " "}, {0, " ", 0, " ", " "}, {" ", " ", " "} }
};
	

	//Loop till exit = 1
	while (exit != 1) {

		//Get an option entered by the menu function
		option = menu();

		printf("\n");

		//Print options related to the Contact menu
		switch (option) {
		case 1:
			//display all contacts
			displayContacts(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 2:
			//add a contact
			addContact(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 3:
			//update a contact
			updateContact(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 4:
			//delete a contact
			deleteContact(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 5:
			//search for a contact
			searchContacts(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 6:
			//sort all contacts by cell phone number
			sortContacts(contact, MAXCONTACTS);

			pause();
			printf("\n");
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			result = yes();

			if (result == 1) {
				exit = 1;
				printf("\n");
				printf("Contact Management System: terminated\n");
			}
			else if (result == 0) {
				exit = 0;
				printf("\n");
			}

			break;
		}
	}
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[]) {

	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {

	int cnt, value = -1;

	for (cnt = 0; cnt < size; cnt++) {
		//Compare to see if both numbers match
		if (strcmp(contacts[cnt].numbers.cell, cellNum) == 0) {
			//if matches assign and return the current position
			value = cnt;
			break;
		}
	}

	return value;
}


// displayContactHeader
void displayContactHeader(void) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
void displayContactFooter(int display) {

	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", display);

}


// displayContact:
void displayContact(const struct Contact *contact) {

	//Compare to see if a middleInitial has been entered
	if (strcmp(contact->name.middleInitial,"") == 0) {
		//display first and last name
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else {
		//display first, middle and last name
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	//display numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	
	//Compare to see if an Apartment Number has been entered
	if (contact->address.apartmentNumber > 0) {
		//Display all Address Info
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else {
		//Display all Address Info except for an Appartment Number
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}

}


// displayContacts:
void displayContacts(const struct Contact contact[], int max) {

	int display;
	int footer = 0, len;

	displayContactHeader();

	for (display = 0; display < max; display++) {
		
		//Get the length of the cell phone string
		len = strlen(contact[display].numbers.cell);

		//Compare to see if a cell string exists by checking its length
		if (len > 1 && len < 11) {
			//display Contacts
			displayContact(&contact[display]);
			footer = footer + 1;
		}
	
	}

	displayContactFooter(footer);
}


// searchContacts:
void searchContacts(const struct Contact contact[], int max) {

	int value;
	char cellNum[11];

	//Ask user to enter a cell number and check to see if it meets getTenDigitPhone's function requirements
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	//Find the current position
	value = findContactIndex(contact, max, cellNum);

	//If found display contact
	if (value > -1) {
		printf("\n");
		displayContact(contact[value]);
		printf("\n");
	}

	//Error
	else {
		printf("--- Contact NOT FOUND ---\n");
	}
}


// addContact:
void addContact(struct Contact contact[], int max) {

	int cnt, full = 0, len, found = 0;

	for (cnt = 0; cnt < max; cnt++) {

		//Compare length of string
		len = strlen(contact[cnt].numbers.cell);
		
		//If string equals 1 or 0 add a new contact.
		if (len == 1 || len == 0) {
			getContact(&contact[cnt]);
			found = 1;
		}

		//If string is full prompt error
		else if (len > 2 && len < 11) {
			full = 1;
		}

	}

	if (found == 1) {
		printf("--- New contact added! ---\n");
	}

	else if (full == 1) {
		printf("*** ERROR: The contact list is full! ***\n");
	}

		
}
	



// updateContact:
void updateContact(struct Contact contact[], int max) {

	int result, value;
	char cellNum[11];

	//Ask user to enter a cell number and check to see if it meets getTenDigitPhone's function requirements
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	//Find current position
	value = findContactIndex(contact, max, cellNum);

	//If the contact is found ask the user to update each section.
	if (value > -1) {
		printf("\nContact found:\n");

		displayContact(&contact[value]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		result = yes();
		if (result == 1) {
			getName(&contact[value].name);
			clearKeyboard();
		}

		printf("Do you want to update the address? (y or n): ");
		result = yes();
		if (result == 1) {
			getAddress(&contact[value].address);
			clearKeyboard();
		}

		printf("Do you want to update the numbers? (y or n): ");
		result = yes();
		if (result == 1) {
			getNumbers(&contact[value].numbers);
		}

		printf("--- Contact Updated! ---\n");

	}
	
	//Error
	else {
		printf("*** Contact NOT FOUND ***\n");
	}

}


// deleteContact:
void deleteContact(struct Contact contact[], int max) {

	int value, result;
	char cellNum[11];

	//Ask user to enter a cell number and check to see if it meets getTenDigitPhone's function requirements
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	//Find current position
	value = findContactIndex(contact, max, cellNum);

	//If contact is found display and ask the user to delete the contact
	if (value > -1) {
		printf("\nContact found:\n");
		displayContact(&contact[value]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		result = yes();

		if (result == 1) {
			printf("--- Contact deleted! ---\n");
			contact[value].numbers.cell[0] = '\0';
		}

	}
	
	//error
	else {
		printf("*** Contact NOT FOUND ***\n");
	}
}


// sortContacts:
void sortContacts(struct Contact contact[], int max) {

	int disCnt = 0, cnt, i;
	struct Contact number;

	//Loop to find the number of existing contacts
	for (cnt = 0; cnt < max; cnt++) {
		if (strlen(contact[cnt].numbers.cell)>0) {
			disCnt = disCnt + 1;
		}
	}

	//Loop until the number of existing contacts are reached.
	//Loop and compare each individual cell number and sort them by lowest to greatest.
	for (cnt = 0; cnt < disCnt -1; cnt++) {

		for (i = cnt; i < disCnt; i++) {

			if (strcmp(contact[cnt].numbers.cell,contact[i].numbers.cell) > 0) {
				number = contact[cnt];
				contact[cnt] = contact[i];
				contact[i] = number;
			}

		}

	}

	printf("--- Contacts sorted! ---\n");
}
