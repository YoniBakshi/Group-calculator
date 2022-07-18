#include "CompProduct.h"

void CompProduct::setGroup(std::vector<Set>& groupVec)
{
	m_result.clear();
	m_comp1->setGroup(groupVec);		//Calcualte result of first paired groups
	m_comp2->setGroup(groupVec);		//Calcualte result of second paired groups

	for(int i = 0; i < m_comp1->getRes().size(); ++i)
		for (int j = 0; j < m_comp2->getRes().size(); ++j)
			m_result.push_back(m_comp1->getRes()[i] * m_comp2->getRes()[j]);

	std::sort(m_result.begin(), m_result.end());

	auto [newEnd, end] = std::ranges::unique(m_result);
	m_result.erase(newEnd, end);
}
