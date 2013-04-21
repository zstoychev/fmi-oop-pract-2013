#include "Library.h"
#include <iostream>
using namespace std;

void printMenu() {
	cout << "1. Print library" << endl;
	cout << "2. Add book" << endl;
	cout << "3. Find book by ISBN" << endl;
	cout << "4. Find books by genre" << endl;
	cout << "5. Sort library" << endl;
	cout << "6. Find thinest and thickest books year difference" << endl;
	cout << "7. Exit" << endl;
	cout << "> ";
}

void executeCommand(Library& library, int choice) {
	switch (choice) {
		case 1:
			printLibraryInfo(&library);
			break;
		case 2:
			addBook(&library, readBook());
			break;
		case 3:
			{
				char isbn[ISBN_LENGTH + 1];
				cout << "Enter ISBN: ";
				cin.getline(isbn, ISBN_LENGTH + 1);
				printBookByISBN(library, isbn);
			}
			break;
		case 4:
			{
				cout << "Enter genre:" << endl;
				printBooksByGenre(&library, inputGenre());
			}
			break;
		case 5:
			sortLibrary(library);
			break;
		case 6:
			cout << "The difference is: " << getYearDifferenceBetweenTheThinestAndTheThickestBooks(library)
				<< " years" << endl;
			break;
	}
}

void interact(Library& library) {
	int choice;

	do {
		printMenu();
		cin >> choice;
		cin.ignore();
		executeCommand(library, choice);
	} while(choice != 7);
}

int main() {
	Library library = {"My Library", {}, 0};

	Book cppBook = {
		"9780321563842",
		"The C++ Programming Language (4th Edition)",
		"Bjarne Stroustrup",
		OTHER,
		1368,
		2013
	};
	Book cloudAtlas = {
		"9780812984415",
		"Cloud Atlas",
		"David Mitchell",
		FANTASY,
		544,
		2004
	};
	Book harryPotter = {
		"9780747543350",
		"Harry Potter and the Philosopher's Stone",
		"J. K. Rowling",
		FANTASY,
		223,
		1997
	};

	addBook(&library, cppBook);
	addBook(&library, cloudAtlas);
	addBook(&library, harryPotter);

	interact(library);

	return 0;
}
