#ifndef LIBRARY_H_
#define LIBRARY_H_

const int MAX_LENGTH = 80;
const int ISBN_LENGTH = 13;
const int LIBRARY_CAPACITY = 50;

enum Genre {
	CRIMINAL,
	FAIRY_TALE,
	FANTASY,
	GRAPHIC_NOVEL,
	ROMANCE,
	SCIENCE_FICTION,
	OTHER
};

const Genre genres[] = {CRIMINAL, FAIRY_TALE, FANTASY, GRAPHIC_NOVEL, ROMANCE, SCIENCE_FICTION, OTHER};
const int NUMBER_OF_GENRES = sizeof(genres) / sizeof(Genre);

Genre inputGenre();

struct Book {
	char isbn[ISBN_LENGTH + 1];
	char title[MAX_LENGTH];
	char author[MAX_LENGTH];
	Genre genre;
	int numberOfPages;
	int publishYear;
};

void printBook(const Book& book);
Book readBook();

bool lessThan(const Book& book1, const Book& book2);

struct Library {
	char name[MAX_LENGTH];
	Book books[LIBRARY_CAPACITY];
	int numberOfBooks;
};

bool addBook(Library* library, const Book& book);

void printLibraryInfo(const Library* library);
void printBookByISBN(const Library& library, const char* isbn);
void printBooksByGenre(const Library* library, const Genre genre);

void sortLibrary(Library& library);

int getYearDifferenceBetweenTheThinestAndTheThickestBooks(const Library& library);

#endif
