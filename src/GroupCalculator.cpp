#include "GroupCalculator.h"

GroupCalculator::GroupCalculator()
	: m_calculatorIsRunning(true),
	  m_operation({})
{
	m_commands = { "uni", "inter", "diff", "prod", "comp", "eval", "del", "help", "exit" };

	m_operation.push_back(std::make_shared<Union>(UNI));
	m_operation.push_back(std::make_shared<Intersection>(INTER));
	m_operation.push_back(std::make_shared<Difference>(DIFF));

}

GroupCalculator::~GroupCalculator()
{
}

void GroupCalculator::runGroupCalculator()
{
	//Main loop. Runs until user requests to exit
	while (m_calculatorIsRunning)
	{
		printOperationList();
		readCommand();
	}
}

int GroupCalculator::commandRequest() const	//Read command from user
{
	std::string theCommand;
	std::cin >> theCommand;			//str input

	for (int i = 0; i < m_commands.size(); ++i)
		if (theCommand.compare(m_commands[i]) == 0)
			return i;

	return (-1);
}

void GroupCalculator::readCommand()
{

	switch (commandRequest())
	{
	case 0:		//uni
		do_union();
		break;

	case 1:		//inter
		do_intersection();
		break;

	case 2:		//diff
		do_difference();
		break;

	case 3:		//prod
		do_product();
		break;

	case 4:		//comp
		do_comp();
		break;

	case 5:		//eval
		do_eval();
		break;

	case 6:		//del
		do_delete();
		break;

	case 7:		//help
		do_help();
		break;

	case 8:		//exit
		do_exit();
		break;

	default:	
		do_error();
		break;
	}
}


void GroupCalculator::do_eval()
{
	std::cin >> operation;
	readGroup();
	printGroup(); //print readin groups
	m_operation[operation]->setGroup(m_groups); //do the calculate
	printResult();
}

void GroupCalculator::printResult()
{
	std::cout << " = {";
	m_set.setVectorForGroup(m_operation[operation]->getRes());
	m_groups.push_back(m_set);
	m_groups[FIRST].printOneGroup();
	std::cout << "}\n";
	m_groups.clear();
}

void GroupCalculator::printGroup()		
{
	int groupNum = 0;
	m_operation[operation]->printGr(m_groups, groupNum);
}

void GroupCalculator::do_union()
{
	std::cin >> operation1 >> operation2;
	m_operation.push_back(std::make_shared<CompUnion>(m_operation[operation1], m_operation[operation2], UNI));

}

void GroupCalculator::do_intersection()
{
	std::cin >> operation1 >> operation2;
	m_operation.push_back(std::make_shared<CompIntersection>(m_operation[operation1], m_operation[operation2], INTER));
}

void GroupCalculator::do_difference()
{
	std::cin >> operation1 >> operation2;
	m_operation.push_back(std::make_shared<CompDifference>(m_operation[operation1], m_operation[operation2], DIFF));
}

void GroupCalculator::do_product()
{
	std::cin >> operation1 >> operation2;
	m_operation.push_back(std::make_shared<CompProduct>(m_operation[operation1], m_operation[operation2], PROD));
}

void GroupCalculator::do_comp()
{
	std::cin >> operation1 >> operation2;
	m_operation.push_back(std::make_shared<Composite>(m_operation[operation1], m_operation[operation2], COMP));

}

void GroupCalculator::do_delete()
{
	std::cin >> operation1;
	m_operation.erase(m_operation.begin() + operation1);
}

void GroupCalculator::do_help() const
{
	std::cout << "\n"
		<< "The available commands are :\n"
		<< "* eval(uate) num ... - compute the result of function #num on the following\n"
		<< "set(s); each set is prefixed with the count of numbers to read\n"
		<< "* uni(on) num1 num2 - Creates an operation that is the union of operation\n"
		<< "#num1 and operation #num2\n"
		<< "* inter(section) num1 num2 - Creates an operation that is the intersection\n"
		<< "of operation #num1 and operation #num2\n"
		<< "* diff(erence) num1 num2 - Creates an operation that is the difference of\n"
		<< "operation #num1 and operation #num2\n"
		<< "* prod(uct) num1 num2 - Creates an operation that returns the product of\n"
		<< " the items from the results of operation #num1 and operation #num2\n"
		<< "* comp(osite) num1 num2 - creates an operation that is the composition of\n"
		<< "operation #num1 and operation #num2\n"
		<< "* del(ete) num - delete operation #num from the operation list\n"
		<< "* help - print this command list\n"
		<< "* exit - exit the program\n\n";
}

void GroupCalculator::do_exit() 
{
	std::cout << "GoodBye (:";
	m_calculatorIsRunning = false;
}

void GroupCalculator::readGroup()
{
	for (int i = 0; i < m_operation[operation]->getNumOfGruops(); ++i)
	{
		m_set.getGroup();
		m_groups.push_back(m_set);
	}
}

void GroupCalculator::printOperationList() const
{
	char groupCharCount;
	std::cout << "\nList of available set operations: \n";

	for (int i = 0; i < m_operation.size(); i++)
	{
		groupCharCount = 'A';
		std::cout << "#" << i << ": ";
		m_operation[i]->printOption(groupCharCount);
		std::cout << "\n";
	}
	std::cout << "Enter command ('help' for the list of available commands): \n";
}


void GroupCalculator::do_error() const
{
	std::cout << "\n**Dear user,"
			  << "\n**Your command request doesn't exist.\n"
			  << "**Please try again.\n";
	//Clear buffer after error msg sent
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
