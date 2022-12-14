//
// Created by jhas on 2022/12/11.
//

#pragma once
#include <Windows.h>
#include <ShObjIdl_core.h>
#include <ShObjIdl.h>
#include <string>

class OpenJSONFile {
private:
    std::string nowOpenFile;
    std::string wsTos(std::wstring wstr) {
        std::string result;
        int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
        if( len <= 0 )
            return result;
        char* buffer = new char[len + 1];
        if(buffer == NULL )
            return result;
        WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
        buffer[len] = '\0';
        result.append(buffer);
        delete[] buffer;
        return result;
    }
public:
    std::string open();
    std::string save();

    const std::string &getNowOpenFile() const;

    void setNowOpenFile(const std::string &nowOpenFile);
};
