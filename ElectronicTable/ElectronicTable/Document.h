#pragma once
#include <fstream>
#include <string>
#include "Table.h"
#include "Integer.h"
#include "Double.h"
#include "String.h"
#include "Formula.h"
#include "Proccessor.h"

class Document
{
	using tokens = std::vector<string>;

public:
	Document();

	/// @brief sets isOpenDoc to true, sets m_currentFile to path, opens a file with a given path and fills the table from it
	/// @param path - path of the file
	/// @param table - Table to fill
	void open(const std::string& path, Table& table);

	/// @brief closes m_out and m_in
	void close();

	/// @brief sets m_currentFile to empty and sets isNewDoc to true
	void newDoc();

	/// @brief saves a given table to a file
	/// @param table - table to save to file if a path exists 
	void save(Table& table);

	/// @brief saves a given table to a file with a path
	/// @param path - path of the file
	/// @param table - table to save
	void saveAs(const std::string& path, Table& table);

	/// @brief getter for the current file
	/// @return the current file 
	inline const string& getFileName() const { return m_currentFile; };

	/// @brief checks if a document is loaded
	/// @return true if isOpenDoc is true and false - otherwise
	inline const bool isOpen() const { return isOpenDoc; };

	/// @brief checks if a new document is loaded
	/// @return true if isNewDoc is true and false - otherwise
	inline const bool isNew() const { return isNewDoc; };

private:
	string m_currentFile;
	std::ofstream m_out;
	std::ifstream m_in;
	tokens m_tokens;

	bool isOpenDoc;
	bool isNewDoc;
};

