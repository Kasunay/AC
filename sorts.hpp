#ifndef SORTS_HPP
#define SORTS_HPP

class SortingAlgorithms
{
public:
    static void insertionSort(int array[], int size);
    static void quickSort(int array[], int low, int high);
    static void radixSort(int array[], int size);
    static void heapSort(int array[], int size);
    static void hybridSort(int array[], int size);

private:
    static void buildMaxHeap(int array[], int size);
    static void heapify(int array[], int heapSize, int rootIndex);
    static int determineThreshold(int size);
};

#endif
