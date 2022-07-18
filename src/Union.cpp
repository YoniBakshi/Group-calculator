#include "Union.h"


void Union::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();
	std::ranges::set_union(groupVec[FIRST].getVectorOneGroup(),
						   groupVec[SECOND].getVectorOneGroup(),
						   std::back_inserter(m_result));

	groupVec.erase(groupVec.begin());
	groupVec.erase(groupVec.begin());
}
