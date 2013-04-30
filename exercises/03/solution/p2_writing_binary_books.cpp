#include <fstream>
#include <iostream>
#include "Library.h"
using namespace std;

Book books[] = {
	{
		"9780321563842",
		"The C++ Programming Language (4th Edition)",
		"Bjarne Stroustrup",
		OTHER,
		1368,
		2013
	},
	{
		"9780812984415",
		"Cloud Atlas",
		"David Mitchell",
		FANTASY,
		544,
		2004
	},
	{
		"9780747543350",
		"Harry Potter and the Philosopher's Stone",
		"J. K. Rowling",
		FANTASY,
		223,
		1997
	},
	{
		"9780321563843",
		"The C++ Programming Language (4th Edition)",
		"Bjarne Stroustrup",
		OTHER,
		3332,
		1922
	},
	{
		"9780812984413",
		"Cloud Atlas",
		"David Mitchell",
		FANTASY,
		123,
		1999
	},
	{
		"9780747543353",
		"Harry Potter and the Philosopher's Stone",
		"J. K. Rowling",
		CRIMINAL,
		444,
		2005
	},
	{
		"9780321563844",
		"The C++ Programming Language (4th Edition)",
		"Bjarne Stroustrup",
		OTHER,
		423,
		1988
	},
	{
		"9780812984414",
		"Cloud Atlas",
		"David Mitchell",
		CRIMINAL,
		244,
		2010
	},
	{
		"9780747543354",
		"Harry Potter and the Philosopher's Stone",
		"J. K. Rowling",
		FANTASY,
		243,
		1997
	},
	{
		"9780321563845",
		"The C++ Programming Language (4th Edition)",
		"Bjarne Stroustrup",
		CRIMINAL,
		2334,
		1987
	}
};

void writeBook(ostream& output, const Book& book) {
	output.write((char *) &book, sizeof(Book));
}

int main(int argc, char **argv) {
	const char* outputFileName = argc >= 2 ? argv[1] : "books.bin";

	ofstream output(outputFileName, ios::out | ios::binary);

	if (!output) {
		cout << "Can't open file " << outputFileName << endl;
		return 1;
	}

	for (int i = 0; i < sizeof(books) / sizeof(Book); i++) {
		writeBook(output, books[i]);
	}

	output.close();

	return 0;
}
