//Question 1 Part A (Vector)
#include <iostream>
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

    //push function that vectors have
    void push(F value){ //take in a value type F so it can be any type
        if(curr == storage){ //if run out of space 
            F* temp = new F[2 * storage]; //increase the storage size
            //copy elements into new 
            for(int i =0; i < storage; i++) {
                temp[i] = ptr[i];
            }
            delete[] ptr; 
            storage *= 2; //update values
            ptr= temp;
        }
        ptr[curr] = value; //add the value into the end
        curr++;
    }

    //vector function to insert at a given position 
    void insertion(F value, int position ){
        F* temp1 = new F[storage + 1]; //add space
        for(int i = 0; i < position; i++){
            temp1[i] = ptr[i]; //copy values into new up until the position we want        
        }
        temp1[position] = value; //add the value into position
        for(int i = position+1; i < storage; i++){
            temp1[i] = ptr[i-1]; //continue the rest
        }
        delete[]ptr;
        storage++;
        ptr = temp1;  
        curr++;
    }
    
    //vector function to delete a value at a given position
    void deletion(int position){
        F* temp1 = new F(storage - 1); //remove storage space
        for(int i = 0; i < position; i++){
            temp1[i] = ptr[i]; //up until position, copy values 
        }
        for(int i = position; i < storage; i++){
            temp1[i] = ptr[i+1]; //skip position we want to get rid of and continue copy
        }
        delete[] ptr;
        storage--;
        ptr = temp1;
        curr--;
    }
    
    F get(int position) {
        if(position < curr) {
            return ptr[position];
        }
    }

    void pop() { curr--; } //simply remove the end

    int size() { return curr;} 

    int getstorage() { return storage;}

    void print( ) {
        for(int i = 0; i < curr; i++) {
            cout<< ptr[i] << " ";
        }
        cout<<endl;
    }
    
    void generateVecWithNumbs(int num){
      F* vec = new F[num];
      for(int i = 0; i < num; i++){
          vec[i]= (rand() % 100 + 1); //insert values from 1-100 into the vector
      }
      for(int i = 0; i < num; i++) { //print
          cout << vec[i] << " ";
      }
      cout<<endl;
    }
};



int main() {
    
    srand(time(nullptr));

    auto begin = high_resolution_clock::now();

    Vectorclass <int> vec1;
    vec1.generateVecWithNumbs(20);

   auto end = high_resolution_clock::now();

   auto duration1 = duration_cast<microseconds>( end - begin ).count();

   cout << duration1; 
    
}

