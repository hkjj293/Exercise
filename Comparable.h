#pragma once
#include <string>
class Comparable
{
public:
	virtual int compare_to(const Comparable & rhs) = 0;
	virtual std::string toString()=0;
};