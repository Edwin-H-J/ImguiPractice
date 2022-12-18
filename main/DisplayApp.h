//
// Created by jhas on 2022/12/18.
//

#ifndef IMGUIPRACTICE_DISPLAYAPP_H
#define IMGUIPRACTICE_DISPLAYAPP_H
#include "D3DApp.h"
#include "../triangle/Triangle.h"
#include "../windows/MainWindow.h"

class DisplayApp: public D3DApp{
public:
    DisplayApp(const std::wstring& windowName, int initWidth, int initHeight);
    Triangle triangle;
    MainWindow mainWindow;
    bool Init();
    void DrawScene();
};


#endif //IMGUIPRACTICE_DISPLAYAPP_H
