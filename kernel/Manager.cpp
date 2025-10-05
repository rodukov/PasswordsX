#include "Manager.h"

#include <vector>
#include <string>
#include <iostream>

void Manager::addRootEntry(
	const std::wstring& NAME,
	const std::wstring& LOGIN,
	const std::wstring& PASSWD,
	const std::wstring& URL,
	const std::wstring& NOTE,
	const DECORATION DECORATION)
{
	rootEntries.push_back({ NAME, LOGIN, PASSWD, URL, NOTE, DECORATION });
}

void Manager::removeRootEntry(
	const std::wstring& NAME
) {
	for (auto object = rootEntries.begin(); object != rootEntries.end(); ++object)
	if (object->NAME == NAME) { rootEntries.erase(object); return; }
	
}

void Manager::printRootNames() {
	for (auto& object : rootEntries) std::wcout << object.NAME << std::endl;
}

Entry* Manager::findRootEntry(const std::wstring& NAME) {
	for (auto& object : rootEntries) if (object.NAME == NAME) return &object;
	return nullptr;
}