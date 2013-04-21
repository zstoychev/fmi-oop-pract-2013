#include <iostream>
#include <fstream>
using namespace std;

int getNextLineLength(istream& input) {
	int result = 0;

	while (true) {
		int nextChar = input.get();

		if (nextChar == EOF || nextChar == '\n') {
			break;
		}

		result++;
	}

	return result;
}

int main(int argc, char **argv) {
	const char* inputFileName = argc >= 2 ? argv[1] : "stats.txt";

	ifstream input(inputFileName);

	if (!input) {
		cout << "Couldn't open file " << inputFileName << endl;
		return 1;
	}

	int longestLineNumber = -1;
	int longestLineLength = -1;

	int currentLineNumber = 0;
	while (!input.eof()) {
		int nextLineLength = getNextLineLength(input);

		if (nextLineLength > longestLineLength) {
			longestLineNumber = currentLineNumber;
			longestLineLength = nextLineLength;
		}

		currentLineNumber++;
	}

	input.close();

	cout << "The longest line is line #" << longestLineNumber + 1 << endl;

	return 0;
}
