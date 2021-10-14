#pragma once

#include "Comparable.h"

class ComparableInt : public Comparable
{
public:
	ComparableInt(int val);
	virtual int compare_to(const Comparable& rhs);
	virtual std::string toString();
	int value;
};