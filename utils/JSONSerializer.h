//
// Created by jhas on 2022/12/13.
//

#ifndef IMGUIPRACTICE_JSONSERIALIZER_H
#define IMGUIPRACTICE_JSONSERIALIZER_H
#include <cereal/archives/json.hpp>
#include "D3D11StructureSerialize.h"
#include <fstream>
template<typename T>
class JSONSerializer {
public:
    void deserialize(const char* path,T& obj) {
        std::ifstream inf(path);
        cereal::JSONInputArchive archive(inf);
        try {
            archive(obj);
        }catch (std::exception e) {
            std::cout<<e.what();
        }
        inf.close();
    }
    void serialize(const char* path,T& obj) {
        std::ofstream of(path);
        cereal::JSONOutputArchive* archive = new cereal::JSONOutputArchive(of);
        try {
            (*archive)(CEREAL_NVP(obj));
        }catch (std::exception e) {
            std::cout<<e.what();
        }
        delete archive;
        of.flush();
        of.close();
    }
};


#endif //IMGUIPRACTICE_JSONSERIALIZER_H
