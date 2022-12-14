//
// Created by jhas on 2022/12/11.
//
#include "../utils/D3D11StructureSerialize.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
int main() {
    std::ofstream of("./test.json");
    cereal::JSONOutputArchive* archive = new cereal::JSONOutputArchive(of);
    D3D11_BLEND_DESC t1;
    memset(&t1,0,sizeof(t1));
    t1.AlphaToCoverageEnable = true;
    t1.IndependentBlendEnable = true;
    (*archive)(CEREAL_NVP(t1));
//    archive->finishNode();
    delete archive;
    of.flush();
    of.close();
}
