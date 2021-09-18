#include <iostream>
#include "Garage.h"

const int MAX_CMD_LEN = 20;

void displayHelp()
{
	std::cout
		<< " ------------------ Commands ------------------- - -------------------- Info --------------------" << std::endl
		<< "help       \t\t\t\t\t - displays this message" << std::endl
		<< "add_vehicle <registration> <description> <space> - add vehicle" << std::endl
		<< "remove_vehicle <registration>\t\t\t - remove vehicle" << std::endl
		<< "print  \t\t\t\t\t\t - prints all vehicles" << std::endl
		<< "quit  \t\t\t\t\t\t - stops the program" << std::endl << std::endl;
}

int main()
{
	Garage g1(5);

	size_t garageSize;
	std::cout << "Enter garage size: ";
	std::cin >> garageSize;
	Garage garage(garageSize);
	Vehicle** vehicles = new Vehicle * [garageSize];
	size_t ind = 0;

	displayHelp();

	char command[MAX_CMD_LEN];
	std::cout << "Enter command: ";
	std::cin >> command;

	while (strcmp(command, "quit") != 0)
	{
		if (strcmp(command, "help") == 0)
		{
			displayHelp();
		}
		else if (strcmp(command, "add_vehicle") == 0)
		{
			char reg[8];
			char description[20];
			int space;
			std::cin >> reg;
			std::cin >> description;
			std::cin >> space;
			Vehicle* vehicle = new Vehicle(reg, description, space);
			bool exc = false;
			try
			{
				garage.insert(*vehicle);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
				exc = true;
			}
			if (!exc)
			{
				vehicles[ind++] = vehicle;
			}
		}
		else if (strcmp(command, "remove_vehicle") == 0)
		{
			char reg[8];
			std::cin >> reg;
			if (garage.find(reg) == nullptr)
			{
				std::cerr << "Vehicle not found!" << std::endl;
			}
			else
			{
				garage.erase(reg);
				for (size_t i = 0; i < ind; i++)
				{
					if (strcmp(vehicles[i]->registration(), reg) == 0)
					{
						vehicles[i] = vehicles[ind - 1];
						vehicles[ind - 1] = nullptr;
						ind--;
						break;
					}
				}
			}
		}
		else if (strcmp(command, "print") == 0)
		{
			for (size_t i = 0; i < ind; i++)
			{
				std::cout << "Vehicle " << i + 1 << ": " << vehicles[i]->registration()
					<< " " << vehicles[i]->description() << " " << vehicles[i]->space() << std::endl;
			}
		}
		std::cout << "Enter command: ";
		std::cin >> command;
	}

	for (size_t i = 0; i < ind; i++)
	{
		delete vehicles[i];
	}
	delete[] vehicles;

	return 0;
}