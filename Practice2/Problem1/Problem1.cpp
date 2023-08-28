#include <iostream>
#include "Library.h"

int main()
{
    Library library;

    char title1[50] = "Harry Potter and the Philosopher's Stone";
    library.addBook(title1, "J.K. Rowling", 523);

    char title2[50] = "The Lord of the Rings";
    library.addBook(title1, "J.R.R. Tolkien", 128);

    library.removeBook(523);

    std::cout << library.m_booksCount << std::endl;

    for (size_t i = 0; i < library.m_booksCount; i++)
    {
        std::cout << library.m_books[i].m_title << ' ' << library.m_books[i].m_author << ' ' << library.m_books[i].m_ISBN << std::endl;
    }

    return 0;
}