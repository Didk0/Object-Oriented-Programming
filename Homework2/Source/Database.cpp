#include "Database.h"

const unsigned int MAX_COMMAND_LEN = 64;
const unsigned int MAX_REG_LEN = 64;
const unsigned int MAX_DESCIPT_LEN = 64;
const unsigned int MAX_NAME_LEN = 64;
const unsigned int MAX_PATH_LEN = 128;

Database::Database()
{}

void Database::validateInput(const string& command, tokens& tokens)
{
	if (command == "")
	{
		tokens.push_back(command);
	}

	//size_t tokensInd = 0;
	size_t comandInd = 0;
	size_t len = command.size();

	for (size_t i = 0; i < len; i++)
	{
		if (command[i] == ' ')
		{
			tokens.push_back(command.substr(comandInd, i - comandInd));
			//tokensInd++;
			comandInd = i + 1;
		}
		else if (i == (len - 1))
		{
			tokens.push_back(command.substr(comandInd, i - comandInd + 1));
		}
	}

	if (tokens.size() > 3)
	{
		throw invalid_argument("Too many arguments!");
	}
}

bool Database::isID(const string& str) const
{
	size_t len = str.size();
	for (size_t i = 0; i < len; i++)
	{
		if (!isDigit(str[i]))
		{
			return false;
		}
	}

	return true;
}

void Database::toUpper(string& str)
{
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 'a' - 'A';
		}
	}
}

void Database::printPeople() const
{
	size_t count = m_people.size();
	for (size_t i = 0; i < count; i++)
	{
		cout << m_people[i] << endl;
	}
}

void Database::printVehicles() const
{
	size_t count = m_vehicles.size();
	for (size_t i = 0; i < count; i++)
	{
		cout << m_vehicles[i] << endl;
	}
}

string& Database::at(size_t index, tokens& tokens)
{
	if (index >= tokens.size())
	{
		throw invalid_argument("Too few arguments!");
	}

	return tokens[index];
}

unsigned int Database::atoi(string& str)
{
	unsigned int res = 0;
	size_t len = str.size();
	for (size_t i = 0; i < len; i++)
	{
		res *= 10;
		res += str[i] - '0';
	}
	return res;
}

Database& Database::instance()
{
	static Database db;
	return db;
}

Person* Database::findPerson(unsigned int ID)
{
	size_t len = m_people.size();
	for (size_t i = 0; i < len; i++)
	{
		if (m_people[i].getId() == ID)
		{
			return &m_people[i];
		}
	}

	return nullptr;
}

Vehicle* Database::findVehicle(const string& regNum)
{
	size_t len = m_vehicles.size();
	for (size_t i = 0; i < len; i++)
	{
		if (m_vehicles[i].getRegNum() == regNum)
		{
			return &m_vehicles[i];
		}
	}

	return nullptr;
}

void Database::addPerson(const string& name, unsigned int ID)
{
	if (findPerson(ID))
	{
		throw std::invalid_argument("Person with this ID already exists!");
	}

	Person person(name, ID);
	m_people.push_back(person);
}

void Database::removePerson(unsigned int ID)
{
	size_t len = m_people.size();
	size_t ind = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (m_people[i].getId() == ID)
		{
			ind = i;
			break;
		}
	}

	Person person = m_people[ind];
	size_t length = person.getVehiclesNum();

	for (size_t i = 0; i < length; i++)
	{
		release(ID, person.getCurrVehicle(0));
	}

	m_people.erase(m_people.begin() + ind);
}

void Database::addVehicle(const string& regNum, const string& description)
{
	if (findVehicle(regNum))
	{
		throw std::invalid_argument("Vehicle with this registration already exists!");
	}

	Vehicle vehicle(regNum, description);
	m_vehicles.push_back(vehicle);
}

void Database::removeVehicle(const string& regNum)
{
	size_t len = m_vehicles.size();
	size_t ind = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (m_vehicles[i].getRegNum() == regNum)
		{
			ind = i;
			break;
		}
	}

	if (m_vehicles[ind].getOwnerID() != 0)
	{
		release(m_vehicles[ind].getOwnerID(), regNum);
	}

	m_vehicles.erase(m_vehicles.begin() + ind);
}

void Database::acquire(unsigned int ownerID, const string& regNum)
{
	Person* person = findPerson(ownerID);
	Vehicle* vehicle = findVehicle(regNum);

	if (!person)
	{
		throw std::invalid_argument("There is no person with this ID!");
	}
	if (!vehicle)
	{
		throw std::invalid_argument("There is no vehicle with this registration!");
	}
	person->addRegNum(regNum);
	vehicle->setOwner(ownerID);
}

void Database::release(unsigned int ownerID, const string& regNum)
{
	Person* person = findPerson(ownerID);
	Vehicle* vehicle = findVehicle(regNum);

	if (!person)
	{
		throw std::invalid_argument("There is no person with this ID!");
	}
	if (!vehicle)
	{
		throw std::invalid_argument("There is no vehicle with this registration!");
	}

	vehicle->setOwner(0);
	person->removeRegNum(regNum);
}

void Database::displayHelp() const
{
	std::cout
		<< " ------------------ Commands ------------------- - -------------------- Info --------------------" << std::endl
		<< "  HELP       \t\t\t\t\t - displays this message" << std::endl
		<< "  VEHICLE <registration> <description> \t\t - adds data about a vehicle" << std::endl
		<< "  PERSON <name> <id> \t\t\t\t - adds data about a person" << std::endl
		<< "  ACQUIRE <owner-id> <vehicle-id>\t\t - adds vehicle to a person" << std::endl
		<< "  RELEASE <owner-id> <vehicle-id>\t\t - removes a vehicle from a person" << std::endl
		<< "  REMOVE <what>\t\t\t\t\t - removes a person/vehicle from the database" << std::endl
		<< "  SAVE <path>\t\t\t\t\t - saves the database to a file" << std::endl
		<< "  SHOW [PEOPLE|VEHICLES|<id>]\t\t\t - displays information about the objects" << std::endl
		<< "  EXIT       \t\t\t\t\t - exits the program." << std::endl
		<< " ------------------------------------------------------------------------------------------------" << std::endl;
}

void Database::run()
{
	char ch;
	cout << "Do you want to load database from file? (y/n)" << endl;
	cin >> ch;
	if (ch == 'y')
	{
		string fileName;
		cout << "Enter file path: ";
		cin >> fileName;
		try
		{
			readFromFile(fileName);
		}
		catch (const std::invalid_argument& e)
		{
			cerr << e.what() << endl;
		}
	}

	displayHelp();

	string cmd;
	tokens tokens;
	cin.ignore(MAX_COMMAND_LEN, '\n');

	do
	{
		tokens.clear();
		getline(cin, cmd);
		try
		{
			validateInput(cmd, tokens);
		}
		catch (const invalid_argument& e)
		{
			cerr << e.what() << endl;
			continue;
		}

		toUpper(tokens[0]);

		if (tokens[0] == "HELP")
		{
			displayHelp();
		}
		else if (tokens[0] == "VEHICLE")
		{
			try
			{
				addVehicle(at(1, tokens), at(2, tokens));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << "Vehicle with registration " << tokens[1] << " added successfully!" << endl;
		}
		else if (tokens[0] == "PERSON")
		{
			try
			{
				addPerson(at(1, tokens), atoi(at(2, tokens)));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << tokens[1] << " added successfully!" << endl;
		}
		else if (tokens[0] == "ACQUIRE")
		{
			try
			{
				acquire(atoi(at(1, tokens)), at(2, tokens));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << "Vehicle with registration " << tokens[2] << " added to " << findPerson(atoi(tokens[1]))->getName() << "!" << endl;
		}
		else if (tokens[0] == "RELEASE")
		{
			try
			{
				release(atoi(at(1, tokens)), at(2, tokens));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << "Vehicle with registration " << tokens[2] << " removed from " << findPerson(atoi(tokens[1]))->getName() << "!" << endl;
		}
		else if (tokens[0] == "REMOVE")
		{
			try
			{
				isID(at(1, tokens));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			if (isID(at(1, tokens)))
			{
				Person* person = findPerson(atoi(tokens[1]));
				string name = person->getName();
				if (!person)
				{
					cerr << "Person not found!" << endl;
				}
				else
				{
					if (person->getVehiclesNum() != 0)
					{
						cout << "Are you sure you want to remove " << person->getName() << "? (y/n)" << endl;
						char ch;
						cin >> ch;
						if (ch == 'y')
						{
							removePerson(atoi(tokens[1]));
						}
						else if (ch == 'n')
						{
							continue;
						}
					}
					else
					{
						removePerson(atoi(tokens[1]));
					}
				}
				cout << name << " removed successfully!" << endl;
			}
			else
			{
				Vehicle* vehicle = findVehicle(tokens[1]);
				string regNum = vehicle->getRegNum();
				if (!vehicle)
				{
					cerr << "Vehicle not found!" << endl;
				}
				else
				{
					if (vehicle->getOwnerID() == 0)
					{
						removeVehicle(tokens[1]);
					}
					else if (vehicle->getOwnerID() != 0)
					{
						cout << "Are you sure you want to remove vehicle with registration " << vehicle->getRegNum() << "? (y/n)" << endl;
						char ch;
						cin >> ch;
						if (ch == 'y')
						{
							removeVehicle(tokens[1]);
						}
						else if (ch == 'n')
						{
							continue;
						}
					}
				}
				cout << "Vehicle with registration " << regNum << " removed successfully!" << endl;
			}
		}
		else if (tokens[0] == "SAVE")
		{
			string fileName;
			try
			{
				fileName = tokens[1];
				writeToFile(fileName);
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			cout << "Successfully saved to file with path: " << fileName << std::endl;
		}
		else if (tokens[0] == "SHOW")
		{
			try
			{
				toUpper(at(1, tokens));
			}
			catch (const std::invalid_argument& e)
			{
				cerr << e.what() << endl;
				continue;
			}
			if (tokens[1] == "PEOPLE")
			{
				if (m_people.size() == 0)
					cout << "There are no people in the database." << endl;
				else
					printPeople();
			}
			else if (tokens[1] == "VEHICLES")
			{
				if (m_vehicles.size() == 0)
					cout << "There are no vehicles in the database." << endl;
				else
					printVehicles();
			}
			else if (isID(tokens[1]))
			{
				Person* person = findPerson(atoi(tokens[1]));

				if (!person)
					cout << "There is no person with this ID!" << endl;
				else
					cout << *person << endl;
			}
			else if (!isID(tokens[1]))
			{
				Vehicle* vehicle = findVehicle(tokens[1]);

				if (!vehicle)
					cout << "There is no vehicle with this registration!" << endl;
				else
					cout << *vehicle << endl;
			}
		}
	} while (tokens[0] != "EXIT");
}

void Database::readFromFile(const string& file)
{
	ifstream in(file);
	if (!in)
	{
		throw invalid_argument("Couldn't open file for reading!");
	}

	size_t peopleCount, vehicleCount;

	in >> vehicleCount;

	for (size_t i = 0; i < vehicleCount; i++)
	{
		string regNum, description;

		in >> regNum >> description;

		addVehicle(regNum, description);
	}

	in >> peopleCount;

	for (size_t i = 0; i < peopleCount; i++)
	{
		size_t regCount, id;
		string name;

		in >> name >> id >> regCount;
		addPerson(name, id);

		for (size_t j = 0; j < regCount; j++)
		{
			string regNum;
			in >> regNum;
			acquire(id, regNum);
		}
	}

	in.close();
}

void Database::writeToFile(const string& file)
{
	ofstream out(file);
	if (!out)
	{
		throw invalid_argument("Couldn't open file for writing!");
	}

	size_t vehicleCount = m_vehicles.size();
	size_t peopleCount = m_people.size();

	out << vehicleCount << endl;
	for (size_t i = 0; i < vehicleCount; i++)
	{
		out << m_vehicles[i].getRegNum() << ' ' << m_vehicles[i].getDescription() << endl;
	}

	out << peopleCount << endl;
	for (size_t i = 0; i < peopleCount; i++)
	{
		size_t regCount = m_people[i].getVehiclesNum();

		out << m_people[i].getName() << ' ' << m_people[i].getId() << ' ' << regCount << endl;

		for (size_t j = 0; j < regCount; j++)
		{
			out << m_people[i].getCurrVehicle(j) << ' ';
		}
		out << endl;
	}

	out.close();
}
