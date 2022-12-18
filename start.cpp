//
// Created by jhas on 2022/12/16.
//
#include "main/DisplayApp.h"
int main() {
    DisplayApp app(L"ImguiPractice",1280, 720);
    if(!app.Init()) {
        return 0;
    }
    return app.Run();
}