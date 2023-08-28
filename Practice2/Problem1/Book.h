#pragma once

const int MAX_NAME_LEN = 50;

struct Book
{
	char m_title[MAX_NAME_LEN];
	char m_author[MAX_NAME_LEN];
	size_t m_ISBN;
};