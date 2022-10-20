#include<bits/stdc++.h>
#include "vars.h"

using namespace std;

vector <int> v;

vector <vector <char> > m = vector<vector<char> >(2, vector<char>(2));


void createVector()
{

    v.resize(longitudDelArray);

    for(int i = 0; i < longitudDelArray; ++i)
    {
        v[i] = i+1;
    }

    for(int o = 0; o < longitudDelArray*1.5; ++o)
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

void createMatrix()
{

    m.resize(longitudDelArray, vector <char> (longitudDelArray));

    for(int f = 0; f < longitudDelArray; ++f)
    {
        for(int c = 0; c < longitudDelArray; ++c)
        {
            m[f][c] = ' ';
        }

    }

    for(int c = 0; c < longitudDelArray; ++c)
    {
        for(int f = longitudDelArray-1; f >= (longitudDelArray-v[c]); --f)
        {
            m[f][c] = 'X';
        }


    }

}
