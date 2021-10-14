#include "ComparableInt.h"

int ComparableInt::compare_to(const Comparable& rhs) {
	const ComparableInt* cInt = dynamic_cast<const ComparableInt*>(&rhs);
	if (cInt != NULL) {
		return (this->value < cInt->value) * -1 + (this->value > cInt->value) * 1 ;
	}
	else {
		return -2;
	}
}

ComparableInt::ComparableInt(int val) : value(val) {
	
}

std::string ComparableInt::toString() {
	return std::to_string(this->value);
}
 