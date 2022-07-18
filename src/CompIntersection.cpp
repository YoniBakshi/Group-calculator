#include "CompIntersection.h"

void CompIntersection::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();
	m_comp1->setGroup(groupVec);		//Calcualte result of first paired groups
	m_comp2->setGroup(groupVec);		//Calcualte result of second paired groups
	std::ranges::set_intersection(m_comp1->getRes(), m_comp2->getRes(), std::back_inserter(m_result));
}
