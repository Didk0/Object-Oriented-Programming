// 
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Практически изпит
// 
// Име: Деян Цветков
// ФН: 45625
// Специалност: Информатика
// Курс: II
// Административна група: II 
// Ден, в който се явявате на изпита: 14.06.2021
// Начален час на изпита: 9:00
// Кой компилатор използвате: Visual C++
//

#define _CRT_SECURE_NO_WARNINGS 

#include <cassert>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const double PRICE_PER_CORE = 29.99;
const double PRICE_PER_GB = 89.99;

class Component
{
public:
	Component(const std::string& label = "")
		:m_label(label)
	{}
	virtual ~Component() = default;

	virtual double price() const = 0;
	virtual void output(std::ostream& out) const
	{
		out << "Component with name " << m_label;
	}

protected:
	std::string m_label;
};

class Cpu : public Component
{
public:
	Cpu(const std::string& label = "", unsigned short cores = 0, unsigned short clockSpeed = 0)
		: Component(label)
	{
		if (cores < 1 || cores > 8)
		{
			throw std::invalid_argument("Invalid cores number!");
		}

		m_cores = cores;
		m_clockSpeed = clockSpeed;
	}
	~Cpu() = default;

	virtual double price() const override
	{
		double result = m_cores * PRICE_PER_CORE;
		return result;
	}
	virtual void output(std::ostream& out) const
	{
		Component::output(out);
		out << " with price " << price();
	}

private:
	unsigned short m_cores;
	unsigned short m_clockSpeed;
};

class Memory : public Component
{
public:
	Memory(const std::string& label = "", unsigned short capacity = 0)
		: Component(label)
	{
		if (capacity < 1 || capacity > 10000)
		{
			throw std::invalid_argument("Invalid capacity size!");
		}

		m_capacity = capacity;
	}
	~Memory() = default;

	virtual double price() const override
	{
		double result = m_capacity * PRICE_PER_GB;
		return result;
	}
	virtual void output(std::ostream& out) const
	{
		Component::output(out);
		out << " with price " << price();
	}

private:
	unsigned short m_capacity;
};

Component* create_component()
{
	std::string ans;
	std::cout << "Choose a component to create (cpu/memory): " << std::endl;
	std::cin >> ans;

	if (ans == "cpu")
	{
		std::string label;
		unsigned short cores, clockSpeed;
		std::cout << "Enter label: " << std::endl;
		std::cin >> label;
		std::cout << "Enter number of cores: " << std::endl;
		std::cin >> cores;
		std::cout << "Enter clock speed: " << std::endl;
		std::cin >> clockSpeed;

		return new Cpu(label, cores, clockSpeed);
	}
	else if (ans == "memory")
	{
		std::string label;
		unsigned short capacity;
		std::cout << "Enter label: " << std::endl;
		std::cin >> label;
		std::cout << "Enter capacity: " << std::endl;
		std::cin >> capacity;

		return new Memory(label, capacity);
	}
	else
		return nullptr;
}

class Configuration
{
public:
	Configuration& operator=(const Configuration& other) = delete;
	Configuration(const Configuration& other) = delete;
	~Configuration()
	{
		for (size_t i = 0; i < size(); i++)
		{
			delete m_components[i];
			m_components[i] = nullptr;
		}
		m_components.clear();
	}

	double price() const
	{
		double result = 0;

		for (size_t i = 0; i < m_components.size(); i++)
		{
			if (!m_components[i])
				result += 0;
			else
				result += m_components[i]->price();
		}
		return result;
	}
	std::size_t size() const
	{
		return m_components.size();
	}

	const Component* operator[](size_t index) const
	{
		if (index < 0 || index > size() - 1)
		{
			throw std::out_of_range("Index out of range!");
		}

		return m_components[index];
	}
	Configuration& operator+=(const Component* obj)
	{
		insert(obj);
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Configuration& obj)
	{
		for (size_t i = 0; i < obj.size(); i++)
		{
			if (obj[i] != nullptr)
			{
				obj[i]->output(out);
				out << std::endl;
			}
		}
		out << obj.price();

		return out;
	}
	friend Configuration* create_configuration();

private:
	Configuration()
	{}
	void checkForSameComponents(const Component* comp)
	{

		for (size_t i = 0; i < size(); i++)
		{
			if (m_components[i] != nullptr && comp != nullptr && typeid(*m_components[i]) == typeid(*comp))
			{
				throw std::invalid_argument("A component of the same type already exists!");
			}
		}
	}
	void insert(const Component* comp)
	{
		checkForSameComponents(comp);

		m_components.push_back(comp);
	}

	std::vector<const Component*> m_components;
};

Configuration* create_configuration()
{
	Configuration* config = new Configuration();

	size_t count;
	std::cout << "Enter number of components to create: " << std::endl;
	std::cin >> count;

	for (size_t i = 0; i < count; i++)
	{
		try
		{
			Component* comp = create_component();
			config->operator+=(comp);
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << e.what() << std::endl;
			return nullptr;
		}
	}

	return config;
}

int main()
{
	try
	{
		Configuration* config = create_configuration();

		std::cout << *config << std::endl;

		std::string filePath;
		std::cout << std::endl << "Enter file path to save the data: " << std::endl;
		std::cin >> filePath;
		std::ofstream out(filePath);
		if (!out)
		{
			delete config;
			throw std::runtime_error("Couldn't open file for writing!");
		}

		out << *config;
		std::cout << "Successfully saved to file" << std::endl;

		out.close();

		delete config;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}