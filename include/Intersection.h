#pragma once
#include "Operation.h"


class Intersection : public Operation
{
public:
	using Operation::Operation;
	void setGroup(std::vector<Set>& groupVec);
};