#pragma once
#include <iostream>
#include <cstring>
#include <exception>

using std::string;
using std::istream;
using std::ostream;

class Registration
{
	public:
		Registration(const string& str);

		Registration& operator=(const Registration& other)
		{
			if (!isValid(other.m_number))
			{
				throw std::exception("Invalid registration number!");
			}

			if (this != &other)
			{
				m_number = other.toString();
			}

			return *this;
		}

		bool operator==(const Registration& other) const;		

		inline const string& toString() const{ return m_number;	}

		friend istream& operator>>(istream& in, Registration& obj);

	private:
		bool isValid(const string& str);

		string m_number;
};

