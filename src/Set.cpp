#include"Set.h"


Set::Set()
{
}

Set::~Set()
{
}

std::vector<int> Set::getGroup()
{
    return readGrop();
}

std::vector<int> Set::getVectorOneGroup() const
{
    return m_groupVec;              //return one group from vector of all received groups.
}

void Set::setVectorForGroup(std::vector<int> newVec)
{
    m_groupVec = newVec;
}

void Set::printOneGroup() const
{
    for (int i = 0; i < m_groupVec.size(); ++i)
    { 
        std::cout << m_groupVec[i];
        if (i != m_groupVec.size() - 1)
            std::cout << ", ";
    }
}

std::vector<int> Set::readGrop()
{
    std::vector<int> grop;
    int gropSize;

    std::cin >> gropSize;

    for (int i = 0; i < gropSize; ++i)
    {
        int input;
        std::cin >> input;
        grop.push_back(input);
    }
 
    std::sort(grop.begin(), grop.end());
   
    auto [newEnd, end] = std::ranges::unique(grop);
    grop.erase(newEnd, end);
    m_groupVec = grop;

    return grop;
}