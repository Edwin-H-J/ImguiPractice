//
// Created by jhas on 2022/12/11.
//

#ifndef IMGUIPRACTICE_BUTTONGROUP_H
#define IMGUIPRACTICE_BUTTONGROUP_H
#include "imgui.h"
#include "../render.h"
#include "../windows/BLEND_DESC_Struct.h"
class ButtonGroup:public Renderable {
private:
    BLEND_DESC_Struct blendDescStruct;
public:
    void render() override;
    ~ButtonGroup() override = default;
};


#endif //IMGUIPRACTICE_BUTTONGROUP_H
