#include <bits/stdc++.h>
#include <ctime>
#include <stdlib.h>
#include "vars.h"

using namespace std;

vector<long long> stats(3, 0);

void delay(int secs)
{
    for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL))
        ;
}

void waitInput()
{
    getchar();
}

void clearConsole()
{
    system("clear");
}

void graphicVector(vector<int> l)
{
    for (int i = 0; i < l.size(); i++)
    {
        cout << l[i] << " ";
    }
    cout << endl;
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

    clearConsole();
    delay(DELAY);
    graphicMatrix(mToSort, toSort);
    cout << endl;
    graphicVector(toSort);
    delay(DELAY);
    clearConsole();

    for (int i = 0; i < toSortSize - 1; i++)
    {
        for (int j = 0; j < toSortSize - i - 1; j++)
        {
            comparations++;
            if (toSort[j] > toSort[j + 1])
            {
                swap(toSort[j + 1], toSort[j]);
                accessToMemory += 2;
                graphicMatrix(mToSort, toSort);
                cout << endl;
                graphicVector(toSort);
                delay(DELAY);
                clearConsole();
            }
        }
    }

    graphicMatrix(mToSort, toSort);
    cout << endl;
    graphicVector(toSort);
    delay(DELAY);

    stats.push_back(comparations);
    stats.push_back(accessToMemory);
    return stats;
}

vector<int> insertionSort()
{

    vector<int> toSort = v;
    vector<vector<char>> mToSort = m;
    vector<int> stats;
    int toSortSize = toSort.size();
    int comparations = 0;
    int accessToMemory = 0;

    clearConsole();
    delay(DELAY);
    graphicMatrix(mToSort, toSort);
    cout << endl;
    graphicVector(toSort);
    delay(DELAY);
    clearConsole();

    int pivot, k;
    for (int i = 0; i < longitudDelArray; ++i)
    {
        pivot = toSort[i];
        accessToMemory++;
        k = i - 1;

        while (k >= 0 && toSort[k] > pivot)
        {
            comparations++;
            toSort[k + 1] = toSort[k];
            graphicMatrix(mToSort, toSort);
            cout << endl;
            graphicVector(toSort);
            delay(DELAY);
            clearConsole();
            accessToMemory += 2;
            k--;
        }
        toSort[k + 1] = pivot;
        accessToMemory++;
    }

    graphicMatrix(mToSort, toSort);
    delay(DELAY);
    cout << endl;

    graphicVector(toSort);

    stats.push_back(comparations);
    stats.push_back(accessToMemory);
    return stats;
}

void quickSortAlgorithm(vector<int> a, int primero, int ultimo, vector<vector<char>> mToSort)
{

    int i, j, central;
    int pivote;
    central = (primero + ultimo) / 2;
    pivote = a[central];
    i = primero;
    j = ultimo;
    do
    {
        while (a[i] < pivote)
            i++;
        while (a[j] > pivote)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

        clearConsole();
        graphicMatrix(mToSort, a);
        cout << endl;
        graphicVector(a);
        delay(DELAY);

    } while (i <= j);
    if (primero < j)
    {
        quickSortAlgorithm(a, primero, j, mToSort);
    }

    if (i < ultimo)
    {
        quickSortAlgorithm(a, i, ultimo, mToSort);
    }
}

vector<int> quickSort()
{
    vector<int> toSort = v;
    vector<vector<char>> mToSort = m;
    vector<int> stats;
    int toSortSize = toSort.size();
    int comparations = 0;
    int accessToMemory = 0;

    clearConsole();
    delay(DELAY);
    graphicMatrix(mToSort, toSort);
    cout << endl;
    graphicVector(toSort);
    delay(DELAY);

    quickSortAlgorithm(toSort, 0, toSortSize - 1, mToSort);

    stats.push_back(toSortSize * (log2(toSortSize)));
    stats.push_back((toSortSize * (log2(toSortSize))) / 2);
    return stats;
}

void sorter()
{
    vector<int> stats(2);
    /*stats = bubbleSort();
    cout << "Bubble Sort finalizado." << endl
         << "Estadisticas: " << endl
         << "Comparaciones: " << stats[0] << endl
         << "Accesos a memoria: " << stats[1] << endl;

    waitInput();
    waitInput();

    stats = insertionSort();
    cout << "Insertion sort finalizado." << endl
         << "Estadisticas: " << endl
         << "Comparaciones: " << stats[0] << endl
         << "Accesos a memoria: " << stats[1] << endl;

    waitInput();*/

    stats = quickSort();
    cout << "Quick sort finalizado." << endl
         << "Estadisticas: " << endl
         << "Comparaciones: " << stats[0] << endl
         << "Accesos a memoria: " << stats[1] << endl;
}