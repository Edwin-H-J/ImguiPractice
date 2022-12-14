//
// Created by jhas on 2022/12/13.
//

#include "D3D11_BLEND_OP_COMBO.h"
D3D11_BLEND_OP_COMBO::D3D11_BLEND_OP_COMBO(D3D11_BLEND_OP &proxy, const char *name):src(proxy),ComboName(name) {
}

void D3D11_BLEND_OP_COMBO::render() {
    const char *items[] = {
            "D3D11_BLEND_OP_ADD",
            "D3D11_BLEND_OP_SUBTRACT",
            "D3D11_BLEND_OP_REV_SUBTRACT",
            "D3D11_BLEND_OP_MIN",
            "D3D11_BLEND_OP_MAX",
    };
    if(ImGui::Combo(ComboName, &select, items, IM_ARRAYSIZE(items))) {
        src = D3D11_BLEND_OP(select + 1);
    }
}

void D3D11_BLEND_OP_COMBO::update() {
    select = int(src) - 1;
}
