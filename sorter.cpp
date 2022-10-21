#include <bits/stdc++.h>
#include "vars.h"

using namespace std;

/**
 * TODO:
 * bubble sort
 * merge sort
 * quicksort
 *
 * **/

vector<long long> stats(3, 0);

void graphicMatrix(vector<int> matrix)
{
    int matrixSize = m.size();
    if (useGraphic == 1)
    {

        for (int i = 0; i < matrixSize; i++)
        {
            for (int j = 0; j < matrixSize; j++)
            {
                cout << matrix[i] << " ";
            }
            cout << endl;
        }
    }
}

vector <int> bubbleSort()
{

    vector<int> toSort = v;
    vector <int> stats;
    int toSortSize = toSort.size();
    int comparations = 0;
    int accessToMemory = 0;

    graphicMatrix(toSort);

    for (int i = 0; i < toSortSize - 1; i++)
    {
        for (int j = 0; j < toSortSize - i - 1; j++)
        {
            comparations++;
            if (toSort[i] > toSort[j])
            {
                swap(toSort[i], toSort[j]);
                accessToMemory++;
                graphicMatrix(toSort);
            }
        }
    }

    stats.push_back(comparations);
    stats.push_back(accessToMemory);
    return stats;
}

void sorter()
{
    vector <int> stats(2);
    stats = bubbleSort();
    cout << "bubbleSort ended." << endl << "Estadisticas: " << endl << "Comparaciones: " << stats[0] << endl << "Accesos a memoria: " << stats[1] << endl;

}