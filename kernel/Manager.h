#pragma once
#include "Entry.h" /* Password */
#include "Group.h" /* Directory */
#include <vector>
#include <string>

class Manager {
private:
	std::vector<Entry> rootEntries;
	std::vector<Group> rootGroups;
	// recursive
	Group* getGroup(const std::wstring& path);
public:
	/* Root Directory Methods */
	void addRootEntry(
		const std::wstring& NAME,
		const std::wstring& LOGIN,
		const std::wstring& PASSWD,
		const std::wstring& URL = L"",
		const std::wstring& NOTE = L"",
		DECORATION DECORATION = {L"", L"", L"", L"" }
	); // creates entry to Root directory
	void removeRootEntry(const std::wstring& NAME);
	void printRootNames();
	Entry* getRootEntry(const std::wstring& NAME);

	/* Group Methods */
	void tree();
	Group* createGroup(const std::wstring& path);
	void addGroupEntry(
		const std::wstring& path,
		const std::wstring& NAME,
		const std::wstring& LOGIN,
		const std::wstring& PASSWD,
		const std::wstring& URL = L"",
		const std::wstring& NOTE = L"",
		DECORATION DECORATION = { L"", L"", L"", L"" }
	);

	/* prints names ONLY for selected folder */
	void printGroupEntriesNames(const std::wstring& path);

};