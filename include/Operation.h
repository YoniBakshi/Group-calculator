#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "Set.h"
#include "Consts.h"


class Operation
{
public:
	Operation(std::string);
	Operation();
	
	virtual ~Operation() = default;
	virtual void setGroup(std::vector<Set> &groupVec) = 0;
	virtual std::vector<int> getRes() const;
	virtual void printOption(char&);
	virtual void printGr(std::vector<Set>& groupVec, int& groupNum);
	int getNumOfGruops() const;  
	std::string getType() const;
	int m_currGroupIndex = 0;

protected:
	std::vector<int> m_result;
	std::string m_optionSign;			//Sign for each operation
	int m_numGropsToRead = 0;			//Required groups to read for according to operation 
};