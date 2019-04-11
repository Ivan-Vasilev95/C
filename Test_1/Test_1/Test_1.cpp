// Test_1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Test_1.h"
#include <string>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK Integer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
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
    LoadStringW(hInstance, IDC_TEST1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST1));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEST1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK Integer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return true;
		case IDC_BUTTON1:
		{
			TCHAR buff[100], *st;
			GetDlgItemText(hDlg, IDC_EDIT4, buff, sizeof(buff));
			long double a = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT5, buff, sizeof(buff));
			long double b = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT6, buff, sizeof(buff));
			long double c = _tcstod(buff, &st);
			if (a - c == 0) {
				MessageBox(hDlg, L"a-c=0", L"Error", MB_OK | MB_ICONERROR);
			}
			else {
				long double y = b/(a-c)+sqrt(c);
				std::wstring s = std::to_wstring(y);
				LPCTSTR str = s.c_str();
				MessageBox(hDlg, str, L"Result", MB_OK | MB_ICONINFORMATION);
			}
		}
		break;
		case IDC_BUTTON2:
		{
			BOOL *SLt = NULL;
			BOOL SIG = true;
			int a = GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
			int b = GetDlgItemInt(hDlg, IDC_EDIT2, SLt, SIG);
			if (b == 0) {
				MessageBox(hDlg, L"Cant devide by 0", L"ERROR", MB_OK | MB_ICONERROR);
			}
			else {
				int c = a / b;
				SetDlgItemInt(hDlg, IDC_EDIT3, c, true);
			}
		}
		break;
		}
		break;
	}
	return false;
}
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
			break;
			case ID_TEST1_ADDOPEN:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_TEST1_CHECK32774, MF_BYCOMMAND);
				if (res == MF_CHECKED) {
					if (GetMenuState(hMenu, ID_TEST1_ADDOPEN + 1000, MF_BYCOMMAND) == -1) {//only one delete me button
						MENUITEMINFO mii; //menu item info
						ZeroMemory(&mii, sizeof(mii));
						mii.cbSize = sizeof(mii);
						mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
						mii.wID = ID_TEST1_ADDOPEN + 1000;
						mii.fType = MFT_STRING;
						mii.dwTypeData = (LPWSTR)"Delete me"; //VS 2017 defference
						mii.fState = MFS_ENABLED;
						InsertMenuItem(hMenu, ID_TEST1_ADDOPEN, FALSE, &mii);
					}
				}
					else if(res==MF_UNCHECKED){
						int v=MessageBox(hWnd, L"Select Check", L"MessageBox", MB_YESNO | MB_ICONQUESTION);
						if (v == IDYES) {
							CheckMenuItem(hMenu, ID_TEST1_CHECK32774, MF_CHECKED);
							MessageBox(hWnd, L"Checked", L"MessageBox", MB_OK | MB_ICONQUESTION);
						}
					}
			}
			break;
			case ID_TEST1_ADDOPEN + 1000:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)Integer);
			}
			case ID_TEST1_CHECK32774:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_TEST1_CHECK32774, MF_BYCOMMAND);
				if (res == MF_CHECKED) {
					CheckMenuItem(hMenu, ID_TEST1_CHECK32774, MF_UNCHECKED);
				}
				else if (res == MF_UNCHECKED) {
					CheckMenuItem(hMenu, ID_TEST1_CHECK32774, MF_CHECKED);
				}
			}
			break;
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
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
