//
// Created by jhas on 2022/12/12.
//

#pragma once
#include <imgui.h>
#include <functional>
void renderFileMenu(std::function<void()> newOperation,std::function<void()> openOperation,std::function<void()> saveOperation);