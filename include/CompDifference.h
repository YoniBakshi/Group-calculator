#pragma once
#include "CompOperation.h"


class CompDifference : public CompOperation
{
public:
	using CompOperation::CompOperation;
	virtual void setGroup(std::vector<Set>& groupVec);
};