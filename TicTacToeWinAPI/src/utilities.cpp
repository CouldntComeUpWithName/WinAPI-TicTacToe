#include "utilities.h"

void PrintToConsole(const wchar_t* message)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        std::wcerr << L"Error getting console handle" << std::endl;
        return;
    }

    DWORD charsWritten;
    if (!WriteConsole(hConsole, message, lstrlen(message), &charsWritten, nullptr))
    {
        std::wcerr << L"Error writing to console" << std::endl;
    }
}

inline int WINAPI RedirectIOToConsole(){
    // Відображення консолі
    AllocConsole();

    // Встановлення файлового потоку, пов'язаного із стандартним потоком виведення C++

    std::wofstream out("CON");
    std::wstreambuf* coutBuffer = std::wcout.rdbuf();

    std::wcout.rdbuf(out.rdbuf());

    // Виведення тексту в консоль з використанням cout
    std::wcout << L"Hello, Console using cout!\n";

    // Здійснення повернення потоку виведення на його оригінальний буфер
    std::wcout.rdbuf(coutBuffer);
    
    return 0;
}