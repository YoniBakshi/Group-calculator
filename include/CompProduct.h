#pragma once
#include "CompOperation.h"


class CompProduct : public CompOperation
{
public:
	using CompOperation::CompOperation;
	virtual void setGroup(std::vector<Set>& groupVec);
};