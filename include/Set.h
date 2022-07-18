#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Set
{
public:
	Set();
	~Set();

	std::vector<int> getGroup();
	std::vector<int> m_groupVec;					//Holds vector of shared ptr to each group vector in each cell.
	std::vector<int> getVectorOneGroup() const;		//Return vector of one group.
	void setVectorForGroup(std::vector<int>);		
	void printOneGroup() const;

private:
	std::vector<int> readGrop();
};


