#pragma once

#include "raylib.h"
#include <string>
#include <vector>

class DataFile
{
public:
	struct Record // the Record
	{
		Image image; // holds the records image
		std::string name; // holds the records name
		int age; // holds the records age
	};

private:

	int recordCount; // initial variable for the recordCount

	Record* currentRecord = nullptr; // initial variable for the currentRecord is set to nullptr

	std::string filename = "npc_data.dat"; // the filename


public:
	DataFile(); //-------------------------------------------------------------------------- functions in DataFile.cpp
	~DataFile();

	void AddRecord(const std::string& imageFilename, const std::string& name, int age);
	Record* GetRecord(int index);

	int GetRecordCount() { return recordCount; };

	void Save(const std::string& filename);
	void Load(const std::string& filename);

private:
	void Clear(); //------------------------------------------------------------------------ 

};

