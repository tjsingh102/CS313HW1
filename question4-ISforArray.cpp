#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

void insertionSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int currentIndex = array[i];
        int j = i - 1;
        while (j >= 0 && currentIndex < array[j])       // moving the array values that are greater than the index by one index forward from their current position
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentIndex;        // make the larger value the new index to use against the array
    }
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)      // traversing the array and outputting each index
    {
        cout << array[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int size = 1000;
    int x[size];

    for (int i = 0; i < size; i++)          // creating a array of size 1000 and adding random values at each index
    {
        x[i] = rand() % 100 + 1;
    }

    print(x, size);         // printing the array before the sort

    auto begin = high_resolution_clock::now();  // beginning timer  

    insertionSort(x, size);                         // calling insertion sort function

    auto end = high_resolution_clock::now();        // ending timer

    auto duration = duration_cast<microseconds>(end - begin).count();       

    print(x, size);     // printing the array after the sort

    cout << "It took " << duration << " microseconds to sort the array using insertion sort. ";
}