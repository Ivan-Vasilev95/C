// WindowsProject3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WindowsProject3.h"
#include <string>

#define MAX_LOADSTRING 100
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK Integer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK Integer1(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
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
    LoadStringW(hInstance, IDC_WINDOWSPROJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT3);
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
LRESULT CALLBACK Integer1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch (wParam) {
		case IDOK:case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
		return true;
		case IDC_BUTTON1:
		{
			/*BOOL *SLt = NULL;
			BOOL SIG = true;
			int a = GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
			int b = GetDlgItemInt(hDlg, IDC_EDIT2, SLt, SIG);
			int c = a + b;
			SetDlgItemInt(hDlg, IDC_EDIT3, c, true);*/
			TCHAR buff[100], *st;
			GetDlgItemText(hDlg, IDC_EDIT1, buff, sizeof(buff));
			long double a = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT2, buff, sizeof(buff));
			long double b = _tcstod(buff, &st);
			long double c = a + b;
			std::wstring s = std::to_wstring(c);
			SetDlgItemText(hDlg, IDC_EDIT3, s.c_str());


		}
		break;
		case IDC_BUTTON2:
		{
			TCHAR buff[100], *st;
			GetDlgItemText(hDlg, IDC_EDIT4, buff, sizeof(buff));
			long double a = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT5, buff, sizeof(buff));
			long double b = _tcstod(buff, &st);
			long double c = a - b;
			std::wstring s = std::to_wstring(c);
			SetDlgItemText(hDlg, IDC_EDIT6, s.c_str());
		}
		break;
		case IDC_BUTTON3:
		{
			TCHAR buff[100], *st;
			GetDlgItemText(hDlg, IDC_EDIT7, buff, sizeof(buff));
			long double a = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT8, buff, sizeof(buff));
			long double b = _tcstod(buff, &st);
			long double c = a * b;
			std::wstring s = std::to_wstring(c);
			SetDlgItemText(hDlg, IDC_EDIT9, s.c_str());
		}
		break;
		case IDC_BUTTON4:
		{
			TCHAR buff[100], *st;
			GetDlgItemText(hDlg, IDC_EDIT10, buff, sizeof(buff));
			long double a = _tcstod(buff, &st);
			GetDlgItemText(hDlg, IDC_EDIT11, buff, sizeof(buff));
			long double b = _tcstod(buff, &st);
			long double c;
			if (b == 0) {
				int res = MessageBox(hDlg, L"Error", L"Title", MB_OK | MB_ICONERROR);
			}
			else {
				c = a / b;
				std::wstring s = std::to_wstring(c);
				SetDlgItemText(hDlg, IDC_EDIT12, s.c_str());
			}
		}
			break;
		}
		break;
	}
	return false;
}
LRESULT CALLBACK Integer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch (wParam) 
		{
		case IDOK:case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
		return true;
		case IDC_BUTTON4:
		{
			BOOL *SLt = NULL;
			BOOL SIG = true;
			int a = GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
			int b = GetDlgItemInt(hDlg, IDC_EDIT2, SLt, SIG);
			int c = a + b;
			SetDlgItemInt(hDlg, IDC_EDIT3, c, true);


			int d= GetDlgItemInt(hDlg, IDC_EDIT4, SLt, SIG);
			int e = GetDlgItemInt(hDlg, IDC_EDIT5, SLt, SIG);
			int f = d * e;
			SetDlgItemInt(hDlg, IDC_EDIT6, f, true);


			int g = GetDlgItemInt(hDlg, IDC_EDIT7, SLt, SIG);
			int j = GetDlgItemInt(hDlg, IDC_EDIT8, SLt, SIG);
			int k;
			if (j == 0) {
				int res = MessageBox(hDlg, L"Error", L"Title", MB_OK | MB_ICONERROR);
			}
			else {
				 k = g / j;
				 SetDlgItemInt(hDlg, IDC_EDIT9, k, true);
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
			case ID_MENUEXAMP_ADD:
			{
				HMENU hMenu = GetMenu(hWnd);
				if (GetMenuState(hMenu, ID_MENUEXAMP_ADD + 1000,MF_BYCOMMAND) == -1) {//only one delete me button
					MENUITEMINFO mii; //menu item info
					ZeroMemory(&mii, sizeof(mii));
					mii.cbSize = sizeof(mii);
					mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
					mii.wID = ID_MENUEXAMP_ADD + 1000;
					mii.fType = MFT_STRING;
					mii.dwTypeData = (LPWSTR)"Delete me"; //VS 2017 defference
					mii.fState = MFS_ENABLED;
					InsertMenuItem(hMenu, ID_MENUEXAMP_ADD, FALSE, &mii);
				}
			}
			break;
			case ID_MENUEXAMP_ADD+1000:
			{
				HMENU hMenu = GetMenu(hWnd);
				DeleteMenu(hMenu, ID_MENUEXAMP_ADD + 1000, MF_BYCOMMAND);
			}
			break;
			case ID_MENUEXAMP_ENABLE:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_MENUEXAMP_DISABLE, MF_BYCOMMAND);
				if (res == MF_DISABLED) {
					EnableMenuItem(hMenu, ID_MENUEXAMP_DISABLE, MF_ENABLED);
				}
			}
			break;
			case ID_MENUEXAMP_DISABLE:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_MENUEXAMP_DISABLE, MF_BYCOMMAND);
				if (res == MF_ENABLED) {
					EnableMenuItem(hMenu, ID_MENUEXAMP_DISABLE, MF_DISABLED);
				}
			}
			break;
			case ID_MENUEXAMP_CHECK:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_MENUEXAMP_CHECK, MF_BYCOMMAND);
				if (res == MF_CHECKED) {
					CheckMenuItem(hMenu, ID_MENUEXAMP_CHECK, MF_UNCHECKED);
				}
				else if (res == MF_UNCHECKED) {
					CheckMenuItem(hMenu, ID_MENUEXAMP_CHECK, MF_CHECKED);
				}
			}
			break;
			case ID_LAB4_INTEGER:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd,(DLGPROC)Integer);
			}
			break;
			case ID_LAB5_REAL:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG2, hWnd, (DLGPROC)Integer1);
			}
			break;
			case ID_POP_OPEN32777:
			{
				int res = MessageBox(hWnd, L"message", L"Title", MB_YESNOCANCEL|MB_ICONINFORMATION);
				if (res == IDYES) {
					res = MessageBox(hWnd, L"Error", L"Title", MB_OK | MB_ICONERROR);
				}
				else if (res == IDNO) {
					res = MessageBox(hWnd, L"Question", L"Title", MB_OK | MB_ICONQUESTION);
				}
				else if (res == IDCANCEL) {
					res = MessageBox(hWnd, L"Warning", L"Title", MB_OK | MB_ICONWARNING);
				}
			}
			break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_RBUTTONDOWN:
	{
		HMENU hMenu = LoadMenu(hInst, (LPCWSTR)IDR_MENU1);
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		POINT pt = { LOWORD(lParam),HIWORD(lParam) };
		ClientToScreen(hWnd, &pt);
		TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
		DestroyMenu(hMenu);
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
