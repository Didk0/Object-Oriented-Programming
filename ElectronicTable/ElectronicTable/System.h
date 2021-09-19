#pragma once
#include <string>
#include <iostream>
#include "Table.h"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include "Formula.h"
#include "Document.h"
#include "Proccessor.h"

using std::string;

class System
{
	using tokens = std::vector<string>;

public:
	System(const System& other) = delete;
	System& operator=(const System& other) = delete;
	~System();

	/// @brief the instance of the class System
	/// @return address of a System
	static System& i();

	/// @brief executes the main logic of the program and does different commands
	void run();

	/// @brief prints the help menu
	void printHelp();

private:
	System();

private:
	Table m_table;
	Document m_doc;
};