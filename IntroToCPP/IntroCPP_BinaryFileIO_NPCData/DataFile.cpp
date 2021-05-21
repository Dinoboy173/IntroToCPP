#include "DataFile.h"
#include <fstream>

DataFile::DataFile()
{
	recordCount = 0; // tracks current record
}

DataFile::~DataFile()
{
	
}

void DataFile::AddRecord(const std::string& imageFilename, const std::string& name, int age)
{
	//Image i = LoadImage(imageFilename.c_str()); // loads new image being added to record
	//
	//Record* r = new Record(); // creates new Record
	//r->image = i; // variable name for image
	//r->name = name; // variable name for name
	//r->age = age; // variable name for age
}

DataFile::Record* DataFile::GetRecord(int index)
{
	std::ifstream infile(filename, std::ios::binary); // opens file

	recordCount = 0; // sets current record to start
	infile.read((char*)&recordCount, sizeof(int)); // gets amount of records

	int nameSize = 0;  //---- sets initial variables and values
	int ageSize = 0;
	int width = 0;
	int height = 0;
	int format = 0;
	int imageSize = 0; //---- 

	if (index < recordCount) // checks if the record index being asked for is in the record list
	{
		for (int i = 0; i < recordCount; i++)
		{
			infile.read((char*)&width, sizeof(int)); // gets image width
			infile.read((char*)&height, sizeof(int)); // gets image height

			imageSize = sizeof(Color) * width * height; // calculates size of the image

			infile.read((char*)&nameSize, sizeof(int)); // gets size of name
			infile.read((char*)&ageSize, sizeof(int)); // gets size of age

			if (i == index) // checks if loading record or not
			{
				break;
			}

			int skipSize = imageSize + nameSize + ageSize; // adds image size, name size, and age size together into a variable

			infile.seekg(skipSize, std::ios::cur); // skips loading the image, name, and age
		}
	}

	char* imgdata = new char[imageSize]; // creates variable to hold the information of the image
	infile.read(imgdata, imageSize); // puts the information of the image into the imgdata variable

	Image img = LoadImageEx((Color*)imgdata, width, height); // loads the information of the image into an Image

	char* name = new char[nameSize + 1];		// creates a variable to hold the name
	int age = 0;									 // create a variable to hold the age

	for (int i = 0; i < nameSize + 1; i++)
	{
		name[i] = '\0';								 // sets the random characters that will be used in the name variable to null termination character
	}

	infile.read((char*)name, nameSize); // puts the name into the name variable
	infile.read((char*)&age, ageSize); // puts the age into the age variable

	if (currentRecord == nullptr) // checks if there is a record already created
	{
		currentRecord = new Record; // creates new Record
	}

	currentRecord->image = img; // puts the image into the Record
	currentRecord->name = std::string(name); // puts the name into the Record
	currentRecord->age = age; // puts the age into the Record

	delete[] imgdata; // deletes the imgdata
	delete[] name; // deletes the name

	infile.close(); // closes the file

	return currentRecord; //returns the record to what called this function
}

void DataFile::Save(const std::string& filename)
{
	//	std::ofstream outfile(filename, std::ios::binary);
	//
	//	int recordCount = records.size();
	//	outfile.write((char*)&recordCount, sizeof(int));
	//
	//	for (int i = 0; i < recordCount; i++)
	//	{		
	//		Color* imgdata = GetImageData(records[i]->image);
	//				
	//		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
	//		int nameSize = records[i]->name.length();
	//		int ageSize = sizeof(int);
	//
	//		outfile.write((char*)&records[i]->image.width, sizeof(int));
	//		outfile.write((char*)&records[i]->image.height, sizeof(int));
	//		
	//		outfile.write((char*)&nameSize, sizeof(int));
	//		outfile.write((char*)&ageSize, sizeof(int));
	//
	//		outfile.write((char*)imgdata, imageSize);
	//		outfile.write((char*)records[i]->name.c_str(), nameSize);
	//		outfile.write((char*)&records[i]->age, ageSize);
	//	}
	//
	//	outfile.close();
}

void DataFile::Load(const std::string& filename)
{
	this->filename = filename; // parses the filename to be used across this file
}

void DataFile::Clear()
{
	//	for (int i = 0; i < records.size(); i++)
    //	{
    //		delete records[i];
    //	}
    //	records.clear();
    //	recordCount = 0;
}