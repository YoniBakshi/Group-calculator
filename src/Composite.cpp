#include "Composite.h"


void Composite::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();
	m_comp1->setGroup(groupVec);		//Calculate result of first paired groups
	Set temp;
	temp.setVectorForGroup(m_comp1->getRes());
	temp.getVectorOneGroup();
	groupVec.push_back((temp));
	std::rotate(groupVec.rbegin(), groupVec.rbegin() + 1, groupVec.rend());
	m_comp2->setGroup(groupVec);		//Calcualte result of second paired groups
	m_result = m_comp2->getRes();
}