#include "Difference.h"


void Difference::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();
	std::ranges::set_difference(groupVec[FIRST].getVectorOneGroup(),
								groupVec[SECOND].getVectorOneGroup(),
								std::back_inserter(m_result));

	groupVec.erase(groupVec.begin());
	groupVec.erase(groupVec.begin());
}
