#include "System.h"

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::cerr;

void System::printHelp()
{
	cout
		<< " ------------------ Commands ------------------- - -------------------- Info --------------------" << endl
		<< "  help       \t\t\t\t\t - displays this message" << endl
		<< "  print \t\t\t\t\t - prints the table" << endl
		<< "  edit <address> <value> \t\t\t - sets a value to a cell" << endl
		<< "  open <path> \t\t\t\t\t - opens a file" << endl
		<< "  close \t\t\t\t\t - closes the current file" << endl
		<< "  new \t\t\t\t\t\t - creates a new file" << endl
		<< "  save \t\t\t\t\t\t - saves the table in the current file" << endl
		<< "  saveas <path>\t\t\t\t\t - saves the table in an existing file" << endl
		<< "  exit       \t\t\t\t\t - exits the program." << endl << endl;
}

System::System()
{}

System::~System()
{
	m_table.clear();
}

System& System::i()
{
	static System sys;
	return sys;
}

void System::run()
{
	printHelp();

	bool saved = true;
	string command;
	tokens tokens;

	while (true)
	{
		cout << '>';
		getline(cin, command);
		if (command == "")
			continue;

		try
		{
			Proccessor::process(command, tokens);
		}
		catch (const std::invalid_argument& e)
		{
			cerr << e.what() << endl;
		}
		Proccessor::toUpper(tokens[0]);

		if (tokens[0] == "PRINT")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}
			if (m_doc.isNew() || m_doc.isOpen())
			{
				m_table.print();
			}
			else
				cout << "Create a new document or open an existing file first!" << endl;
		}
		else if (tokens[0] == "EDIT")
		{
			if (tokens.size() != 3)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}
			Proccessor::toUpper(tokens[1]);
			if (!Proccessor::isAddress(tokens[1]))
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			if (m_doc.isNew() || m_doc.isOpen())
			{
				size_t row = 0, col = 0;
				Proccessor::getPosition(tokens[1], row, col);

				if (Proccessor::isString(tokens[2]))
				{
					Proccessor::processString(tokens[2]);
					if (Proccessor::isInteger(tokens[2]))
						m_table.edit(new Integer(tokens[2]), row, col);
					else if (Proccessor::isDouble(tokens[2]))
						m_table.edit(new Double(tokens[2]), row, col);
					else if (Proccessor::isFormula(tokens[2]))
					{
						try
						{
							m_table.edit(new Formula(tokens[2], &m_table), row, col);
						}
						catch (const std::invalid_argument& e)
						{
							m_table.edit(new String("ERROR"), row, col);
							cerr << e.what() << endl;
							continue;
						}
					}
					else
					{
						m_table.edit(new String(tokens[2]), row, col);
					}
				}
				else
				{
					if (Proccessor::isInteger(tokens[2]))
						m_table.edit(new Integer(tokens[2]), row, col);
					else if (Proccessor::isDouble(tokens[2]))
						m_table.edit(new Double(tokens[2]), row, col);
					else
						cerr << "Error: row " << row << ", col " << col << " ," << tokens[2] << " is unknown data type!" << endl;
				}

				Proccessor::updateFormulas(m_table);

				saved = false;
			}
			else
				cout << "Create a new document or open an existing file first!" << endl;
		}
		else if (tokens[0] == "OPEN")
		{
			if (tokens.size() != 2)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			try
			{
				if (m_doc.isNew() || m_doc.isOpen())
				{
					m_table.clear();
				}
				if (Proccessor::isString(tokens[1]))
					Proccessor::processString(tokens[1]);

				m_doc.open(tokens[1], m_table);
			}
			catch (const std::invalid_argument& e)
			{
				m_table.clear();
				cerr << e.what() << endl;
				continue;
			}
			cout << "Successfully opened " << m_doc.getFileName() << endl;
		}
		else if (tokens[0] == "CLOSE")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			string doc;
			if (!saved)
			{
				cout << "Do you want to save the changes to " << m_doc.getFileName() << "? (yes/no/cancel)" << endl;
				string ans;
				cin >> ans;
				if (ans == "yes")
				{
					doc = m_doc.getFileName();
					if (m_doc.isNew())
					{
						string path;
						cout << "Enter file path: " << endl;
						cin >> path;
						try
						{
							m_doc.saveAs(path, m_table);
						}
						catch (const std::invalid_argument& e)
						{
							cerr << e.what() << endl;
							cin.ignore();
							continue;
						}
					}
					else if (m_doc.isOpen())
					{
						try
						{
							m_doc.save(m_table);
						}
						catch (const std::invalid_argument& e)
						{
							cerr << e.what() << endl;
							cin.ignore();
							continue;
						}
					}
					m_table.clear();
					m_doc.close();
					saved = true;
					cout << "Successfully saved the changes to " << doc << endl;
					cin.ignore();
				}
				else if (ans == "no")
				{
					doc = m_doc.getFileName();
					try
					{
						m_doc.close();
					}
					catch (const std::invalid_argument& e)
					{
						cerr << e.what() << endl;
						cin.ignore();
						continue;
					}
					saved = true;
					m_table.clear();
					cout << "Successfully closed " << doc << endl;
					cin.ignore();
				}
				else if (ans == "cancel")
				{
					cin.ignore();
					continue;
				}
			}
			else
			{
				doc = m_doc.getFileName();
				try
				{
					m_doc.close();
				}
				catch (const std::invalid_argument& e)
				{
					cerr << e.what() << endl;
					continue;
				}
				m_table.clear();
				cout << "Successfully closed " << doc << endl;
			}
		}
		else if (tokens[0] == "NEW")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			try
			{
				if (m_doc.isNew() || m_doc.isOpen())
				{
					m_table.clear();
				}
				m_doc.newDoc();
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << "New document created" << endl;
		}
		else if (tokens[0] == "SAVE")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			try
			{
				m_doc.save(m_table);
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			saved = true;
			cout << "Successfully saved the changes to " << m_doc.getFileName() << endl;
		}
		else if (tokens[0] == "SAVEAS")
		{
			if (tokens.size() != 2)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			try
			{
				m_doc.saveAs(tokens[1], m_table);
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			saved = true;
			cout << "Successfully saved the changes to " << m_doc.getFileName() << endl;
		}
		else if (tokens[0] == "HELP")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			printHelp();
		}
		else if (tokens[0] == "EXIT")
		{
			if (tokens.size() != 1)
			{
				cerr << "Invalid command!" << endl;
				continue;
			}

			return;
		}
	}
}
