#include "Operation.h"


Operation::Operation(std::string str)
{
	m_optionSign = str;
	m_numGropsToRead = 2;
}

Operation::Operation()
{
}

int Operation::getNumOfGruops() const
{
	return m_numGropsToRead;
}

std::vector<int> Operation::getRes() const
{
	return m_result;
}

std::string Operation::getType() const
{
	return m_optionSign;
}


void Operation::printOption(char& groupCharCount)
{
	std::cout << "(" << groupCharCount++ << " " << m_optionSign << " " << groupCharCount++ << ")";
}

void Operation::printGr(std::vector<Set>& groupVec, int &groupNum)
{
	std::cout << "({";
	groupVec[groupNum++].printOneGroup();
	std::cout << "} " << m_optionSign << " {";
	groupVec[groupNum++].printOneGroup();
	std::cout << "})";
}
