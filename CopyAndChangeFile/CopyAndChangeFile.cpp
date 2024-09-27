#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    HMODULE hDll;
    int(*CountSymbolInFile)(const string&, char);
    hDll = LoadLibrary("C:\\Users\\217041\\source\\repos\\copyandchangefileDLL\\x64\\Debug\\copyandchangefileDLL.dll");
    if (!hDll)
    {
        cerr << "Load library failed." << endl;
        return GetLastError();
    }

    CountSymbolInFile = (int(*)(const string&, char)) GetProcAddress(hDll, MAKEINTRESOURCE(1));
    if (!CountSymbolInFile)
    {
        cerr << "GEt procedure address failled." << endl;
        return GetLastError();
    }

    char fin[256]; // Allocate a buffer
    cout << "Enter the filename: ";
    cin >> fin; // Read the filename into the buffer
    cout << CountSymbolInFile(fin,'i') << endl;
    if (!FreeLibrary(hDll))
    {
        cerr << "Free library failed." << endl;
        return GetLastError();
    }
    cout << "Press any key to exit";

}
