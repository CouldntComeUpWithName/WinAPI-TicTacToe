#pragma once
#include<iostream>
#include<windows.h>
#include<sstream>

class Output {

private:
    HANDLE hConsole;

public:
    Output()
    {
        AllocConsole();
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    ~Output()
    {
        FreeConsole();
    }

    friend Output& operator<<(Output& output, std::wstring wstring);
    friend Output& operator<<(Output& output, const wchar_t* wcstring);
    friend Output& operator<<(Output& output, std::string string);
    
    template<typename T> 
    friend Output& operator<<(Output& output, T element);

};

template<typename T>
Output& operator<<(Output& output, T element)
{
#ifndef NDEBUG

    if (output.hConsole == INVALID_HANDLE_VALUE)
    {
        std::wcerr << L"Error getting console handle" << std::endl;
        return output;
    }

    std::wstringstream wstrstream;
    wstrstream << element;

    wchar_t character{};

    while (wstrstream.get(character))
    {
        DWORD charsWritten;
        if (!WriteConsole(output.hConsole, &character, 1, &charsWritten, nullptr))
        {
            std::wcerr << L"Error writing to console" << std::endl;
        }
    }

#endif
    return output;
}

extern Output winout;


