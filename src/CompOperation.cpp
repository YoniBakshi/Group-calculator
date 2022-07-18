#include "CompOperation.h"


CompOperation::CompOperation(std::shared_ptr<Operation>& oper1, std::shared_ptr<Operation>& oper2, std::string sign)
			  : m_comp1(oper1), m_comp2(oper2)
{
	m_numGropsToRead = m_comp1->getNumOfGruops() + m_comp2->getNumOfGruops();		//Calculate num of groups
	m_optionSign = sign;															//get operation's sign

	if (sign == COMP)
		--m_numGropsToRead;
}

void CompOperation::printOption(char& groupCharCount)
{
	std::cout << "(";
	m_comp1->printOption(groupCharCount);
	std::cout << " " << m_optionSign << " ";
	m_comp2->printOption(groupCharCount);
	std::cout << ")";
}

void CompOperation::printGr(std::vector<Set>& groupVec, int& groupNum)
{
	std::cout << "(";
	if (m_optionSign != COMP) 
	{
		m_comp1->printGr(groupVec, groupNum);
		std::cout << " " << m_optionSign << " ";
		m_comp2->printGr(groupVec, groupNum);
	}

	else
	{
		m_comp1->printGr(groupVec, groupNum);
		std::cout << " " << m_comp2->getType() << "{";
		groupVec[groupNum].printOneGroup();
		std::cout << "}";
	}

	std::cout << ")";
}
