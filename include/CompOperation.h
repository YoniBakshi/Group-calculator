#pragma once
#include "Operation.h"


class CompOperation : public Operation
{
public:
	CompOperation(std::shared_ptr<Operation>& , std::shared_ptr<Operation>&, std::string);
	virtual ~CompOperation() = default;
	virtual void setGroup(std::vector<Set>&) override {};	
	virtual void printGr(std::vector<Set>& groupVec, int& groupNum);
	void printOption(char&);
protected:
	std::shared_ptr<Operation> m_comp1;
	std::shared_ptr<Operation> m_comp2;
};