//Question 1 Part B (Vector)
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

template <typename F> class Vectorclass{
    //f type pointer 
    F* ptr;
    //capacity of vector
    int storage;
    // # of elements in the vector
    int curr;
    public:
        Vectorclass() {
        Public:
            ptr = new F[1];
            storage = 1;
            curr = 0;
        }

    void push(F value) {
        if(curr == storage) {
            F* temp = new F[2 * storage];
            //copy elements new 
            for(int i = 0; i < storage; i++) {
                temp[i] = ptr[i];
            }
            delete[] ptr;
            storage *= 2;
            ptr= temp;
        }
        ptr[curr] = value;
        curr++;
    }

    void insertion(F value, int position ){
        F* temp1 = new F[storage + 1]; 
        for(int i = 0; i < position; i++){
            temp1[i] = ptr[i];        
        }
        temp1[position] = value; 
        for(int i = position+1; i < storage; i++){
            temp1[i] = ptr[i-1];
        }
        delete[]ptr;
        storage ++;
        ptr = temp1;  
        curr++;
    }
    
    void deletion(int position){
        F* temp1 = new F(storage - 1);
        for(int i = 0; i < position; i++){
            temp1[i] = ptr[i];
        }
        for(int i = position; i < storage; i++){
            temp1[i] = ptr[i+1];
        }
        delete[] ptr;
        storage --;
        ptr = temp1;
        curr--;
    }
    
    F get(int position){
        if(position < curr){
            return ptr[position];
        }
    }

    void pop() { curr--; }

    int size() { return curr;}

    int getstorage() { return storage;}

    void print( ) {
        for(int i = 0; i < curr; i++) {
            cout<< ptr[i] << " ";
        }
        cout<<endl;
    }

    void generateVecWithStrings(int num){
    F* vec = new F[num];
    int length = 5;
    int r;
        for( int i = 0; i < num ; ++i){ // outer loop responsible for amount of strings built
            for( int j = 0; j < length; ++j){ // inner loop responsible for length of string
                r = rand() % 26;   // generate a random number and store in r
                vec[i] = 'a' + r; // Convert to a character from a-z and store in i'th place in vector
                cout<< vec[i]; // print the value in the i'th place of vector
            }
        cout<< endl;
        }
    }
};





int main() {

    auto begin = high_resolution_clock::now();

    Vectorclass <string> vec1;
    vec1.generateVecWithStrings(20);

     auto end = high_resolution_clock::now();

     auto duration1 = duration_cast<microseconds>( end - begin ).count();

    cout << duration1; 
    
}
