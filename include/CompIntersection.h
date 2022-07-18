#pragma once
#include "CompOperation.h"


class CompIntersection : public CompOperation
{
public:
	using CompOperation::CompOperation;
	virtual void setGroup(std::vector<Set>& groupVec);
};