#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

template <typename F>
class Vectorclass
{

    F *ptr; //f type pointer

    int storage; //capacity of vector

    int current_num_items; // # of elements in the vector

public:
    Vectorclass()
    {
    Public:
        ptr = new F[1];    // making the F ptr point to a new vector of type F
        storage = 1;
        current_num_items = 0;
    }

    void push(F value)
    {
        if (current_num_items == storage)    // if the vector is full
        {
            F *temp = new F[2 * storage]; // make a new vector that is double the size of the original

            for (int i = 0; i < storage; i++)   
            {
                temp[i] = ptr[i];       // copy the elements over 
            }

            delete[] ptr;       // delete the original vector
            storage *= 2;        // update the size of the vector
            ptr = temp;
        }

        ptr[current_num_items] = value;  // if the vector is not full, then simply add the value to the end of the vector 
        current_num_items++;
    }

    void insertion(F value, int position)
    {
        F *temp1 = new F[storage + 1];      //make a new vector with an increased storage size
        for (int i = 0; i < position; i++)  
        {
            temp1[i] = ptr[i];              //copy all the elements of the previous vector onto the new vector up until the position that is requested
        }

        temp1[position] = value;       // then add the value at the position requested

        for (int i = position + 1; i < storage; i++)    
        {
            temp1[i] = ptr[i - 1];          // starting from the position, add every value that was left to add
        }
        delete[] ptr;       // delete the original vector
        storage++; // increase storage by 1
        current_num_items++; 
    }
    void deletion(int position)
    {
        F *temp1 = new F(storage - 1);     // create new vector with one less storage space
        for (int i = 0; i < position; i++)   
        {   
            temp1[i] = ptr[i];      // same process as insertion but we are just removing the value here instead of adding it 
        }
        for (int i = position; i < storage; i++)
        {
            temp1[i] = ptr[i + 1];
        }

        delete[] ptr;
        storage--;
        current_num_items--;
    }
    F get(int position)
    {
        if (position < current_num_items)            // simple get function that returns the value at the requested position in a vector 
        {
            return ptr[position];
        }
    }

    void pop()
    {
        current_num_items--;             //manipulating the vector and "popping" the value at the end of the vector by decreasing the number of items in the vector by 1
    }

    int number_of_items()
    {
        return current_num_items;    // function that returns the current number of items in the vector
    }

    int getstorage()
    {
        return storage;     // basic function that returns size of vector
    }

    void print()
    {
        for (int i = 0; i < current_num_items; i++)
        {
            cout << ptr[i] << " ";          // outputs the values in the vector
        }
        cout << endl;
    }
    void generateVecWithChars(int size)
    {
        F *vec = new F[size];
        cout << endl;
        for (int i = 0; i <= size; ++i)         // generating a new vector and filling it with random characters
        {
            vec[i] = 'A' + rand() % 26;

            cout << vec[i];
        }
        cout << endl << endl;
    }
};

int main()
{

    auto begin = high_resolution_clock::now();  // beginning timer  

    Vectorclass<char> vec1;
    vec1.generateVecWithChars(100000); // creating new vector that contains 100,000 characters
 
    auto end = high_resolution_clock::now(); // ending timer

    auto duration1 = duration_cast<microseconds>(end - begin).count();

    cout << endl << "This is how long it took to complete this operation: " << duration1 << " mircoseconds." << endl;
}
