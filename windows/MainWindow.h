//
// Created by jhas on 2022/12/11.
//

#ifndef IMGUIPRACTICE_MAINWINDOW_H
#define IMGUIPRACTICE_MAINWINDOW_H
#include <imgui.h>
#include "../components/ButtonGroup.h"
#include "../render.h"

class MainWindow : public Renderable{
private:
    ButtonGroup buttonGroup;
public:
    void render() override;
    ~MainWindow() override = default;
};


#endif //IMGUIPRACTICE_MAINWINDOW_H
