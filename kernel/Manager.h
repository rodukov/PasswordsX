#pragma once
#include "Entry.h" /* Password */
#include "Group.h" /* Directory */
#include <vector>
#include <string>

class Manager {
private:
	std::vector<Entry> rootEntries;
	std::vector<Group> rootGroups;

	// * findGroup(const std::wstring& path);
	// void listGroup();
public:
	void addRootEntry(
		const std::wstring& NAME,
		const std::wstring& LOGIN,
		const std::wstring& PASSWD,
		const std::wstring& URL = L"",
		const std::wstring& NOTE = L"",
		DECORATION DECORATION = {L"", L"", L"", L"" }
	);
void removeRootEntry(const std::wstring& NAME);
void printRootEntries();
};