#pragma once

class Application
{
public:

	Application();
	~Application();

	void Run();

	void SaveToFile(const char* filename);
	void LoadFromFile(const char* filename);

protected:

	static const int NUMBERS_COUNT = 10;
	int m_numbers[NUMBERS_COUNT];

private:

};
