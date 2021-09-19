#pragma once
#include <iostream>
#include <cstring>
class MyString
{
public:
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	MyString(const char* str);
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	bool empty() const; // TODO
	size_t size() const;
	void clear();
	void push_back(char c);
	void pop_back();
	MyString& operator+=(char c);
	MyString& operator+=(const MyString& rhs);
	MyString operator+(char c) const;
	MyString operator+(const MyString& rhs) const;
	const char* c_str() const;
	bool operator==(const MyString& rhs) const;
	bool operator<(const MyString& rhs) const;
	inline char* getName() const { return m_str; }

private:
	void copy(const MyString& other);

	char* m_str;
	size_t m_size;
	size_t m_capacity;
};

