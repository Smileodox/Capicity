//
// Created by Paul Keck on 12.01.23.
//

#include "CapicitySim.h"
#include "Building.h"
#include "Leer.h"
#include "Windkraftwerk.h"
#include "Wasserkraftwerk.h"
#include "Solarpanel.h"


void CapicitySim::start() {


    std::cout <<"Bitte ZeilenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> reihen;

    std::cout <<"Bitte SpaltenAnzahl der zu simulierenten Fläche eingeben\n";
    std::cin >> spalten;

    //Flächen Vektor initialisieren

    gebäude = vector(reihen, vector<Building*>(spalten));

    for(int i = 0; i < gebäude.size(); i++) {
        for(int j = 0; j < gebäude[i].size();j++) {
            gebäude[i][j] = new Leer();
        }
    }




    //Test
    printFläche();

    hauptMenü();


}


void CapicitySim::gebäudeSetzenMitTest(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz,
                                Building* zuBauendesGebäude)
{
    bool test = false;
    bool outOfBounds = false;


    if(startZeile > gebäude.size() || startSpalte > gebäude[0].size()
        || (startSpalte - 1 + spaltenAnz) > gebäude[0].size() || (startZeile - 1 + zeilenAnz) >
            gebäude.size()){

        std::cout<< "Gebäude ist out of Bounds\n"<<endl;
        outOfBounds = true;


    }else{
        for (int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++) {
            for (int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++) {
                if (gebäude[i][j]->gebäudeID != 0){
                    test = true;

                }
            }
        }


    }

    if(test == true) {

        cout << "Gebäude kollidiert mit anderen Gebäuden, Vorgang wird abgebrochen\n" << endl;

    } else if(outOfBounds != true){

        for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
            for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
                gebäude[i][j] = zuBauendesGebäude;
            }
        }

    }



}

void CapicitySim::printFläche() {

    int temp = 0;

    for(int i = 0; i < gebäude.size(); i++) {
        for(int j = 0; j < gebäude[i].size();j++) {
            std::cout << gebäude[i][j]->gebäudeName; std::cout << "\t\t";
        }
        std::cout << "\n\n";
    }

    for(int i = 0; i < gebäude.size(); i++) {
        for(int j = 0; j < gebäude[i].size();j++) {
            if(gebäude[i][j]->gebäudeID!=0) {
                temp += gebäude[i][j]->berechneKosten();
                cout << "[" << i << "][" << j << "]" << gebäude[i][j]->auflistung() << endl;
            }
        }
    }
    std::cout << "\n\nGesamtkosten:     " << temp<<"\n"<<endl;


}

void CapicitySim::hauptMenü() {

    bool loop = true;
    int choice, choice_gebäude, temp_startZeile, temp_startSpalte, temp_zeilenAnz, temp_spaltenAnz;



    while(loop == true) {
        cout << "Bitte wählen Sie ihre nächste Aktion\n" << endl;
        cout << "\t1. Gebäude setzen" << endl;
        cout << "\t2. Bereich löschen" << endl;
        cout << "\t3. Ausgaben des aktuellen Bauplans" << endl;
        cout << "\t4. Beenden\n" << endl;

        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Sie haben Gebäude setzen gewählt" << endl;

                cout << "Bitte Gebäudeart wählen" << endl;
                cout << "\t1. WASSERKRAFTWERK" << endl;
                cout << "\t2. WINDKRAFTWERK" << endl;
                cout << "\t3. SOLARPANEL\n" << endl;
                cin >> choice_gebäude;

                switch (choice_gebäude) {

                    case 1:
                        cout << "Sie haben Wasserkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebäudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                      temp_spaltenAnz, new Wasserkraftwerk());
                        break;

                    case 2:
                        cout << "Sie haben Windkraftwerk gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebäudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                      temp_spaltenAnz, new Windkraftwerk());

                        break;

                    case 3:
                        cout << "Sie haben Solarpanel gewählt\n" << endl;

                        cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                        cin >> temp_startZeile;

                        cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                        cin >> temp_startSpalte;

                        cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                        cin >> temp_zeilenAnz;

                        cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                        cin >> temp_spaltenAnz;

                        gebäudeSetzenMitTest(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                                      temp_spaltenAnz, new Solarpanel());

                        break;

                }

                break;

            case 2:
                cout << "Sie haben Bereich löschen gewählt" << endl;

                cout << "Bitte Startzeile (oberes linkes Gebäudeeck) eingeben\n";
                cin >> temp_startZeile;

                cout << "Bitte Startspalte (oberes linkes Gebäudeeck) eingben\n";
                cin >> temp_startSpalte;

                cout << "Bitte ZeilenAnzahl des Gebäudes eingben\n";
                cin >> temp_zeilenAnz;

                cout << "Bitte Spaltenanzahl des Gebäudes eingeben\n";
                cin >> temp_spaltenAnz;

                //Delete die Instanz vom vorherigen Builing solange der Pointer noch existiert --> keine MemoryLeaks
                //for(int i = temp_startZeile - 1; i < temp_startZeile - 1 + temp_zeilenAnz; i++){
                    //for(int j = temp_startSpalte - 1; j < temp_startSpalte - 1 + temp_spaltenAnz; j++){
                        //delete gebäude[i][j] ;
                    //}
                //}

                gebäudeSetzen(temp_startZeile, temp_startSpalte, temp_zeilenAnz,
                              temp_spaltenAnz, new Leer());

                break;

            case 3:
                cout << "Sie haben Ausgabe des aktuellen Bauplans gewählt\n" << endl;

                printFläche();

                break;

            case 4:
                cout << "Sie haben Beenden gewählt" << endl;
                loop = false;
                break;
        }

    }

}

void
CapicitySim::gebäudeSetzen(int startZeile, int startSpalte, int zeilenAnz, int spaltenAnz, Building* zuBauendesGebäude) {

    for(int i = startZeile - 1; i < startZeile - 1 + zeilenAnz; i++){
        for(int j = startSpalte - 1; j < startSpalte - 1 + spaltenAnz; j++){
            gebäude[i][j] = zuBauendesGebäude;
        }
    }

}




