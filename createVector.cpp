#include<bits/stdc++.h>
#include "vars.h"

using namespace std;

vector <int> v;

void createVector()
{

    v.resize(longitudDelArray);

    for(int i = 0; i < longitudDelArray; ++i)
    {
        v[i] = i;
    }

    for(int o = 0; o < longitudDelArray; ++o)
    {
        for(int i = 0; i < longitudDelArray; ++i)
        {
            for(int k = i; k < longitudDelArray-1; ++k)
            {
                swap(v[k], v[k+1]);
            }
        }
    }

}
