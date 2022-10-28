#include <bits/stdc++.h>
#include <ctime>
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

void delay(int secs)
{
    for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL))
        ;
}

void waitInput()
{
    char k;
    cin >> k;
}

void graphicMatrix(vector<vector<char>> matrix, vector<int> l)
{
    if (useGraphic == 1)
    {

        for (int f = 0; f < longitudDelArray; ++f)
        {
            for (int c = 0; c < longitudDelArray; ++c)
            {
                matrix[f][c] = ' ';
            }
        }

        for (int c = 0; c < longitudDelArray; ++c)
        {
            for (int f = longitudDelArray - 1; f >= (longitudDelArray - l[c]); --f)
            {
                matrix[f][c] = 'X';
            }
        }

        for (int i = 0; i < longitudDelArray; i++)
        {
            for (int j = 0; j < longitudDelArray; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

vector<int> bubbleSort()
{

    vector<int> toSort = v;
    vector<vector<char>> mToSort = m;
    vector<int> stats;
    int toSortSize = toSort.size();
    int comparations = 0;
    int accessToMemory = 0;

    graphicMatrix(mToSort, toSort);
    cout << endl;

    for (int i = 0; i < toSortSize - 1; i++)
    {
        for (int j = 0; j < toSortSize - i - 1; j++)
        {
            comparations++;
            if (toSort[j] > toSort[j + 1])
            {
                swap(toSort[j + 1], toSort[j]);
                accessToMemory++;
                graphicMatrix(mToSort, toSort);
                cout << endl;
                delay(1.5);
            }
        }
    }

    cout << endl;

    for (int i = 0; i < longitudDelArray; ++i)
        cout << toSort[i] << " ";
    cout << endl;

    stats.push_back(comparations);
    stats.push_back(accessToMemory);
    return stats;
}

void merge(vector<int>&left, vector<int>& right, vector<int>& toSorts, vector<vector <char> > matrix)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            toSorts[i] = left[j];
            j++;
        }
        else {
            toSorts[i] = right[k];
            k++;
        }
        i++;
        //graphicMatrix(matrix, toSorts);
    }
    while (j < nL) {
        toSorts[i] = left[j];
        j++; i++;
        //graphicMatrix(matrix, toSorts);
    }
    while (k < nR) {
        toSorts[i] = right[k];
        k++; i++;
        //graphicMatrix(matrix, toSorts);
    }
}

void mergeAlgorithm(vector<int> & toSort, vector<vector <char> > matrix) {
    if (toSort.size() <= 1) return;

    int mid = toSort.size() / 2;
    vector<int> left;
    vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(toSort[j]);
    for (size_t j = 0; j < (toSort.size()) - mid; j++)
        right.push_back(toSort[mid + j]);

    graphicMatrix(matrix, toSort);
    mergeAlgorithm(left, matrix);
    graphicMatrix(matrix, toSort);
    mergeAlgorithm(right, matrix);
    graphicMatrix(matrix, toSort);
    merge(left, right, toSort, matrix);
}


vector<int> mergeSort()
{

    vector<int> toSort = v;
    vector<vector<char>> mToSort = m;
    vector<int> stats;
    int toSortSize = toSort.size();
    int comparations = 0;
    int accessToMemory = 0;

    for (int i = 0; i < longitudDelArray; ++i)
        cout << toSort[i] << " ";
    cout << endl;

    mergeAlgorithm(toSort, mToSort); 

    for (int i = 0; i < longitudDelArray; ++i)
        cout << toSort[i] << " ";
    cout << endl;

    stats.push_back(comparations);
    stats.push_back(accessToMemory);
    return stats;
}

void sorter()
{
    vector<int> stats(2);
    //stats = bubbleSort();
    /*cout << "bubbleSort finalizado." << endl
         << "Estadisticas: " << endl
         << "Comparaciones: " << stats[0] << endl
         << "Accesos a memoria: " << stats[1] << endl;*/

    waitInput();

    stats = mergeSort();
    cout << "Merge sort finalizado." << endl
         << "Estadisticas: " << endl
         << "Comparaciones: " << stats[0] << endl
         << "Accesos a memoria: " << stats[1] << endl;
}