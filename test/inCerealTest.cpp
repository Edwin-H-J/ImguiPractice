//
// Created by jhas on 2022/12/11.
//
#include "../utils/D3D11StructureSerialize.h"
#include <cereal/archives/json.hpp>
#include <fstream>
#include <iostream>
int main() {
    std::ifstream inf("./test.json");
    cereal::JSONInputArchive archive(inf);
    D3D11_BLEND_DESC t1;
    try {
        archive(t1);
    }catch (std::exception e) {
        std::cout<<e.what();
    }
    std::cout<<t1.IndependentBlendEnable << t1.AlphaToCoverageEnable;
}