#pragma once
#include "Operation.h"


class Union : public Operation
{
public:
	using Operation::Operation;
	void setGroup(std::vector<Set>& groupVec);
};