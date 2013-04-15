#include "util.h"

int gcd(int a, int b) {
	while (b > 0) {
		int oldB = b;
		b = a % b;
		a = oldB;
	}

	return a;
}

int sign(int n) {
	if (n > 0) {
		return 1;
	} else if (n < 0) {
		return -1;
	} else {
		return 0;
	}
}
