#include <iostream>
#include <cassert>
#include <algorithm>
#include "sorts.hpp"

using namespace std;

// tests may not comprehensive, just testing if functions working as expected

bool isSorted(int array[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        if (array[i] < array[i - 1])
        {
            return false;
        }
    }
    return true;
}

void testInsertionSort()
{
    const int size = 10;
    int unsortedArray[size] = {5, 2, 9, 1, 5, 6, 8, 3, 7, 4};
    int sortedArray[size] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int reverseSortedArray[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int repeatedValuesArray[size] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    SortingAlgorithms::insertionSort(unsortedArray, size);
    assert(isSorted(unsortedArray, size));

    SortingAlgorithms::insertionSort(sortedArray, size);
    assert(isSorted(sortedArray, size));

    SortingAlgorithms::insertionSort(reverseSortedArray, size);
    assert(isSorted(reverseSortedArray, size));

    SortingAlgorithms::insertionSort(repeatedValuesArray, size);
    assert(isSorted(repeatedValuesArray, size));
}

void testQuickSort()
{
    const int size = 10;
    int unsortedArray[size] = {5, 2, 9, 1, 5, 6, 8, 3, 7, 4};
    int sortedArray[size] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int reverseSortedArray[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int repeatedValuesArray[size] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    SortingAlgorithms::quickSort(unsortedArray, 0, size - 1);
    assert(isSorted(unsortedArray, size));

    SortingAlgorithms::quickSort(sortedArray, 0, size - 1);
    assert(isSorted(sortedArray, size));

    SortingAlgorithms::quickSort(reverseSortedArray, 0, size - 1);
    assert(isSorted(reverseSortedArray, size));

    SortingAlgorithms::quickSort(repeatedValuesArray, 0, size - 1);
    assert(isSorted(repeatedValuesArray, size));
}

void testRadixSort()
{
    const int size = 10;
    int unsortedArray[size] = {5, 2, 9, 1, 5, 6, 8, 3, 7, 4};
    int sortedArray[size] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int reverseSortedArray[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int repeatedValuesArray[size] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    SortingAlgorithms::radixSort(unsortedArray, size);
    assert(isSorted(unsortedArray, size));

    SortingAlgorithms::radixSort(sortedArray, size);
    assert(isSorted(sortedArray, size));

    SortingAlgorithms::radixSort(reverseSortedArray, size);
    assert(isSorted(reverseSortedArray, size));

    SortingAlgorithms::radixSort(repeatedValuesArray, size);
    assert(isSorted(repeatedValuesArray, size));
}

void testHeapSort()
{
    const int size = 10;
    int unsortedArray[size] = {5, 2, 9, 1, 5, 6, 8, 3, 7, 4};
    int sortedArray[size] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};
    int reverseSortedArray[size] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int repeatedValuesArray[size] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    SortingAlgorithms::heapSort(unsortedArray, size);
    assert(isSorted(unsortedArray, size));

    SortingAlgorithms::heapSort(sortedArray, size);
    assert(isSorted(sortedArray, size));

    SortingAlgorithms::heapSort(reverseSortedArray, size);
    assert(isSorted(reverseSortedArray, size));

    SortingAlgorithms::heapSort(repeatedValuesArray, size);
    assert(isSorted(repeatedValuesArray, size));
}

int main()
{
    cout << "Running tests...\n";

    testInsertionSort();
    testQuickSort();
    testRadixSort();
    testHeapSort();

    cout << "All tests passed!\n";

    return 0;
}
