#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "sorts.hpp"

using namespace std;

void generateRandomData(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 10000;
    }
}

void quickSortWrapper(int array[], int size) // function to allow quickSort to be passed as a parameter
{
    SortingAlgorithms::quickSort(array, 0, size - 1);
}

double measureExecutionTime(int array[], int size, void (*sortingFunction)(int[], int))
{
    using namespace std::chrono;

    // used high_resolution_clock instead of steady_clock for more accuracy
    high_resolution_clock::time_point start = high_resolution_clock::now();
    sortingFunction(array, size);
    high_resolution_clock::time_point end = high_resolution_clock::now();

    duration<double> elapsedTime = duration_cast<duration<double>>(end - start);

    return elapsedTime.count();
}

void recordRawData(int dataSize, int array[], ofstream &dataFile, const string &algorithmName)
{
    dataFile << "Input Data for " << algorithmName << " (Size " << dataSize << "):\n";
    for (int i = 0; i < dataSize; ++i)
    {
        dataFile << array[i] << " ";
    }
    dataFile << "\n\n";
}

ofstream createDataFile(const string &filename)
{
    ofstream dataFile(filename);
    if (!dataFile.is_open())
    {
        cerr << "Unable to open data file for writing\n";
        exit(1);
    }

    dataFile << fixed << setprecision(8);
    dataFile << "Input Size,Insertion Sort Time,Quick Sort Time,Radix Sort Time,Heap Sort Time,Hybrid Sort Time\n";

    return dataFile;
}

void writeResultsDetailed(ofstream &dataFile, int dataSize, int testData[], int run) // for examining
{
    double insertionSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::insertionSort);
    double quickSortTime = measureExecutionTime(testData, dataSize, quickSortWrapper);
    double radixSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::radixSort);
    double heapSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::heapSort);
    double hybridSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::hybridSort);

    recordRawData(dataSize, testData, dataFile, "Insertion Sort");
    recordRawData(dataSize, testData, dataFile, "Quick Sort");
    recordRawData(dataSize, testData, dataFile, "Radix Sort");
    recordRawData(dataSize, testData, dataFile, "Heap Sort");
    recordRawData(dataSize, testData, dataFile, "Hybrid Sort");

    dataFile << dataSize << ","
             << insertionSortTime << ","
             << quickSortTime << ","
             << radixSortTime << ","
             << heapSortTime << ","
             << hybridSortTime << "\n";

    dataFile << "Input Size: " << dataSize << "\n";
    dataFile << "Run: " << run << "\n";
    dataFile << "Insertion Sort Time: " << insertionSortTime << " seconds\n";
    dataFile << "Quick Sort Time: " << quickSortTime << " seconds\n";
    dataFile << "Radix Sort Time: " << radixSortTime << " seconds\n";
    dataFile << "Heap Sort Time: " << heapSortTime << " seconds\n";
    dataFile << "Hybrid Sort Time: " << hybridSortTime << " seconds\n\n";
}

void writeResultsConcise(ofstream &dataFile, int dataSize, int testData[]) // for visualizing
{
    double insertionSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::insertionSort);
    double quickSortTime = measureExecutionTime(testData, dataSize, quickSortWrapper);
    double radixSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::radixSort);
    double heapSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::heapSort);
    double hybridSortTime = measureExecutionTime(testData, dataSize, SortingAlgorithms::hybridSort);

    dataFile << dataSize << ","
             << insertionSortTime << ","
             << quickSortTime << ","
             << radixSortTime << ","
             << heapSortTime << ","
             << hybridSortTime << "\n";
}

int main()
{
    srand(time(0));

    const int maxRuns = 4; // how many times to run each algorithm
    int stepSize = 4; // multiplier for increasing data size
    int dataSize = 100; // starting data size

    ofstream detailedDataFile = createDataFile("graph/results_detailed.csv");
    ofstream conciseDataFile = createDataFile("graph/results_concise.csv");

    for (int i = 0; i < maxRuns; ++i)
    {
        int *testData = new int[dataSize];

        generateRandomData(testData, dataSize);
        writeResultsDetailed(detailedDataFile, dataSize, testData, i + 1);
        writeResultsConcise(conciseDataFile, dataSize, testData);

        delete[] testData;
        dataSize *= stepSize;
    }

    detailedDataFile.close();
    conciseDataFile.close();

    return 0;
}
