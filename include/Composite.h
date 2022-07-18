#pragma once
#include "CompOperation.h"


class Composite : public CompOperation
{
public:
	using CompOperation::CompOperation;
	virtual void setGroup(std::vector<Set>& groupVec);
};