//
// Created by jhas on 2022/12/12.
//

#ifndef IMGUIPRACTICE_D3D11_BLEND_COMBO_H
#define IMGUIPRACTICE_D3D11_BLEND_COMBO_H
#include <imgui.h>
#include <d3d11.h>
class D3D11_BLEND_COMBO{

private:
    const char* ComboName;
    D3D11_BLEND& src;
    int select = 0;
public:
    D3D11_BLEND_COMBO(D3D11_BLEND& proxy,const char* name);
    void render();
    void update();
    ~D3D11_BLEND_COMBO() = default;
};


#endif //IMGUIPRACTICE_D3D11_BLEND_COMBO_H
