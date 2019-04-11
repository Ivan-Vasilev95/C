// Test_2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Test_2.h"
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
LRESULT CALLBACK test(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
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
    LoadStringW(hInstance, IDC_TEST2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TEST2);
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

LRESULT CALLBACK test(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_TIMER:
	{
		int pos = SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0);
		if (pos < 100) {
			pos++;
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, pos, 0);
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
			if (IsDlgButtonChecked(hDlg, IDC_CHECK1)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"1");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK2)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"2");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK3)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"3");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK6)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"4");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK5)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"5");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK4)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"6");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK7)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"7");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK8)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"8");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK9)) {
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"9");
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK10)) {
				std::wstring s = std::to_wstring(10);
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)s.c_str());
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK11)) {
				std::wstring s = std::to_wstring(11);
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)s.c_str());
			}
			if (IsDlgButtonChecked(hDlg, IDC_CHECK12)) {
				std::wstring s = std::to_wstring(12);
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)s.c_str());
			}

		}
		break;
		case IDC_BUTTON2:
		{
			std::wstring oct = std::to_wstring(10);
			std::wstring nov = std::to_wstring(11);
			std::wstring dec = std::to_wstring(12);

			int elemets = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCOUNT, 0, 0);

			int countJan = 0;
			int countFeb = 0;
			int countMarch = 0;
			int countApr = 0;
			int countMay = 0;
			int countJune = 0;
			int countJuly = 0;
			int countAug = 0;
			int countSept = 0;
			int countOct = 0;
			int countNov =0;
			int countDec = 0;
		
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"1") >= 0) {
				countJan++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"2") >= 0) {
				countFeb++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"3") >= 0) {
				countMarch++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"4") >= 0) {
				countApr++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"5") >= 0) {
				countMay++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"6") >= 0) {
				countJune++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"7") >= 0) {
				countJuly++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"8") >= 0) {
				countAug++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)"9") >= 0) {
				countSept++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)oct.c_str()) >= 0) {
				countOct++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)nov.c_str()) >= 0) {
				countNov++;
			}
			if (int temp = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)dec.c_str()) >= 0) {
				countDec++;
			}

			TCHAR buff[10];
			TCHAR jan[10] = { '1' };

			for (int i = 0; i < elemets; i++) {


				if (_tcscmp(buff, jan) == 0) {
					countJan++;
				}
			}
			
			
			

		    std::wstring s1 = std::to_wstring(countJan);
		    LPCTSTR str1 = s1.c_str();
		    MessageBox(hDlg, str1, L"January", MB_OK | MB_ICONINFORMATION);
			
			std::wstring s2 = std::to_wstring(countFeb);
			LPCTSTR str2 = s2.c_str();
			MessageBox(hDlg, str2, L"February", MB_OK | MB_ICONINFORMATION);

		    std::wstring s3 = std::to_wstring(countMarch);
			LPCTSTR str3 = s3.c_str();
			MessageBox(hDlg, str3, L"March", MB_OK | MB_ICONINFORMATION);

			std::wstring s4 = std::to_wstring(countApr);
			LPCTSTR str4 = s4.c_str();
			MessageBox(hDlg, str4, L"April", MB_OK | MB_ICONINFORMATION);

			std::wstring s5 = std::to_wstring(countMay);
			LPCTSTR str5 = s5.c_str();
			MessageBox(hDlg, str5, L"May", MB_OK | MB_ICONINFORMATION);

			std::wstring s6 = std::to_wstring(countJune);
			LPCTSTR str6 = s6.c_str();
			MessageBox(hDlg, str6, L"June", MB_OK | MB_ICONINFORMATION);
			
			std::wstring s7 = std::to_wstring(countJuly);
			LPCTSTR str7 = s7.c_str();
			MessageBox(hDlg, str7, L"July", MB_OK | MB_ICONINFORMATION);

			std::wstring s8 = std::to_wstring(countAug);
			LPCTSTR str8 = s8.c_str();
			MessageBox(hDlg, str8, L"August", MB_OK | MB_ICONINFORMATION);		

			std::wstring s9 = std::to_wstring(countSept);
			LPCTSTR str9 = s9.c_str();
			MessageBox(hDlg, str9, L"September", MB_OK | MB_ICONINFORMATION);

			std::wstring s10 = std::to_wstring(countOct);
			LPCTSTR str10 = s10.c_str();
			MessageBox(hDlg, str10, L"October", MB_OK | MB_ICONINFORMATION);

			std::wstring s11 = std::to_wstring(countNov);
			LPCTSTR str11 = s11.c_str();
			MessageBox(hDlg, str11, L"November", MB_OK | MB_ICONINFORMATION);		

			std::wstring s12 = std::to_wstring(countDec);
			LPCTSTR str12 = s12.c_str();
			MessageBox(hDlg, str12, L"December", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDC_BUTTON3:
		{
			int index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCURSEL, 0, 0);
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_DELETESTRING, index, 0);
		}
		break;
		case IDC_BUTTON4:
		{
			BOOL *SLt = NULL;
			BOOL SIG = true;

			int index = GetDlgItemInt(hDlg, IDC_COMBO1, SLt, SIG);
			int box = GetDlgItemInt(hDlg, IDC_EDIT1, SLt, SIG);
			int rezult = index + box;

			switch (rezult) {
			case 1:
			{
				MessageBox(hDlg, L"January", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 2:
			{
				MessageBox(hDlg, L"February", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 3:
			{
				MessageBox(hDlg, L"March", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 4:
			{
				MessageBox(hDlg, L"April", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 5:
			{
				MessageBox(hDlg, L"May", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 6:
			{
				MessageBox(hDlg, L"June", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 7:
			{
				MessageBox(hDlg, L"July", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 8:
			{
				MessageBox(hDlg, L"August", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 9:
			{
				MessageBox(hDlg, L"September", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 10:
			{
				MessageBox(hDlg, L"October", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 11:
			{
				MessageBox(hDlg, L"November", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			case 12:
			{
				MessageBox(hDlg, L"December", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			default:
			{
				MessageBox(hDlg, L"There is no month with this number", L"Result", MB_OK | MB_ICONINFORMATION);
			}
			break;
			}
		}
		break;
		case IDC_BUTTON5:
		{
			SetTimer(hDlg, TIMER1, 1, NULL);
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 0, 0);
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

			HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 0, 255));
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

			SetBkColor(hdc, RGB(255,0,0));
			HBRUSH hBrush2 = CreateHatchBrush(HS_HORIZONTAL, RGB(124, 252, 0));
			SelectObject(hdc, hBrush2);
			Ellipse(hdc, 190, 80, 230, 100);
			Ellipse(hdc, 250, 80, 290, 100);

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
