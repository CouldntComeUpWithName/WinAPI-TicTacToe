#include<Windows.h>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<gdiplus.h>

#include"Game.h"
#include"Window.h"
#include"utilities.h"
#include"Output_Stream.h"
#include<gdiplus.h>
#include <objidl.h>

using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    switch (uMsg)
//    {
//    case WM_CLOSE:
//        if (MessageBoxW(hwnd, L"Really quit?", L"TIC-TAC", MB_OKCANCEL) == IDOK)
//        {
//            DestroyWindow(hwnd);
//        }
//        return 0;
//
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        return 0;
//
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hwnd, &ps);
//        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//        EndPaint(hwnd, &ps);
//    }
//    return 0;
//    }
//
//    return DefWindowProc(hwnd, uMsg, wParam, lParam);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR args, _In_ int nCmdShow)
{
    
    Game game(hInstance, nCmdShow);
    game.Run();

    //window.SetBGColor((HBRUSH)1);
    //PCWSTR name = L"Sample";

    //WNDCLASS wc = { };
    //wc.hInstance = hInstance;
    //wc.lpszClassName = name;
    //wc.lpfnWndProc = WindowProc;
    //wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);

    //if (!Register(&wc))
    //    return -1;

    //HWND window = Create(name, L"Hello", WS_OVERLAPPEDWINDOW | WS_BORDER, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, hInstance, nullptr);
    //
    ////SetWindowPos(window, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
   
    //CreateWindowA("static", "Hello World", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), window, NULL, NULL, NULL);
    //CreateWindowA("button", "Click on me", WS_VISIBLE | WS_CHILD | ES_CENTER, 0,0 , 100, 25, window, NULL, NULL, NULL);

    /*if (!window)
        return -1;*/

   /* ShowWindow(window.GetHandle(), nCmdShow);

    MSG msg = { 0 };
    while (GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }*/

    return 0;
}