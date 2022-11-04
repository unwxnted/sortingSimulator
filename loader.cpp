#include<bits/stdc++.h>
#include "vars.h"

using namespace std;

void loadStd(){

    cout << "Longitud del Array: ";
    cin >> longitudDelArray;
    cout << "Usar representacion grafica? " << endl << "1- Si"<< endl << "2- No" <<endl<<"[console]: ";
    cin >> useGraphic;
     cout << "Ingrese el Delay a usar: ";
    cin >> DELAY;

}

void loadFile(){

    ifstream in("input.txt");
    in >> longitudDelArray;
    in >> useGraphic;
    in >> DELAY;
}

void loader(){

    cout << "Que metodo de input vas a usar?" << endl << "1- Entrada estandar (teclado)" << endl << "2- Archivo de texto"<< endl <<"[console]: ";
    cin >> metodo;

    switch(metodo){
    case 1:
        loadStd();
        break;
    case 2:
        loadFile();
        break;

    }

}
