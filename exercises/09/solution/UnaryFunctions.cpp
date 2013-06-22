#include "UnaryFunctions.h"

ostream& operator<<(ostream& output, const UnaryFunction& uf) {
	output << uf.toString();

	return output;
}
