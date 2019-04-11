// Test_2_D.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Test_2_D.h"
#include <string>
#include <CommCtrl.h>

#define MAX_LOADSTRING 100
#define TIMER1 500

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK test(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
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
    LoadStringW(hInstance, IDC_TEST2D, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST2D));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST2D));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEST2D);
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

LRESULT CALLBACK test(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_TIMER:
	{
		int pos = SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0);
		if (pos < 100) {
			int test = rand() % 100;
			std::wstring s9 = std::to_wstring(test);
			LPCTSTR str9 = s9.c_str();
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)str9);
			pos++;
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, pos, 0);
		}
		else {
			KillTimer(hDlg, TIMER1);
		}
	}
	break;
	case WM_COMMAND:
		switch (wParam) {
		case IDOK:case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return true;
		case IDC_BUTTON1:
		{
			BOOL *SLt = NULL;
			BOOL SIG = true;

			int index = GetDlgItemInt(hDlg, IDC_COMBO1, SLt, SIG);
			if (IsDlgButtonChecked(hDlg, IDC_CHECK1)&&!IsDlgButtonChecked(hDlg,IDC_CHECK2)) {
				int A= GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
				int rezult = index + A;
				std::wstring s9 = std::to_wstring(rezult);
				LPCTSTR str9 = s9.c_str();
				MessageBox(hDlg, str9, L"Result", MB_OK | MB_ICONINFORMATION);
			}
			else if (!IsDlgButtonChecked(hDlg, IDC_CHECK1) && IsDlgButtonChecked(hDlg, IDC_CHECK2)) {
				int B= GetDlgItemInt(hDlg, IDC_EDIT2, SLt, SIG);
				if (B == 0) {
					MessageBox(hDlg, L"Cant devide by 0", L"0", MB_OK | MB_ICONINFORMATION);
				}
				else {
					int rezult = index / B;
					std::wstring s9 = std::to_wstring(rezult);
					LPCTSTR str9 = s9.c_str();
					MessageBox(hDlg, str9, L"Result", MB_OK | MB_ICONINFORMATION);
				}
			}
			else if (IsDlgButtonChecked(hDlg, IDC_CHECK1) && IsDlgButtonChecked(hDlg, IDC_CHECK2)) {
				int A = GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
				int B = GetDlgItemInt(hDlg, IDC_EDIT2, SLt, SIG);
				if (B == 0) {
					MessageBox(hDlg, L"Cant devide by 0", L"0", MB_OK | MB_ICONINFORMATION);
				}
				else {
					A /= B;
					int rezult = index + A;
					std::wstring s9 = std::to_wstring(rezult);
					LPCTSTR str9 = s9.c_str();
					MessageBox(hDlg, str9, L"Result", MB_OK | MB_ICONINFORMATION);
				}
			}

		}
		break;
		case IDC_BUTTON2:
		{
			SetTimer(hDlg, TIMER1, 1, NULL);
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 0, 0);
		}
		break;
		case IDC_BUTTON3:
		{
			int index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCURSEL, 0, 0);
			if (index >= 0) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_DELETESTRING, index, 0);
			}
			else {
				MessageBox(hDlg, L"Select Item", L"Error", MB_OK | MB_ICONINFORMATION);
			}
		}
		break;
		}
		break;
	}
	return false;

}
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
			case ID_TEST2_OPEN:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)test);
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
    case WM_PAINT:
        {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 255, 0));
		SelectObject(hdc, hBrush1);
		Rectangle(hdc, 210, 30, 270, 60);

		HBITMAP hBmp1 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP1);
		POINT pp[3];
		hBrush1 = CreatePatternBrush(hBmp1);
		SelectObject(hdc, hBrush1);
		pp[0].x = 240; pp[0].y = 60;
		pp[1].x = 210; pp[1].y = 130;
		pp[2].x = 270; pp[2].y = 130;
		Polygon(hdc, pp, 3);

		hBrush1 = CreateSolidBrush(RGB(255, 255, 0));
		HBRUSH hBrush2 = CreateHatchBrush(HS_VERTICAL, RGB(124, 252, 0));
		SelectObject(hdc, hBrush1);
		Ellipse(hdc, 190, 80, 230, 100);
		Ellipse(hdc, 250, 80, 290, 100);

		SelectObject(hdc, hBrush2);
		POINT left[3];
		pp[0].x = 220; pp[0].y = 130;
		pp[1].x = 210; pp[1].y = 150;
		pp[2].x = 230; pp[2].y = 150;
		Polygon(hdc, pp, 3);
		POINT right[3];
		pp[0].x = 260; pp[0].y = 130;
		pp[1].x = 250; pp[1].y = 150;
		pp[2].x = 270; pp[2].y = 150;
		Polygon(hdc, pp, 3);

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
