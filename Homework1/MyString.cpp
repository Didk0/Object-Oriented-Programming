#include "MyString.h"

const int DEFAULT_CAPACITY = 1;

MyString::MyString()
	: m_size(0)
	, m_capacity(DEFAULT_CAPACITY)
	, m_str(new char[DEFAULT_CAPACITY])
{
	m_str[0] = '\0';
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[] m_str;
		m_str = nullptr;
		copy(other);
	}
	return *this;
}

MyString::~MyString()
{
	delete[] m_str;
	m_str = nullptr;
}

MyString::MyString(MyString&& other) noexcept
{
	delete[] m_str;
	m_str = other.m_str;
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_str = nullptr;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		delete[] m_str;
		m_str = nullptr;
		m_str = other.m_str;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		other.m_size = 0;
		other.m_capacity = 0;
		other.m_str = nullptr;
	}

	return *this;
}

MyString::MyString(const char* str)
{
	if (!str)
	{
		throw std::invalid_argument("Invalid argument!");
	}
	size_t len = strlen(str);
	m_str = new char[len + 1];
	strcpy(m_str, str);
	m_size = len;
	m_capacity = len;
}

char& MyString::at(size_t pos)
{
	if (pos >= m_size)
	{
		throw std::out_of_range("Index out of range!");
	}

	return m_str[pos];
}

const char& MyString::at(size_t pos) const
{
	if (pos >= m_size)
	{
		throw std::out_of_range("Index out of range!");
	}

	return m_str[pos];
}

char& MyString::operator[](size_t pos)
{
	return at(pos);
}

const char& MyString::operator[](size_t pos) const
{
	return m_str[pos];
}

char& MyString::front()
{
	return m_str[0];
}

const char& MyString::front() const
{
	return m_str[0];
}

char& MyString::back()
{
	return m_str[m_size - 1];
}

const char& MyString::back() const
{
	return m_str[m_size - 1];
}

bool MyString::empty() const
{
	return m_size == 0;
}

size_t MyString::size() const
{
	return m_size;
}

void MyString::clear()
{
	m_size = 0;
	m_capacity = DEFAULT_CAPACITY;
	m_str[0] = '\0';
}

void MyString::push_back(char c)
{
	if (m_size + 1 >= m_capacity)
	{
		char* newStr = new char[m_capacity * 2];
		strcpy(newStr, m_str);
		m_capacity *= 2;

		newStr[m_size] = c;
		newStr[m_size + 1] = '\0';

		delete[] m_str;
		m_str = newStr;
	}
	else
	{
		m_str[m_size] = c;
		m_str[m_size + 1] = '\0';
	}
	m_size++;
}

void MyString::pop_back()
{
	m_str[m_size - 1] = '\0';
	m_size--;
}

MyString& MyString::operator+=(char c)
{
	push_back(c);
	return *this;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	for (size_t i = 0; i < rhs.m_size; i++)
	{
		push_back(rhs[i]);
	}
	return *this;
}

MyString MyString::operator+(char c) const
{
	return MyString(*this) += c;
}

MyString MyString::operator+(const MyString& rhs) const
{
	return MyString(*this) += rhs;
}

const char* MyString::c_str() const
{
	return m_str;
}

bool MyString::operator==(const MyString& rhs) const
{
	return strcmp(m_str, rhs.m_str) == 0;
}

bool MyString::operator<(const MyString& rhs) const
{
	return strcmp(m_str, rhs.m_str) < 0;
}

void MyString::copy(const MyString& other)
{
	try
	{
		m_str = new char[other.m_size + 1];
	}
	catch (const std::bad_alloc& e)
	{
		m_str = nullptr;
		throw e;
	}
	strcpy(m_str, other.m_str);
	m_size = other.m_size;
	m_capacity = other.m_capacity;
}

