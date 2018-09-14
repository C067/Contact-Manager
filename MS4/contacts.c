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

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *name) {

	//Contact's first name
	printf("Please enter the contact's first name: ");
	scanf("%[^\t\n]s", (*name).firstName);

	//Middle Initial
	int result;

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	clearKeyboard();
	result = yes();

	if (result == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\t\n]s", (*name).middleInitial);
	}

	//Contact's last name
	printf("Please enter the contact's last name: ");
	scanf(" %[^\t\n]s", (*name).lastName);
}

// getAddress:
void getAddress(struct Address *address) {
	int result;

	//Contact's street number
	printf("Please enter the contact's street number: ");
	(*address).streetNumber = getInt();

	//Contact's street name
	printf("Please enter the contact's street name: ");
	scanf(" %[^\t\n]s", (*address).street);

	//Apartment Number
	printf("Do you want to enter an apartment number? (y or n): ");
	clearKeyboard();
	result = yes();

	if (result == 1) {

		printf("Please enter the contact's apartment number: ");
		(*address).apartmentNumber = getInt();

	}

	else {
		address->apartmentNumber = 0;
	}

	//Contact's postal code
	printf("Please enter the contact's postal code: ");
	scanf("%[^\t\n]s", (*address).postalCode);

	//Contacts City
	printf("Please enter the contact's city: ");
	scanf(" %[^\t\n]s", (*address).city);
}

// getNumbers:
void getNumbers(struct Numbers *number) {
	int result;

	//Contacts Cell Number
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone((*number).cell);


	//Contacts home phone Number
	printf("Do you want to enter a home phone number? (y or n): ");
	result = yes();

	if (result == 1) {

		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone((*number).home);
	}

	else {
		number->home[0] = '\0';
	}

	//Contacts business Number
	printf("Do you want to enter a business phone number? (y or n): ");
	result = yes();

	if (result == 1) {

		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone((*number).business);

	}

	else {
		number->business[0] = '\0';
	}
}

// getContact:
void getContact(struct Contact contact[]) {

	getName(&contact->name);

	getAddress(&contact->address);

	getNumbers(&contact->numbers);
	

}
