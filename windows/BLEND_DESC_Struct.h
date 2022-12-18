//
// Created by jhas on 2022/12/11.
//

#ifndef IMGUIPRACTICE_BLEND_DESC_STRUCT_H
#define IMGUIPRACTICE_BLEND_DESC_STRUCT_H
#include <imgui.h>
#include <d3d11.h>
#include "../utils/OpenJSONFile.h"
#include "../components/ComponentUtils.h"
#include "../components/RenderTargetGroup.h"
#include "../utils/JSONSerializer.h"
#include <vector>
#include <memory>
class BLEND_DESC_Struct{
private:
    OpenJSONFile openJsonFile;
    JSONSerializer<D3D11_BLEND_DESC> jsonSerializer;
    D3D11_BLEND_DESC d3D11BlendDesc{};
    bool display = false;
    std::vector<std::shared_ptr<RenderTargetGroup>> RenderTargetGroups;

public:
    BLEND_DESC_Struct();
    bool isDisplay();
    void startDisplay();
    void render();
    void update();
    void structureInit();
    ~BLEND_DESC_Struct();
};


#endif //IMGUIPRACTICE_BLEND_DESC_STRUCT_H
