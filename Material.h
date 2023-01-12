//
// Created by Paul Keck on 12.01.23.
//

#ifndef CLION_WS_MATERIAL_H
#define CLION_WS_MATERIAL_H

#include <string>


class Material {

public:
    Material(std::string name, int preis);

    std::string materialName;
    int preis;


};


#endif //CLION_WS_MATERIAL_H
