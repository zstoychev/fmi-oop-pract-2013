#include "Library.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

void printGenre(Genre genre) {
	switch (genre) {
		case CRIMINAL:
			cout << "Criminal";
			break;
		case FAIRY_TALE:
			cout << "Fairy tale";
			break;
		case FANTASY:
			cout << "Fantasy";
			break;
		case GRAPHIC_NOVEL:
			cout << "Graphic novel";
			break;
		case ROMANCE:
			cout << "Romance";
			break;
		case SCIENCE_FICTION:
			cout << "Science fiction";
			break;
		case OTHER:
			cout << "Other";
			break;
		default:
			cout << "Unknown genre";
	}
}

Genre inputGenre() {
	for (int i = 0; i < NUMBER_OF_GENRES; i++) {
		cout << i + 1 << ". ";
		printGenre(genres[i]);
		cout << endl;
	}

	cout << "> ";
	int choice;
	cin >> choice;

	return genres[choice - 1];
}

void printBook(const Book& book) {
	cout << "ISBN: " << book.isbn << endl;
	cout << "Title: " << book.title << endl;
	cout << "Author: " << book.isbn << endl;

	cout << "Genre: ";
	printGenre(book.genre);
	cout << endl;

	cout << "Number of pages: " << book.numberOfPages << endl;
	cout << "Publish year: " << book.publishYear << endl;
}

Book readBook() {
	Book result;

	cout << "Enter isbn: ";
	cin.getline(result.isbn, ISBN_LENGTH + 1);

	cout << "Enter title: ";
	cin.getline(result.title, MAX_LENGTH);

	cout << "Enter author: ";
	cin.getline(result.author, MAX_LENGTH);

	cout << "Enter genre: " << endl;
	result.genre = inputGenre();

	cout << "Enter number of pages: ";
	cin >> result.numberOfPages;

	cout << "Enter publish year: ";
	cin >> result.publishYear;

	return result;
}

bool lessThan(const Book& book1, const Book& book2) {
	if (book1.genre == book2.genre) {
		return strcmp(book1.title, book2.title) < 0;
	} else {
		return book1.genre < book2.genre;
	}
}

bool addBook(Library* library, const Book& book) {
	if (library->numberOfBooks == LIBRARY_CAPACITY) {
		return false;
	}

	library->books[library->numberOfBooks++] = book;

	return true;
}

void printLibraryInfo(const Library* library) {
	cout << "Library name: " << library->name << endl;
	cout << "Available books: " << endl;

	for (int i = 0; i < library->numberOfBooks; i++) {
		printBook(library->books[i]);
		cout << endl;
	}
}

void printBookByISBN(const Library& library, const char* isbn) {
	for (int i = 0; i < library.numberOfBooks; i++) {
		if (strcmp(library.books[i].isbn, isbn) == 0) {
			printBook(library.books[i]);
			return;
		}
	}

	cout << "Couldn't find a book with ISBN " << isbn << endl;
}

void printBooksByGenre(const Library* library, const Genre genre) {
	for (int i = 0; i < library->numberOfBooks; i++) {
		if (library->books[i].genre == genre) {
			printBook(library->books[i]);
			cout << endl;
		}
	}
}

void sortLibrary(Library& library) {
	/*
	 * Creates a reference to the books array of the library, so that we can type
	 * books[i] instead of library.books[i]. The code here is just to illustrate how
	 * to use references to arrays (similar to pointers to arrays). It's perfectly fine
	 * to type library.books[i] instead.
	 *
	 * As a reminder, the syntax for pointer to array definition is:
	 * Book (*booksPtr)[LIBRARY_CAPACITY] = &library.books;
	 *
	 */
	Book (&books)[LIBRARY_CAPACITY] = library.books;

	for (int i = 0; i < library.numberOfBooks; i++) {
		int minBookIndex = i;

		for (int j = i + 1; j < library.numberOfBooks; j++) {
			if (lessThan(books[j], books[minBookIndex])) {
				minBookIndex = j;
			}
		}

		// swap is a utility function, located in <algorithm>
		swap(books[i], books[minBookIndex]);
	}
}

int getYearDifferenceBetweenTheThinestAndTheThickestBooks(const Library& library) {
	// Assumes there is at least one book in the library
	const Book* thinestBook = &library.books[0];
	const Book* thickestBook = &library.books[0];

	for (int i = 1; i < library.numberOfBooks; i++) {
		if (library.books[i].numberOfPages < thinestBook->numberOfPages) {
			thinestBook = &library.books[i];
		}
		if (library.books[i].numberOfPages > thickestBook->numberOfPages) {
			thickestBook = &library.books[i];
		}
	}

	return abs(thinestBook->publishYear - thickestBook->publishYear);
}
