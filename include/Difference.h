#pragma once
#include "Operation.h"


class Difference : public Operation
{
public:
	using Operation::Operation;
	void setGroup(std::vector<Set>& groupVec);
};