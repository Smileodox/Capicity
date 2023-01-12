//
// Created by Paul Keck on 12.01.23.
//

#ifndef CLION_WS_CAPICITYSIM_H
#define CLION_WS_CAPICITYSIM_H

#include "Building.h"

#include <iostream>
#include <vector>

using namespace std;

class CapicitySim {

private:
    int reihen;
    int spalten;
    vector<vector<Building*>> gebäude;




public:
    void printFläche();
    void gebäudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebäude);
    void gebäudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebäude);
    void hauptMenü();



    void start();



};


#endif //CLION_WS_CAPICITYSIM_H
