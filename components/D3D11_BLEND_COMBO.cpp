//
// Created by jhas on 2022/12/12.
//

#include "D3D11_BLEND_COMBO.h"
D3D11_BLEND_COMBO::D3D11_BLEND_COMBO(D3D11_BLEND &proxy,const char* name):src(proxy),ComboName(name) {

}

void D3D11_BLEND_COMBO::render() {
    const char* items[] = {"D3D11_BLEND_ZERO",
                           "D3D11_BLEND_ONE",
                           "D3D11_BLEND_SRC_COLOR",
                           "D3D11_BLEND_INV_SRC_COLOR",
                           "D3D11_BLEND_SRC_ALPHA",
                           "D3D11_BLEND_INV_SRC_ALPHA",
                           "D3D11_BLEND_DEST_ALPHA",
                           "D3D11_BLEND_INV_DEST_ALPHA",
                           "D3D11_BLEND_DEST_COLOR",
                           "D3D11_BLEND_INV_DEST_COLOR",
                           "D3D11_BLEND_SRC_ALPHA_SAT",
                           "D3D11_BLEND_BLEND_FACTOR",
                           "D3D11_BLEND_INV_BLEND_FACTOR",
                           "D3D11_BLEND_SRC1_COLOR",
                           "D3D11_BLEND_INV_SRC1_COLOR",
                           "D3D11_BLEND_SRC1_ALPHA",
                           "D3D11_BLEND_INV_SRC1_ALPHA"};
    if(ImGui::Combo(ComboName, &select, items, IM_ARRAYSIZE(items))) {
        if(select < 11) {
            src = D3D11_BLEND(select + 1);
        }else{
            src = D3D11_BLEND(select + 3);
        }
    }
}

void D3D11_BLEND_COMBO::update() {
    if(int(src) <= 11&&int(src) > 0) {
        select = int(src) - 1;
    }else if(int(src > 11)){
        select = int(src) - 3;
    }
}
