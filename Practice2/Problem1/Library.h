#pragma once
#include "Book.h"
#include <cstring>
#include <iostream>

const int MAX_BOOKS = 1000;

struct Library
{
	void addBook(char title[], const char author[], size_t ISBN);
	void removeBook(size_t ISBN);

	size_t m_booksCount = 0;
	Book m_books[MAX_BOOKS];
};