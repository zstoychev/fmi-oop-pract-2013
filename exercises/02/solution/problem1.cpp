#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream input("problem1-input.txt");

	if (!input) {
		cout << "Couldn't open problem1-input.txt" << endl;
		return 1;
	}

	while (true) {
		if (input.peek() == EOF) {
			break;
		}


		int minNumber, maxNumber;
		bool startedReadingLine = true;

		while (input.peek() != '#') {
			int next;
			input >> next;

			if (startedReadingLine) {
				minNumber = maxNumber = next;
				startedReadingLine = false;
			} else {
				minNumber = min(minNumber, next);
				maxNumber = max(maxNumber, next);
			}

			// ignores the space after the number
			input.ignore();
		}

		// ignores the # character and the new line after it
		input.ignore(2);

		if (!startedReadingLine) {
			cout << "Min/Max " << minNumber << "/" << maxNumber << endl;
		}
	}

	input.close();

	return 0;
}
