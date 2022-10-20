#include <bits/stdc++.h>
#include "loader.cpp"
#include "creator.cpp"
#include "vars.h"

using namespace std;

int main()
{
    loader();
    createVector();
    if(useGraphic == 1){
        createMatrix();
    }


    return 0;
}
