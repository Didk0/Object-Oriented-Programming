#pragma once
#include "Vehicle.h"
#include <iostream>

class Garage
{
public:
	Garage(size_t size);
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();
	Garage(Garage&& other) noexcept;
	Garage& operator=(Garage&& other) noexcept;

	void insert(Vehicle& v);
	void erase(const char* registration);
	const Vehicle& at(std::size_t pos) const;
	const Vehicle& operator[](std::size_t pos) const;
	bool empty() const;
	size_t size() const;
	void clear();
	const Vehicle* find(const char* registration) const;

private:
	void copy(const Garage& other);

	size_t m_reserved;
	size_t m_size;
	size_t m_count;
	const Vehicle** m_vehicles = nullptr;
};

