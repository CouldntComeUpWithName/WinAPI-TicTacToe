#include "Output_Stream.h"

Output& operator<<(Output& output, std::string string)
{
    if (output.hConsole == INVALID_HANDLE_VALUE)
    {
        std::wcerr << L"Error getting console handle" << std::endl;
        return output;
    }

    DWORD charsWritten;
    if (!WriteConsole(output.hConsole, string.c_str(), static_cast<DWORD>(string.length()), &charsWritten, nullptr))
    {
        std::wcerr << L"Error writing to console" << std::endl;
    }

    return output;
}

Output& operator<<(Output& output, std::wstring wstring)
{
    if (output.hConsole == INVALID_HANDLE_VALUE)
    {
        return output;
    }

    DWORD charsWritten;
    if (!WriteConsole(output.hConsole, wstring.c_str(), static_cast<DWORD>(wstring.length()), &charsWritten, nullptr))
    {
        std::wcerr << L"Error writing to console" << std::endl;
    }

    return output;
}


Output& operator<<(Output& output, const wchar_t* wcstring)
{
    if (output.hConsole == INVALID_HANDLE_VALUE)
    {
        std::wstring exceptionStr = L"Error getting console handle. Line: ";
        exceptionStr += std::to_wstring(__LINE__);
        throw exceptionStr;
        
        //std::wcerr << L"Error getting console handle" << std::endl;
        return output;
    }

    if (!WriteConsole(output.hConsole, wcstring, lstrlen(wcstring), nullptr, nullptr))
    {
        std::wcerr << L"Error writing to console" << std::endl;
    }
    return output;
}

Output winout;
