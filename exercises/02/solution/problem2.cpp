#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream input("problem2-input.txt");

	if (!input) {
		cout << "Couldn't open problem2-input.txt" << endl;
		return 1;
	}

	while (true) {
		if (input.peek() == EOF) {
			break;
		}


		int minNumber, maxNumber;
		bool startedReadingLine = true;

		while (input.peek() != '\n') {
			int next;
			input >> next;

			if (startedReadingLine) {
				minNumber = maxNumber = next;
				startedReadingLine = false;
			} else {
				minNumber = min(minNumber, next);
				maxNumber = max(maxNumber, next);
			}
		}

		// ignores the new line character
		input.ignore(1);

		if (!startedReadingLine) {
			cout << "Min/Max " << minNumber << "/" << maxNumber << endl;
		}
	}

	input.close();

	return 0;
}
