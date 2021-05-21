#pragma once

#include "raylib.h"
#include <string>
#include <vector>

class DataFile
{
public:
	struct Record
	{
		Image image;
		std::string name;
		int age;
	};

private:

	int recordCount;
	std::vector<Record*> records;	// delete this vector. Load only the required record 


public:
	DataFile();
	~DataFile();

	void AddRecord(const std::string& imageFilename, const std::string& name, int age);
	Record* GetRecord(int index);

	int GetRecordCount() { return recordCount; };

	void Save(const std::string& filename);
	void Load(const std::string& filename);

private:
	void Clear();

};

