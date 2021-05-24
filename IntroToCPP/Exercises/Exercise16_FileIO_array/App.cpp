#include "Application.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

Application::Application()
{

}
Application::~Application()
{

}

void Application::Run()
{
    const char* filename = "data.dat";

    srand(time(0)); // fix

    for (int i = 0; i < NUMBERS_COUNT; i++)
        m_numbers[i] = rand() % 100;

    // save the above numbers to file
    SaveToFile(filename);

    // reset the numbers
    for (int i = 0; i < NUMBERS_COUNT; i++)
        m_numbers[i] = 0;

    LoadFromFile(filename);

    // print to console
    for (int i = 0; i < NUMBERS_COUNT; i++)
        std::cout << m_numbers[i] << std::endl;
}

void Application::SaveToFile(const char* filename)
{
    // TODO: write your code here
    std::fstream file;
    file.open(filename, std::ios_base::out | std::ios_base::binary);

    if (file.is_open())
    {
        file.write((char*)&m_numbers, sizeof(int) * NUMBERS_COUNT);

        file.close();
    }
}

void Application::LoadFromFile(const char* filename)
{
    // TODO: write your code here
    std::fstream file;
    file.open(filename, std::ios_base::in | std::ios_base::binary);

    if (file.is_open())
    {
        file.read((char*)&m_numbers, sizeof(int) * NUMBERS_COUNT);

        file.close();
    }
}