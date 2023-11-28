#include <iostream>
#include "sorts.hpp"

using namespace std;

void SortingAlgorithms::insertionSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void SortingAlgorithms::quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (array[j] < pivot)
            {
                i++;
                swap(array[i], array[j]);
            }
        }

        swap(array[i + 1], array[high]);

        int pi = i + 1;

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void SortingAlgorithms::radixSort(int array[], int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        int output[size];
        int count[10] = {0};

        for (int i = 0; i < size; i++)
        {
            count[(array[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
        {
            array[i] = output[i];
        }
    }
}

void SortingAlgorithms::heapSort(int array[], int size)
{
    buildMaxHeap(array, size);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void SortingAlgorithms::buildMaxHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }
}

void SortingAlgorithms::heapify(int array[], int heapSize, int rootIndex)
{
    int largest = rootIndex;
    int left = 2 * rootIndex + 1;
    int right = 2 * rootIndex + 2;

    if (left < heapSize && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < heapSize && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != rootIndex)
    {
        swap(array[rootIndex], array[largest]);
        heapify(array, heapSize, largest);
    }
}

void SortingAlgorithms::hybridSort(int array[], int size)
{
    /*
        determine which sorting algorithm to use based on size of input
        numbers are arbitrary and based on my own testing
        could be changed by testing on more data sets to find better ranges

        heap sort: 0 - 999
        radix sort: 1000 - 3000
        insertion sort: 3000 - 6000
        quick sort: 10000 - {infinity}
    */

    if (size < 1000)
    {
        heapSort(array, size);
        cout << "heap sort " << size << endl;
    }
    else if (size < 3000)
    {
        radixSort(array, size);
        cout << "radix sort " << size << endl;
    }
    else if (size < 6000)
    {
        quickSort(array, 0, size - 1);
        cout << "quick sort " << size << endl;
    }
    else
    {  
        insertionSort(array, size);
        cout << "insertion sort " << size << endl;
    }
}