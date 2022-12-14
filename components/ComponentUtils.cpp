//
// Created by jhas on 2022/12/12.
//
#include "ComponentUtils.h"

void renderFileMenu(std::function<void()> newOperation,std::function<void()> openOperation,std::function<void()> saveOperation) {
    if(ImGui::BeginMenu("File")){
        if(ImGui::MenuItem("New")) {
            newOperation();

        }
        if(ImGui::MenuItem("Open")) {
            openOperation();
        }
        if(ImGui::MenuItem("Save")) {
            saveOperation();
        }
        ImGui::EndMenu();
    }
}