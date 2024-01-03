#pragma once
#include<iostream>
#include<fstream>
#include<windows.h>

void PrintToConsole(const wchar_t* message);

inline int WINAPI RedirectIOToConsole();
//
//class Window 
//{
//public:
//    Window(const wchar_t* className, HINSTANCE hInstance)
//        : className(className), hInstance(hInstance), hWnd(nullptr) {
//        this->Register();
//        this->Create();
//    }
//
//     Конструктор переміщення
//    Window(Window&& other) noexcept
//        : className(other.className), hInstance(other.hInstance), hWnd(other.hWnd) {
//        other.hWnd = nullptr; // Обов'язково нулюємо вказівник, щоб інший об'єкт не знищив вікно
//    }
//
//     Оператор переміщення
//    Window& operator=(Window&& other) noexcept {
//        if (this != &other) {
//            Unregister();
//            Destroy();
//
//            className = other.className;
//            hInstance = other.hInstance;
//            hWnd = other.hWnd;
//
//            other.hWnd = nullptr; // Обов'язково нулюємо вказівник, щоб інший об'єкт не знищив вікно
//        }
//        return *this;
//    }
//
//    ~Window() {
//        Unregister();
//        Destroy();
//    }
//
//     Інші методи класу...
//
//private:
//    const wchar_t* className;
//    HINSTANCE hInstance;
//    HWND hWnd;
//
//     Реєстрація класу вікна
//    void Register() {
//        WNDCLASS wc = { 0 };
//        wc.lpfnWndProc = DefWindowProc;
//        wc.hInstance = hInstance;
//        wc.lpszClassName = className;
//
//        if (RegisterClass(&wc) == 0) {
//            std::cerr << "Failed to register window class." << std::endl;
//        }
//    }
//
//     Створення вікна
//    void Create() {
//        hWnd = CreateWindowEx(
//            0, className, L"Window", WS_OVERLAPPEDWINDOW,
//            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//            nullptr, nullptr, hInstance, nullptr
//        );
//
//        if (hWnd == nullptr) {
//            std::cerr << "Failed to create window." << std::endl;
//        }
//    }
//
//     Відміна реєстрації класу
//    void Unregister() {
//        if (className != nullptr) {
//            UnregisterClass(className, hInstance);
//        }
//    }
//
//    Знищення вікна
//    void Destroy() {
//        if (hWnd != nullptr) {
//            DestroyWindow(hWnd);
//            hWnd = nullptr;
//        }
//    }
//};

template<typename T>
void RedirectIOToConsole(const T& character)
{
    std::wofstream out("CON");
    std::wstreambuf* coutBuffer = std::wcout.rdbuf(out.rdbuf());

    // Виведення тексту в консоль з використанням cout
    std::wcout << character << std::endl;

    // Здійснення повернення потоку виведення на його оригінальний буфер
    std::wcout.rdbuf(coutBuffer);
}

