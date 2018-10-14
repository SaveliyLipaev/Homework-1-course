#pragma once

void bubble(int *mas, const int length);  // - bubble sort.

void heapSort(int *mas, const int length); // - heap sort, use function siftingGown.

void sortingCounting(int *mas, const int length); // - couting sort.

void sortingInsert(int* mas, int left, int right); // - insert sort.

void siftingDown(int *mas, int root, const int border); // - function sifting large elements in a binary tree up.

bool binSearch(int* mas, const int left, const int right, const int searchVeriable); // - binary search. 

int mostCommonElementInSortArray(int *mas, const int length); // - finds the most common element in the separated array.

int mostCommonElement(int *mas, const int length); // - the function finds the most common element in the array
                                                   //uses the heapSort and mostCommonElementInSortArray functions.
void printMas(int *mas, const int length); // - prints an array.

void swap(int& a, int& b); // - swap elements.

int amountSeriesOfCharacters(FILE *file); // - returns the number of series of characters.

int maxLengthSeriesOfCharacter(FILE *file); // - returns the length of the maximum character series.
