#include <fstream>
#include <iostream>
#include "Library.h"
using namespace std;


int main() {
	ifstream input("library-bad.bin", ios::in | ios::binary);
	ofstream output("library-good.bin", ios::out | ios::binary);

	if (!input || !output) {
		cout << "Can't open files" << endl;
	}

	while (true) {
		Book nextBook;
		input.read((char*) &nextBook, sizeof(Book));

		if (input.eof()) {
			break;
		}

		if (nextBook.genre != CRIMINAL) {
			if (nextBook.publishYear < 1999) {
				nextBook.numberOfPages += 20;
			}

			output.write((char*) &nextBook, sizeof(Book));
		}
	}

	input.close();
	output.close();

	return 0;
}
