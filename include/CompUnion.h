#pragma once
#include "CompOperation.h"


class CompUnion : public CompOperation
{
public:
	using CompOperation::CompOperation;
	virtual void setGroup(std::vector<Set>& groupVec);
};