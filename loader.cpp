#include<bits/stdc++.h>
#include "vars.h"

using namespace std;

void loadStd(){

    cout << "Longitud del Array: ";
    cin >> longitudDelArray;
    cout << "Usar representacion grafica? " << endl << "1- Si"<< endl << "2- No" <<endl<<"[console]: ";
    cin >> useGraphic;

}

void loadFile(){

    ifstream in("input.txt");
    in >> longitudDelArray;
    in >> useGraphic;
}

void loader(){

    cout << "Que metodo de input vas a usar?" << endl << "1- entrada estandar (teclado)" << endl << "2- archivo de texto"<< endl <<"[console]: ";
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
