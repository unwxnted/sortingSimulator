#include <bits/stdc++.h>
#include "loader.cpp"
#include "creator.cpp"
#include "vars.h"
#include "sorter.cpp"

using namespace std;

int main()
{
    loader();
    createVector();
    if(useGraphic == 1){
        createMatrix();
    }
    sorter();


    return 0;
}
