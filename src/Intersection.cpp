#include "Intersection.h"


void Intersection::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();

	std::ranges::set_intersection(groupVec[FIRST].getVectorOneGroup(),
								  groupVec[SECOND].getVectorOneGroup(),
								  std::back_inserter(m_result));

	groupVec.erase(groupVec.begin());
	groupVec.erase(groupVec.begin());
}
