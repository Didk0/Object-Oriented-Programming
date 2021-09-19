#include "Document.h"

using std::getline;
using std::endl;
using std::cerr;

Document::Document()
	:m_currentFile("")
	, isOpenDoc(false)
	, isNewDoc(false)
{}

void Document::open(const std::string& path, Table& table)
{
	if (!m_currentFile.empty() || isNewDoc)
	{
		close();
	}

	m_in.open(path);
	if (!m_in)
	{
		throw std::invalid_argument("Couldn't load the document!");
	}

	isOpenDoc = true;
	m_currentFile = path;

	string toRead;
	size_t currRow = 0, currCol = 0;

	while (!m_in.eof())
	{
		getline(m_in, toRead);
		Proccessor::splitByComma(toRead, m_tokens);
		currRow++;
		for (size_t i = 0; i < m_tokens.size(); i++)
		{
			currCol = i + 1;
			if (m_tokens[i].empty())
				continue;

			if (Proccessor::isString(m_tokens[i]))
			{
				Proccessor::processString(m_tokens[i]);
				if (Proccessor::isInteger(m_tokens[i]))
					table.edit(new Integer(m_tokens[i]), currRow, currCol);
				else if (Proccessor::isDouble(m_tokens[i]))
					table.edit(new Double(m_tokens[i]), currRow, currCol);
				else if (Proccessor::isFormula(m_tokens[i]))
				{
					try
					{
						table.edit(new Formula(m_tokens[i], &table), currRow, currCol);
					}
					catch (const std::invalid_argument& e)
					{
						cerr << e.what() << endl;
					}
				}
				else
				{
					table.edit(new String(m_tokens[i]), currRow, currCol);
				}
			}
			else
			{
				if (Proccessor::isInteger(m_tokens[i]))
					table.edit(new Integer(m_tokens[i]), currRow, currCol);
				else if (Proccessor::isDouble(m_tokens[i]))
					table.edit(new Double(m_tokens[i]), currRow, currCol);
				else
				{
					isOpenDoc = false;
					string error = "Error: row " + std::to_string(currRow) + ", col " + std::to_string(currCol) + " ," + m_tokens[i] + " is unknown data type!";
					throw std::invalid_argument(error);
				}
			}

			Proccessor::updateFormulas(table);
		}
	}

	m_in.close();
}

void Document::close()
{
	if (!isOpenDoc && !isNewDoc)
	{
		throw std::invalid_argument("There is no loaded document!");
	}

	if (m_out.is_open() || m_in.is_open())
	{
		m_out.close();
		m_in.close();
	}
	m_currentFile.clear();
	isOpenDoc = false;
	isNewDoc = false;
}

void Document::newDoc()
{
	if (isOpenDoc || isNewDoc)
	{
		close();
	}
	isNewDoc = true;
	m_currentFile.clear();
}

void Document::save(Table& table)
{
	if (isNewDoc)
	{
		throw std::invalid_argument("There is no given file path!");
	}

	if (!isOpenDoc)
	{
		throw std::invalid_argument("There is no loaded document!");
	}

	m_out.open(m_currentFile);
	if (!m_out)
	{
		throw std::invalid_argument("Couldn't open file for writing!");
	}

	for (size_t i = 0; i < table.rowsCount(); i++)
	{
		for (size_t j = 0; j < table.colsCount(); j++)
		{
			if (!table.at(i, j))
			{
				if (j != table.colsCount() - 1)
					m_out << ", ";
				continue;
			}
			else if (!Proccessor::isInteger(table.at(i, j)->toString()) && !Proccessor::isDouble(table.at(i, j)->toString()))
				m_out << '"' << table.at(i, j)->toString() << '"';
			else
				m_out << table.at(i, j)->toString();

			if (j != table.colsCount() - 1)
				m_out << ", ";
		}
		if (i != table.rowsCount() - 1)
			m_out << std::endl;
	}

	m_out.close();
}

void Document::saveAs(const std::string& path, Table& table)
{
	if (!isNewDoc && !isOpenDoc)
	{
		throw std::invalid_argument("There is no loaded document!");
	}

	m_currentFile = path;

	m_out.open(path);
	if (!m_out)
	{
		throw std::invalid_argument("Couldn't open file for writing!");
	}

	for (size_t i = 0; i < table.rowsCount(); i++)
	{
		for (size_t j = 0; j < table.colsCount(); j++)
		{
			if (!table.at(i, j))
			{
				if (j != table.colsCount() - 1)
					m_out << ", ";
				continue;
			}
			else if (!Proccessor::isInteger(table.at(i, j)->toString()) && !Proccessor::isDouble(table.at(i, j)->toString()))
				m_out << '"' << table.at(i, j)->toString() << '"';
			else
				m_out << table.at(i, j)->toString();

			if (j != table.colsCount() - 1)
				m_out << ", ";
		}
		if (i != table.rowsCount() - 1)
			m_out << std::endl;
	}

	m_out.close();
}