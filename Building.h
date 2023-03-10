//
// Created by Paul Keck on 12.01.23.
//

#ifndef CLION_WS_BUILDING_H
#define CLION_WS_BUILDING_H

#include <string>
#include <vector>
#include "Material.h"



class Building {

public:
    Building(std::string name, int id, int gebPreis, std::vector<Material*> benMaterialien);

    std::string gebäudeName;

    int gebäudeID;

    int gebäudePreis;


    int berechneKosten();

    std::string auflistung();

    std::vector<Material*> materialien;
};


#endif //CLION_WS_BUILDING_H
