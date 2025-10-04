#pragma once
#include <iostream>

struct Entry {
	std::wstring NAME; // entryname
	std::wstring LOGIN; // login(username)
	std::wstring PASSWD; // password
	std::wstring URL; // servicelink
	std::wstring NOTE; // entrycomment (optional)
	std::wstring DECORATION; // entry customization (optional)
};