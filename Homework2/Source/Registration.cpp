#include "Registration.h"

Registration::Registration(const string& str)
{
	if (!isValid(str))
	{
		throw std::invalid_argument("Invalid registration number!");
	}
	m_number = str;
}

bool Registration::operator==(const Registration& other) const
{
	return m_number == other.m_number;
}

bool Registration::isValid(const string& str)
{
	if (str.size() > 8)
	{
		return false;
	}

	if (std::isalpha(str[0]))
	{
		if (isalpha(str[1]))
		{
			if (isdigit(str[2]) && isdigit(str[3]) && isdigit(str[4]) && isdigit(str[5]))
			{
				if (isalpha(str[6]) && isalpha(str[7]))
				{
					return true;
				}
				else return false;
			}
			else return false;
		}
		else if (isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]) && isdigit(str[4]))
		{
			if (isalpha(str[5]) && isalpha(str[6]))
			{
				return true;
			}
			else return false;
		}
		else return false;
	}

	return false;
}

istream& operator>>(istream& in, Registration& obj)
{
	in >> obj.m_number;
	return in;
}
