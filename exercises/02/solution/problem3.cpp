#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main(int argc, char **argv) {
	int occurrences[UCHAR_MAX + 1] = {};
	int totalSymbols = 0;

	const char* inputFileName = argc >= 2 ? argv[1] : "stats.txt";

	ifstream input(inputFileName);

	if (!input) {
		cout << "Couldn't open file " << inputFileName << endl;
		return 1;
	}

	while (true) {
		int next = input.get();

		if (next == EOF) {
			break;
		}

		occurrences[next]++;
		totalSymbols++;
	}

	input.close();

	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		if (occurrences[i] > 0) {
			cout << (unsigned char) i << ": " << 100 * float(occurrences[i]) / totalSymbols << "%" << endl;
		}
	}

	return 0;
}
