//
// Created by jhas on 2022/12/13.
//

#ifndef IMGUIPRACTICE_RENDERTARGETGROUP_H
#define IMGUIPRACTICE_RENDERTARGETGROUP_H

#include <imgui.h>
#include <d3d11.h>
#include "D3D11_BLEND_COMBO.h"
#include "D3D11_BLEND_OP_COMBO.h"

class RenderTargetGroup {
private:
    D3D11_RENDER_TARGET_BLEND_DESC &d3D11RenderTargetBlendDesc;
    D3D11_BLEND_COMBO SrcBlend;
    D3D11_BLEND_COMBO DestBlend;
    D3D11_BLEND_OP_COMBO BlendOp;
    D3D11_BLEND_COMBO SrcBlendAlpha;
    D3D11_BLEND_COMBO DestBlendAlpha;
    D3D11_BLEND_OP_COMBO BlendOpAlpha;
public:
    explicit RenderTargetGroup(D3D11_RENDER_TARGET_BLEND_DESC &src);

    void render();

    void update();

    ~RenderTargetGroup();
};


#endif //IMGUIPRACTICE_RENDERTARGETGROUP_H
