#include <iostream> 
#include <time.h>
#include <ctime>
#include <chrono>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using namespace std::chrono;
// swapping addresses of values
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[],int size) {
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//
void sortY(int arr[], int size) { //insertion sort
    if(size > 10) {
        cout<<"\nNumber of unsorted elements in the array is now less than 10. Will complete sorting here."<<endl;
    }
    if(size < 10) {
        cout<<"Array size is less than 10 so we will finsih sorting completely here.\n";
    }


    int elem,y;
    for(int i = 1; i < size; i++) {
        elem = arr[i];
        y = i - 1;
        while(y >= 0 && arr[y] > elem) { // 1 5 4 // does another loop and sees 1 i not greater than 4 so breaks out of while loop
            arr[y+1]= arr[y];            // 1   5
            y = y-1;
        }
        arr[y + 1] = elem;   // 1 4 5 finally index 1 has the element we compared
    }
}

//This sortX is used only when the array is greater than 10. We will be using selectionsort method for all the elements until the number of sorted elements
//is less than 10. Then we will call the function sortY() where we will switch over to the new function and finish sorting the rest of the elements their. 
void sortX(int arr[], int size) { // selectionsort
    int x,y,min;
    int switchF = size; // counter for the number of elements sorted in the array
    cout<<"\nWill use SortX until the number of unsorted numbers in the array is less than 10 \n"<<endl;
    for(x = 0; x < size - 1; x++) {
        if(switchF < 10) { // makes sure if the number of sorted elements is less than 10 then we print the statement and break out the loop to go to sortY 
            cout<<"The size of unsorted array is now less than 10. We will switch to the sortY function to finish sorting completely.\n";
            print(arr,size);
            break;
        }
        min = x;
        for(y = x+1; y < size; y++) {
            //compares the elements in the array to the first index and it will swap with the smallest value then we have the smallest value at index 0 
            //and we move on to the next index and compare to all elements to the right of it. 
            if(arr[y] < arr[min]) {         //  3 4 1
                swap(&arr[min], &arr[y]); 
            }
        }
        switchF--;
    }
    sortY(arr,size);
    
}


void pickSort(int arr[], int size) {
    // this function checks which of the sorting functions we will be using first. If the array is greater than 10 then we will call sortX.
    // If not then sortY
    if(size > 10) {
        sortX(arr,size);
    }
    else{
        sortY(arr,size);
    }
}

int main () {
    //hard code array 
    int arr1[] = {5,34,24,53,1,1,24,45,6,1,8,7,867,6}; //14
    int arr2[] = {5,11,24,53,7,1,24,47,1,8,0,867,6};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    auto start = high_resolution_clock::now(); //
    cout<<"What your array looks like before sorting: "<<endl;
    print(arr1, size);

    pickSort(arr1,size);
    cout<<"Array completely sorted: "<<endl;
    print(arr1,size);

    auto end = high_resolution_clock::now(); //
    auto time = duration_cast<microseconds> (end - start); //end of time
    cout<<"Time taken is: " <<time.count()<<"microseconds\n"<<endl;
    
    
    cout<<"First sorting library: "<<endl;
    auto t1 = high_resolution_clock::now();
    sort(arr2, arr2 + size2);
    print(arr2,size2);
    auto t2 = high_resolution_clock::now();

    auto t3 = duration_cast<microseconds> (t2 - t1);
    cout<<"Time taken is: " <<t3.count()<<" microseconds.\n"<<endl;

}