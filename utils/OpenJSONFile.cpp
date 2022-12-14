#include "OpenJSONFile.h"
std::string OpenJSONFile::open() {
    IFileOpenDialog* iFileOpenDialog = NULL;
    nowOpenFile.clear();
    HRESULT hr = CoCreateInstance(__uuidof(FileOpenDialog), NULL, CLSCTX_ALL,
                                  __uuidof(IFileOpenDialog),
                                  reinterpret_cast<void**>(&iFileOpenDialog));
    if(SUCCEEDED(hr)) {
        hr = iFileOpenDialog->Show(NULL);
        if(SUCCEEDED(hr)) {
            IShellItem* shell_item = NULL;
            hr = iFileOpenDialog->GetResult(&shell_item);
            if(SUCCEEDED(hr)) {
                PWSTR file_path_ptr = NULL;
                hr = shell_item->GetDisplayName(SIGDN_FILESYSPATH, &file_path_ptr);
                if(SUCCEEDED(hr)) {
                    nowOpenFile = wsTos(file_path_ptr);
                }
            }
        }
    }
    return nowOpenFile;
}
std::string OpenJSONFile::save() {
    IFileSaveDialog* iFileSaveDialog = NULL;
    nowOpenFile.clear();
    HRESULT hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL,
                                  IID_IFileSaveDialog, reinterpret_cast<void**>(&iFileSaveDialog));
    if(SUCCEEDED(hr)) {
        hr = iFileSaveDialog->Show(NULL);
        if(SUCCEEDED(hr)) {
            IShellItem* shell_item = NULL;
            hr = iFileSaveDialog->GetResult(&shell_item);
            if(SUCCEEDED(hr)) {
                PWSTR file_path_ptr = NULL;
                hr = shell_item->GetDisplayName(SIGDN_FILESYSPATH, &file_path_ptr);
                if(SUCCEEDED(hr)) {
                    nowOpenFile = wsTos(file_path_ptr);
                }
            }
        }
    }
    return nowOpenFile;
}

const std::string &OpenJSONFile::getNowOpenFile() const {
    return nowOpenFile;
}

void OpenJSONFile::setNowOpenFile(const std::string &nowOpenFile) {
    OpenJSONFile::nowOpenFile = nowOpenFile;
}

