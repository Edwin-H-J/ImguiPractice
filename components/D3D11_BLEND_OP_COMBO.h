//
// Created by jhas on 2022/12/13.
//

#ifndef IMGUIPRACTICE_D3D11_BLEND_OP_COMBO_H
#define IMGUIPRACTICE_D3D11_BLEND_OP_COMBO_H

#include <d3d11.h>
#include <imgui.h>



class D3D11_BLEND_OP_COMBO {
private:
    const char *ComboName;
    D3D11_BLEND_OP &src;
    int select = 0;
public:
    D3D11_BLEND_OP_COMBO(D3D11_BLEND_OP &proxy, const char *name);

    void render();

    void update();

    ~D3D11_BLEND_OP_COMBO() = default;
};


#endif //IMGUIPRACTICE_D3D11_BLEND_OP_COMBO_H
