//
// Created by jhas on 2022/12/11.
//

#ifndef IMGUIPRACTICE_BUTTONGROUP_H
#define IMGUIPRACTICE_BUTTONGROUP_H
#include "imgui.h"
#include "../windows/BLEND_DESC_Struct.h"
class ButtonGroup {
private:
    BLEND_DESC_Struct blendDescStruct;
public:
    void render() ;
    ~ButtonGroup()  = default;
};


#endif //IMGUIPRACTICE_BUTTONGROUP_H
