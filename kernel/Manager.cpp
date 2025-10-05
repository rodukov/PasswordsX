#include "Manager.h"
#include "split.h"
#include <vector>
#include <string>
#include <iostream>

/*
Root Directory Methods Implementation
*/
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

Entry* Manager::getRootEntry(const std::wstring& NAME) {
	for (auto& object : rootEntries) if (object.NAME == NAME) return &object;
	return nullptr;
}
/*
Group Methods Implementation
*/

// complex
Group* Manager::getGroup(const std::wstring& path) {
    auto parts = split(path);
    std::vector<Group>* level = &rootGroups;

    for (auto& part : parts) {
        bool found = false;
        for (auto& group : *level) {
            if (group.groupName == part) {
                found = true;
                if (part == parts.back()) return &group;
                level = &group.subGroups;
                break;
            }
        }
        if (!found) return nullptr;
    }

    return nullptr;
}

// complex
Group* Manager::createGroup(const std::wstring& path) {
    auto parts = split(path);
    std::vector<Group>* currentLevel = &rootGroups;
    Group* lastGroup = nullptr;

    for (auto& part : parts) {
        bool found = false;

        // Switches to downlevel(exists)
        for (auto& group : *currentLevel) {
            if (group.groupName == part) {
                lastGroup = &group;
                currentLevel = &group.subGroups;
                found = true;
                break;
            }
        }
        // Creates new directory(not exists)
        if (!found) {
            Group newGroup;
            newGroup.groupName = part;
            currentLevel->push_back(newGroup);

            lastGroup = &currentLevel->back();
            currentLevel = &lastGroup->subGroups;
        }
    }

    return lastGroup;
}

void Manager::addGroupEntry(
    const std::wstring& path,
    const std::wstring& NAME,
    const std::wstring& LOGIN,
    const std::wstring& PASSWD,
    const std::wstring& URL,
    const std::wstring& NOTE,
    DECORATION DECORATION)
{
    Group* X = getGroup(path);
    X->entries.push_back({ NAME, LOGIN, PASSWD, URL, NOTE, DECORATION });
}

void Manager::printGroupEntriesNames(const std::wstring& path) {
    Group* X = getGroup(path);
    for (auto& Y : X->entries) {
        std::wcout << Y.NAME << std::endl;
    }
}