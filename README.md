# SortingSimulator
### Description
This project is made it for a expo of my technical school, it´s based on all the knowledge that I have been learning during the last months in competitive programming.

In this project you gonna view 3 sorting algorithms: BubbleSort, InsertionSort and QuickSort.

And sorry for the outputs on spanish, but it´s my original language.

## How to Compile

Use MinGW compiler for c++,
and This plugin for compile in Visual Studio Code: danielpinto8zz6.c-cpp-compile-run

## How it works

This program will show you how is the proccess of the differents sorting algorithms, these algorithms will be: BubbleSort, InsertionSort, QuickSort.

### BubbleSort
It works by checking each item in the list to be sorted with the next, swapping them if they are in the wrong order. It is necessary to go through the entire list several times until no more exchanges are needed, which means that the list is sorted.

### InsertionSort
Initially there is only one element, which is obviously an ordered set. Then, when there are k k items sorted from smallest to largest, element k + 1 is taken and compared with all elements already sorted, stopping when a smallest element is found (all largest elements have been shifted one position to the right) or when no items are found anymore (all items were moved and this is the smallest). At this point, element k + 1 is inserted, and the other elements must be moved.

### QuickSort
The algorithm works as follows:

- Choose an element from the set of elements to order, which we will call pivot.

- Relocate the other elements of the list on each side of the pivot, so that all the smaller ones are on one side, and the larger ones are on the other. Elements equal to the pivot can be placed either to its right or to its left, depending on the desired implementation. At this point, the pivot occupies exactly its rightful place in the sorted list.

- The list is separated into two sublists, one formed by the elements to the left of the pivot, and another by the elements to its right.

- Repeat this process recursively for each sublist as long as they contain more than one element. Once this process is finished, all the elements will be ordered.
