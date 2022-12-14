//
// Created by jhas on 2022/12/11.
//

#include "MainWindow.h"

void MainWindow::render() {
    ImGui::Begin("Main Window");
    buttonGroup.render();
    ImGui::End();
}
