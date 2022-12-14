//
// Created by jhas on 2022/12/11.
//

#include "BLEND_DESC_Struct.h"
#include "string"

bool BLEND_DESC_Struct::isDisplay() {
    return display;
}

void BLEND_DESC_Struct::startDisplay() {
    display = true;
}

void BLEND_DESC_Struct::render() {
    if (!display) {
        return;
    }
    ImGuiWindowFlags flags = 0;
    flags |= ImGuiWindowFlags_MenuBar;
    ImGui::Begin("BLEND DESC Editor", &display, flags);
    if (ImGui::BeginMenuBar()) {
        renderFileMenu([this]() {
            structureInit();
            update();
            openJsonFile.setNowOpenFile("");
        }, [this]() {
            auto &&openFile = openJsonFile.open();
            if (!openFile.empty()) {
                jsonSerializer.deserialize(openFile.c_str(), d3D11BlendDesc);
                update();
            }
        }, [this]() {
            auto openFile = openJsonFile.getNowOpenFile();
            if (openFile.empty()) {
                openFile = openJsonFile.save();
            }
            if (!openFile.empty()) {
                jsonSerializer.serialize(openFile.c_str(), d3D11BlendDesc);
            }
        });
        ImGui::EndMenuBar();
    }
    ImGui::Checkbox("AlphaToCoverageEnable", reinterpret_cast<bool *>(&d3D11BlendDesc.AlphaToCoverageEnable));
    ImGui::Checkbox("IndependentBlendEnable", reinterpret_cast<bool *>(&d3D11BlendDesc.IndependentBlendEnable));
    for (int i = 0; i < 8; i++) {
        if (ImGui::TreeNode(("RenderTarget " + std::to_string(i + 1)).c_str())) {
            RenderTargetGroups[i]->render();
            ImGui::TreePop();
        }
    }
    ImGui::End();
}

BLEND_DESC_Struct::BLEND_DESC_Struct() {
    structureInit();
    for (int i = 0;i<8;i++) {
        RenderTargetGroups.push_back(std::make_shared<RenderTargetGroup>(d3D11BlendDesc.RenderTarget[i]));
    }
    update();
}

BLEND_DESC_Struct::~BLEND_DESC_Struct() {

}

void BLEND_DESC_Struct::update() {
    for (int i = 0; i < 8; i++) {
        RenderTargetGroups[i]->update();
    }
}

void BLEND_DESC_Struct::structureInit() {
    d3D11BlendDesc = D3D11_BLEND_DESC {FALSE,FALSE,{
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL},
        {FALSE,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,D3D11_BLEND_OP_ADD,D3D11_BLEND_ONE,D3D11_BLEND_ZERO,
         D3D11_BLEND_OP_ADD,D3D11_COLOR_WRITE_ENABLE_ALL}
    }};
}

