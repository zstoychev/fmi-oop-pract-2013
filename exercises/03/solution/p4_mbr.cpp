#include <iostream>
#include <fstream>
using namespace std;

bool checkSignature(istream& input) {
	unsigned char signature[2];

	input.seekg(510);
	input.read((char*) signature, 2);

	return signature[0] == 0x55 && signature[1] == 0xAA;
}

void printPartitionType(unsigned char partitionType) {
	cout << "Partition type: 0x" << hex << unsigned(partitionType) << " (";

	switch (partitionType) {
	case 0x05:
	case 0x0F:
		cout << "Extended partition";
		break;
	case 0x83:
		cout << "Linux partition";
		break;
	case 0x82:
		cout << "Linux swap partition";
		break;
	case 0x07:
		cout << "NTFS partition";
		break;
	default:
		cout << "unknown partition";
	}

	cout << ")" << dec << endl;
}

void printPartitionInfo(istream& input) {
	unsigned char activeFlag;
	unsigned char partitionType;
	unsigned int firstSector;
	unsigned int numberOfSectors;

	input.read((char*) &activeFlag, 1);
	input.ignore(3);
	input.read((char *) &partitionType, 1);
	input.ignore(3);
	input.read((char *) &firstSector, sizeof(firstSector));
	input.read((char *) &numberOfSectors, sizeof(numberOfSectors));

	if (partitionType == 0x00) {
		cout << "Empty partition entry\n";
		return;
	} else {
		if (activeFlag & 0x80) {
			cout << "Active flag set\n";
		}

		printPartitionType(partitionType);

		cout << "Starting byte: " << firstSector * 512ull << endl;
		cout << "Number of bytes: " << numberOfSectors * 512ull << endl;
	}
}

void printPartitionsInfo(istream& input) {
	input.seekg(446);

	for (int i = 0; i < 4; i++) {
		cout << "Partition " << i << ":\n";
		printPartitionInfo(input);
	}
}

int main() {
	ifstream input("sdabeginning.img");

	if (!checkSignature(input)) {
		cout << "The file doesn't start with a MBR sector\n";
	}

	printPartitionsInfo(input);

	return 0;
}
