#include "formatkit.h"

#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

int main() {
    // Настройка UTF-16 для wcout/wcin
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    // Включение поддержки ANSI в Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    colorPrint(L"white", L"Менеджер паролей alpha-0.1", L"bold");

    return 0;
}
