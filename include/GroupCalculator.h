#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Set.h"
#include "Operation.h"
#include "Union.h"
#include "Intersection.h"
#include "Difference.h"
#include "CompOperation.h"
#include "CompUnion.h"
#include "CompIntersection.h"
#include "CompDifference.h"
#include "CompProduct.h"
#include "Composite.h"


class GroupCalculator
{
public:
	GroupCalculator();
	~GroupCalculator();

	void runGroupCalculator();

	void readCommand();
	Set m_set;
	
private:
	void printOperationList() const;
	int commandRequest() const;
	void readGroup();
	void printGroup();
	void printResult();

	void do_eval();
	void do_union();
	void do_intersection();
	void do_difference();
	void do_product();
	void do_comp();
	void do_help() const;
	void do_delete();
	void do_exit();
	void do_error() const;

	int operation;
	int operation1;
	int operation2;

	bool m_calculatorIsRunning;

	std::vector<std::shared_ptr<Operation>> m_operation;	//Holds current list of commands(operations)
	std::vector<std::string> m_commands;					//Hold all commands (operations) options
	std::vector<Set> m_groups;
};

