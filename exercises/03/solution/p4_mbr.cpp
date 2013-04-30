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
		cout << "Unknown partition";
	}

	cout << ")" << dec << endl;
}

int readInteger(istream& input) {
	unsigned char chunks[4];

	input.read((char*) chunks, sizeof(chunks));

	return (chunks[3] << 24) + (chunks[2] << 16) + (chunks[1] << 8) + chunks[0];
}

/*
 * The integers in the MBR file are stored in little endian format (read more at
 * http://en.wikipedia.org/wiki/Endianness). Basically, the endianness specifies how
 * the bytes in the integers are ordered in the memory (whether the most significant (Big Endian)
 * or the least significant (Little Endian) byte is first).
 *
 * Here we demonstrate two ways for reading little endian integers:
 *
 * - The first one makes use of that the x86 architectures uses little endianness and directly
 * reads the bytes in the memory. This solution is simple, but not multiplatform.
 *
 * - The second one (the function readInteger above of this comment) reads a chunk of 4 bytes
 * and orders them properly using binary operations. This solution is platform-independent.
 *
 */
void printPartitionInfo(istream& input) {
	unsigned char activeFlag;
	unsigned char partitionType;
	unsigned int firstSector;
	unsigned int numberOfSectors;

	input.read((char*) &activeFlag, 1);
	input.ignore(3);
	input.read((char*) &partitionType, 1);
	input.ignore(3);

	// Reading the two integers in two different ways
	input.read((char*) &firstSector, sizeof(firstSector));
	numberOfSectors = readInteger(input);

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


int main(int argc, char* argv[]) {
	const char* inputFileName = argc >= 2 ? argv[1] : "mbr.img";
	ifstream input(inputFileName, ios::in | ios::binary);

	if (!input) {
		cout << "Can't open file " << inputFileName << endl;
		return 1;
	}

	if (!checkSignature(input)) {
		cout << "The file doesn't start with a MBR sector\n";
		return 1;
	}

	printPartitionsInfo(input);

	return 0;
}
