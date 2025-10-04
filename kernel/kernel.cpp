#include "formatkit.h"
#include "Manager.h"

#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

int main() {
    // UTF-16 settings for wcout/wcin
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    // ANSI support enable in CMD/PowerShell
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    colorPrint(L"white", L"Менеджер паролей alpha-0.1", L"bold", L"blue");

    Manager manager;
    manager.addRootEntry(L"Server Access", L"root@144.2.253.150", L"Ex4(KF5K3(#(55$JSDl12", L"", L"corporate server access #58483", { L"red", L"", L"", L""} );
    manager.removeRootEntry(L"Server Access");
    manager.addRootEntry(L"Server Access", L"root@144.2.253.150", L"Ex4(KF5K3(#(55$JSDl12", L"", L"corporate server access #58483", { L"red", L"", L"", L"" });
    manager.addRootEntry(L"Server Access 2", L"admin@144.2.253.150", L"Ex4(KF5K$3(#(55$JS1111", L"", L"corporate server access #58483", { L"yellow", L"", L"", L"" });
    manager.addRootEntry(L"Server Access 3", L"dev@144.2.253.150", L"Ex4(*%($5JSDl12", L"", L"corporate server access #58483", { L"green", L"", L"", L"" });
    manager.printRootEntries();

    return 0;
}
