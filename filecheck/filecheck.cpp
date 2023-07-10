//craig 7/10/2021
// TIME: 1:00 AM
// 

#include <windows.h>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <shlobj.h>
#include <thread>
#include <chrono>

/// <summary>
///  File Names to search for
/// </summary>
std::set<std::wstring> target_files = { L"Client_25.exe", L"Client_26.exe",
L"Client_27.exe", L"Client_28.exe",L"Client_29.exe", L"HsLoader.exe",
L"HeadShotLoader.exe", L"AddictedLauncher.exe",L"AddictedLauncherx64.exe", L"AD.exe",
L"AddictedLauncher.exe", L"cheese.exe", L"primal.exe", L"PrimalClient-V2_FREE.exe", 
L"xing.exe", L"BaseInput.json",  L"BaseInput_1.json", };


/// <summary>
///  File Folders search for
/// </summary>
std::set<std::wstring> target_folders = { L"AddictedCheats", L"AddictedCheatsx64", L"AddictedCheatsx86",
L"AddictedLauncher", L"AddictedLauncherx64", L"AddictedLauncherx86", L"AddictedLauncherx86_64",L"HeadshotConfig",
};


std::map<std::wstring, std::vector<std::wstring>> foundFiles;

void search_files(const std::wstring& folder) {
    std::wstring search_path = folder + L"/*";
    WIN32_FIND_DATAW findfiledata;
    HANDLE hFind = FindFirstFileW(search_path.c_str(), &findfiledata);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::wcerr << L"Error while accessing " << folder << std::endl;
        return;
    }

    do {
        if (findfiledata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (wcscmp(findfiledata.cFileName, L".") != 0 && wcscmp(findfiledata.cFileName, L"..") != 0) {
                std::wstring filename(findfiledata.cFileName);
                if (target_folders.count(filename)) {
                    foundFiles[filename].push_back(folder);
                }
                std::wstring sub_dir = folder + L"/" + findfiledata.cFileName;
                std::wcout << L"Searching in directory: " << sub_dir << std::endl;

                try {
                    search_files(sub_dir);
                }
                catch (...) {
                    std::wcerr << L"Failed to access " << sub_dir << std::endl;
                }
            }
        }
        else {
            std::wstring filename(findfiledata.cFileName);
            if (target_files.count(filename)) {
                foundFiles[filename].push_back(folder);
            }
        }
    } while (FindNextFileW(hFind, &findfiledata) != 0);

    FindClose(hFind);
}




int main() {
    std::wstring title = L"FileCheck 1.1";

    SetConsoleTitleW(title.c_str());
    std::wcout << L"Starting file search..." << std::endl;
    
    std::wstring path = L"C:\\";

    search_files(path);

    if (foundFiles.empty()) {
        std::wcout << L"No target files or folders found." << std::endl;
    }
    else {
        std::wcout << L"\nFILES FOUND!" << std::endl;
        for (auto& pair : foundFiles) {
            std::wcout << L"\nFile: " << pair.first << std::endl;
            for (auto& location : pair.second) {
                std::wcout << L"Location: " << location << std::endl;
            }
        }
    }

    system("pause");

    return 0;
}
