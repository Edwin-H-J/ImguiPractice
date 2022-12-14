//
// Created by jhas on 2022/12/11.
//

#include "ButtonGroup.h"

void ButtonGroup::render() {
    if(ImGui::Button("Edit_BLEND_DESC")) {
        blendDescStruct.startDisplay();
    }
    blendDescStruct.render();
}
