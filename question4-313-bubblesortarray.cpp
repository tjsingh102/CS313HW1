#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

void swap(int &x, int &y)
{
    int temp = x; // swap function that passes in x and y by reference
    x = y;        // need to have temp to store x because we dont need the value to put into y at the end
    y = temp;
}
void sortArray(int *x, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)          // nested loop to sort items and then run through them again started from the next index
    {
        for (j = 0; j < size - i - 1; j++)          // last i items are already sorted so we dont need to run through them again
        {
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);       // swaps if the value to the left is greater than the value to the right of ahead of it 
        }
    }
}
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)              //traversing the array and outputting value at each index
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size = 1000;
    int testArray[size];

    for (int i = 0; i < size; i++)
    {
        testArray[i] = rand() % 100 + 1;        // creating an array of size 20 and adding random values at each index
    }
    printArray(testArray, size);                //printing the array before the sort

    auto begin = high_resolution_clock::now();   // beginning timer

    sortArray(testArray, size);     //calling bubble sort function

    auto end = high_resolution_clock::now();    // ending timer

    auto duration = duration_cast<microseconds>(end - begin).count();

    printArray(testArray, size);        // printing the array after sorting

    cout << "It took " << duration << " microseconds to sort the array using bubble sort. ";
}