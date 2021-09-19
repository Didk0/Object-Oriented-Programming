#include "Garage.h"

Garage::Garage(size_t size)
	: m_size(size)
	, m_reserved(0)
	, m_count(0)
	, m_vehicles(new const Vehicle* [size])
{
	if (m_size <= 0)
	{
		throw std::invalid_argument("Invalid argument!");
	}
}

Garage::Garage(const Garage& other)
{
	copy(other);
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other)
	{
		delete[] m_vehicles;
		m_vehicles = nullptr;
		copy(other);
	}
	return *this;
}

Garage::~Garage()
{
	m_reserved = 0;
	m_size = 0;
	m_count = 0;
	delete[] m_vehicles;
}

Garage::Garage(Garage&& other) noexcept
{
	m_reserved = other.m_reserved;
	m_size = other.m_size;
	m_count = other.m_count;
	delete[] m_vehicles;
	m_vehicles = other.m_vehicles;
	other.m_reserved = 0;
	other.m_size = 0;
	other.m_count = 0;
	other.m_vehicles = nullptr;
}

Garage& Garage::operator=(Garage&& other) noexcept
{
	if (this != &other)
	{
		m_reserved = other.m_reserved;
		m_size = other.m_size;
		m_count = other.m_count;
		delete[] m_vehicles;
		m_vehicles = other.m_vehicles;
		other.m_reserved = 0;
		other.m_size = 0;
		other.m_count = 0;
		other.m_vehicles = nullptr;
	}

	return *this;
}

void Garage::insert(Vehicle& v)
{
	if (v.space() > m_size - m_reserved)
	{
		throw std::invalid_argument("Not enough free space!");
	}
	for (size_t i = 0; i < m_count; i++)
	{
		if (m_vehicles[i] != nullptr)
		{
			if (strcmp(m_vehicles[i]->registration(), v.registration()) == 0)
			{
				throw std::invalid_argument("Car with the same registration is in the garage!");
			}
		}
	}

	m_reserved += v.space();
	m_vehicles[m_count++] = &v;
}

void Garage::erase(const char* registration)
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (strcmp(m_vehicles[i]->registration(), registration) == 0)
		{
			m_vehicles[i] = m_vehicles[m_count - 1];
			m_vehicles[m_count - 1] = nullptr;
			m_count--;
			return;
		}
	}
}

const Vehicle& Garage::at(size_t pos) const
{
	if (pos < m_count)
	{
		return *m_vehicles[pos];
	}
	else
	{
		throw std::out_of_range("Index out of range!");
	}
}

const Vehicle& Garage::operator[](size_t pos) const
{
	return *m_vehicles[pos];
}

bool Garage::empty() const
{
	return m_count == 0;
}

size_t Garage::size() const
{
	return m_count;
}

void Garage::copy(const Garage& other)
{
	try
	{
		m_vehicles = new const Vehicle * [other.m_count];
	}
	catch (const std::bad_alloc& e)
	{
		m_vehicles = nullptr;
		throw e;
	}
	for (size_t i = 0; i < other.m_count; i++)
	{
		m_vehicles[i] = other.m_vehicles[i];
	}
	m_count = other.m_count;
	m_size = other.m_size;
	m_reserved = other.m_reserved;
}

void Garage::clear()
{
	m_reserved = 0;
	for (size_t i = 0; i < m_count; i++)
	{
		m_vehicles[i] = nullptr;
	}
	m_count = 0;
}

const Vehicle* Garage::find(const char* registration) const
{
	for (size_t i = 0; i < m_count; i++)
	{
		if (strcmp(m_vehicles[i]->registration(), registration) == 0)
		{
			return m_vehicles[i];
		}
	}

	return nullptr;
}