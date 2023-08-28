#include "Library.h"

bool isLowerCase(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void toUpper(char*& str)
{
	while (*str)
	{
		if (isLowerCase(*str))
		{
			*str -= 'a' - 'A';
		}
		++str;
	}
}

void Library::addBook(char title[], const char author[], size_t ISBN)
{
	if (m_booksCount + 1 <= MAX_BOOKS)
	{
		toUpper(title);

		strcpy(m_books[m_booksCount].m_title, title);
		strcpy(m_books[m_booksCount].m_author, author);
		m_books[m_booksCount].m_ISBN = ISBN;

		++m_booksCount;
	}
}

void Library::removeBook(size_t ISBN)
{
	for (size_t i = 0; i < m_booksCount; i++)
	{
		if (m_books[i].m_ISBN == ISBN)
		{
			std::swap(m_books[i], m_books[m_booksCount - 1]);
			--m_booksCount;
			--i;
		}
	}
}
