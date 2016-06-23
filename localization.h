const wchar_t* get_localization_text(const char* text);

HWND WINAPI CreateWindowExAL(_In_ DWORD dwExStyle,
	_In_opt_ LPCSTR lpClassName,
	_In_opt_ LPCSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam);

BOOL WINAPI TextOutAL(_In_ HDC hdc, _In_ int x, _In_ int y, _In_reads_(c) LPCSTR lpString, _In_ int c);
BOOL WINAPI SetDlgItemTextAL(_In_ HWND hDlg,	_In_ int nIDDlgItem, _In_ LPCSTR lpString);
BOOL APIENTRY GetTextExtentPoint32AL(_In_ HDC hdc, _In_reads_(c) LPCSTR lpString, _In_ int c, _Out_ LPSIZE psizl);
