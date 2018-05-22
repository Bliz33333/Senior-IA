#include "StartUpCommands.h"
#include <windows.h>
#include <windowsx.h>
#include <climits>

std::map<std::string, class LitUnit> IBmap;
std::map<std::string, class LitUnit> APmap;

#define BTN_GO		1101
#define BTN_NEXT	1102

HWND englishBox;
HWND latinBox;
HWND litSelect;
LitUnit * c_view = NULL;
std::vector<std::string> IBindices =
		{ };
std::vector<std::string> APindices =
		{ };
int counter = 0;

const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_COMMAND:
			switch (HIWORD(wParam))
			{
				case BN_CLICKED:
					if (LOWORD(msg) == BTN_NEXT || LOWORD(wParam) == BTN_NEXT) //TODO word cut instead of what is now
					{
						if(c_view != NULL)
						{
							if (counter % 2 == 0)
							{
								c_view->translator.nextLatin();
								SetWindowText(latinBox, c_view->translator.DAL.c_str());
								counter++;

								SendMessage(latinBox, (UINT) EM_LINESCROLL, (WPARAM) 0, (LPARAM) INT_MAX);
							}
							else
							{
								c_view->translator.nextEnglish();
								SetWindowText(englishBox, c_view->translator.DAE.c_str());
								counter++;

								SendMessage(englishBox, (UINT) EM_LINESCROLL, (WPARAM) 0, (LPARAM) INT_MAX);
							}
						}
					}
					else if (LOWORD(msg) == BTN_GO || LOWORD(wParam) == BTN_GO)
					{
						if (c_view != NULL)
						{
							c_view->translator.reset();
						}

						unsigned int selected = ComboBox_GetCurSel(litSelect);

						if (selected < IBindices.size())
						{
							c_view = &IBmap[IBindices[selected]];
						}
						else
						{
							c_view = &APmap[APindices[selected - IBindices.size()]];
						}

						SetWindowText(englishBox, c_view->translator.DAE.c_str());
						SetWindowText(latinBox, c_view->translator.DAL.c_str());
						counter = 0;
					}
					break;
			}
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow)
{
	startupLit(IBmap, APmap);
	startupStages();

	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
		MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
	WS_EX_CLIENTEDGE, g_szClassName, "Latin Study Tool",
	WS_OVERLAPPEDWINDOW,
	CW_USEDEFAULT, CW_USEDEFAULT, 1300, 750,
	NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
		MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND goButton = CreateWindow(
			"BUTTON",  // Predefined class; Unicode assumed
			"Go",// Button text
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | BS_NOTIFY | BS_PUSHBUTTON,// Styles
			10,// x position
			100,// y position
			50,// Button width
			25,// Button height
			hwnd,// Parent window
			(HMENU) BTN_GO,// No menu.
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

	SendMessage(goButton, (UINT) DM_SETDEFID, (WPARAM) BTN_GO, 0);

	HWND nextButton = CreateWindow(
			"BUTTON",  // Predefined class; Unicode assumed
			"Next",// Button text
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_NOTIFY | BS_PUSHBUTTON,// Styles
			10,// x position
			140,// y position
			92,// Button width
			25,// Button height
			hwnd,// Parent window
			(HMENU) BTN_NEXT,// No menu.
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

	SendMessage(nextButton, (UINT) DM_SETDEFID, (WPARAM) BTN_NEXT, 0);

	englishBox = CreateWindow(TEXT("Edit"), TEXT(std::to_string(BTN_GO).c_str()), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY, 175, 60, 600, 500, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

	latinBox = CreateWindow(TEXT("Edit"), TEXT(std::to_string(BTN_NEXT).c_str()), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY, 867, 60, 400, 500, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

	litSelect = CreateWindow(TEXT("ComboBox"), TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
			10, 60, 140, 180, hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

	for (std::map<std::string, class LitUnit>::iterator it = IBmap.begin(); it != IBmap.end(); ++it)
	{
		IBindices.push_back(it->first);
		SendMessage(litSelect, (UINT) CB_ADDSTRING, (WPARAM) 0, (LPARAM) it->first.c_str());
	}
	for (std::map<std::string, class LitUnit>::iterator it = APmap.begin(); it != APmap.end(); ++it)
	{
		APindices.push_back(it->first);
		SendMessage(litSelect, (UINT) CB_ADDSTRING, (WPARAM) 0, (LPARAM) it->first.c_str());
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

