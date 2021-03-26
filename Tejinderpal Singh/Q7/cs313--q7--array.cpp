#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std; 
using namespace chrono; 

void genCharArray(int size){
    char *char_Array = new char[size];
    cout << endl; 
    for (int i = 0; i <= size; i++){        // creating a char array and filling it with random characters
        char_Array[i] = 'A' + rand() % 26; 
        cout << char_Array[i];
    }
    cout << endl << endl; 
}
int main(){
    auto begin = high_resolution_clock::now();      // beginning timer
    genCharArray(100000);                           // filling array with 100,000 characters
    auto end = high_resolution_clock::now();       // ending timer

   cout << endl; 

    auto duration1 = duration_cast<microseconds>(end - begin).count();

   cout << endl << "This is how long it took to complete this operation: " << duration1 << " mircoseconds." << endl;
}