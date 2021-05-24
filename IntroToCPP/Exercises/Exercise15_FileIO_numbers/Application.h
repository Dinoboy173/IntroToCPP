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

	int num1 = 0;
	int num2 = 0;
	float num3 = 0;
	float num4 = 0;
	double num5 = 0;
	double num6 = 0;

private:
};