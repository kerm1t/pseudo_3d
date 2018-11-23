// tempo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "tempo.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TEMPO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEMPO));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEMPO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEMPO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//    wcex.cbSize = 400;

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0,
     356, // width
     320, // height
     nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void loopy(HDC hdc)
{
  COLORREF sky     = RGB(34, 141, 203);
  COLORREF ground  = RGB(0, 197, 0);
  COLORREF road    = RGB(142, 140, 142);
  COLORREF marker1 = RGB(255, 46, 0);
  COLORREF marker2 = RGB(255, 255, 255);

  RECT r = { 10,10,10+320,10+120 };
  HBRUSH brush = CreateSolidBrush(sky);
  FillRect(hdc, &r, brush);

  r = { 10,10+120,10 + 320,10 + 240 };
  brush = CreateSolidBrush(ground);
  FillRect(hdc, &r, brush);

  // road
  brush = CreateSolidBrush(road);
  SelectObject(hdc, brush);
  HPEN hGray = CreatePen(PS_SOLID, 1, road);
  SelectObject(hdc, hGray);
  POINT apt[4] = { { 10,10 + 240 },{ 10 + 160 - 20,10 + 120 },{ 10 + 160 + 20,10 + 120 } ,{ 10 + 320,10 + 240 } };
  Polygon(hdc, apt, 4);

  // marker red
  HPEN hRed = CreatePen(PS_SOLID, 4, marker1);
  SelectObject(hdc, hRed);
  apt[0] = { 10,10 + 240 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc,apt,2);
  apt[0] = { 10+320,10 + 240 };
  apt[1] = { 10+160+20,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10,10 + 235 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 320,10 + 235 };
  apt[1] = { 10 + 160 + 20,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10,10 + 230 };
  apt[1] = { 10 + 160 - 20, 10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 320,10 + 230 };
  apt[1] = { 10 + 160 + 20,10 + 120 };
  Polyline(hdc, apt, 2);


  // marker white
  HPEN hWhite = CreatePen(PS_SOLID, 4, marker2);
  SelectObject(hdc, hWhite);
  apt[0] = { 10 + 160 - 60,10 + 240 };
  apt[1] = { 10 + 160 - 10,10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 160+60,10 + 240 };
  apt[1] = { 10 + 160 + 10,10 + 120 };
  Polyline(hdc, apt, 2);

  apt[0] = { 10 + 160 - 55,10 + 240 };
  apt[1] = { 10 + 160 - 10,10 + 120 };
  Polyline(hdc, apt, 2);
  apt[0] = { 10 + 160 + 55,10 + 240 };
  apt[1] = { 10 + 160 + 10,10 + 120 };
  Polyline(hdc, apt, 2);

  SetBkColor(hdc, sky);
  TextOutA(hdc, 30, 30, "Pseudo 3D cheated", 17);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            
            loopy(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
