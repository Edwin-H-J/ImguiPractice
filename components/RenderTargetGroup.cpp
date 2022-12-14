//
// Created by jhas on 2022/12/13.
//

#include "RenderTargetGroup.h"

RenderTargetGroup::RenderTargetGroup(D3D11_RENDER_TARGET_BLEND_DESC& src):
d3D11RenderTargetBlendDesc(src),
SrcBlend(src.SrcBlend,"SrcBlend"),
DestBlend(src.DestBlend,"DestBlend"),
BlendOp(src.BlendOp,"BlendOp"),
SrcBlendAlpha(src.SrcBlendAlpha,"SrcBlendAlpha"),
DestBlendAlpha(src.DestBlendAlpha,"DestBlendAlpha"),
BlendOpAlpha(src.BlendOpAlpha,"BlendOpAlpha"){

}

void RenderTargetGroup::render() {
    ImGui::Checkbox("BlendEnable", reinterpret_cast<bool*>(&d3D11RenderTargetBlendDesc.BlendEnable));
    SrcBlend.render();
    DestBlend.render();
    BlendOp.render();
    SrcBlendAlpha.render();
    DestBlendAlpha.render();
    BlendOpAlpha.render();
    static int inputStep = 1;
    ImGui::InputScalar("RenderTargetWriteMask", ImGuiDataType_U8,&d3D11RenderTargetBlendDesc.RenderTargetWriteMask,&inputStep,NULL,"%u");

}

void RenderTargetGroup::update() {
    SrcBlend.update();
    DestBlend.update();
    BlendOp.update();
    SrcBlendAlpha.update();
    DestBlendAlpha.update();
    BlendOpAlpha.update();
}

RenderTargetGroup::~RenderTargetGroup() {

}
