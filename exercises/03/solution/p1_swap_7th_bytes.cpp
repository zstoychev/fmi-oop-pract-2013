#include <fstream>
#include <iostream>
using namespace std;

void swap7thBytes(iostream& stream) {
	stream.seekg(6, ios::beg);
	char a = stream.get();

	stream.seekg(-7, ios::end);
	char b = stream.get();

	stream.seekp(-7, ios::end);
	stream.put(a);

	stream.seekp(6, ios::beg);
	stream.put(b);
}


int main(int argc, char **argv) {
	const char* fileName = argc >= 2 ? argv[1] : "file.bin";

	fstream stream(fileName, ios::in | ios::out | ios::binary);

	if (!stream) {
		cout << "Can't open file " << fileName << endl;
		return 1;
	}

	swap7thBytes(stream);

	stream.close();

	return 0;
}
