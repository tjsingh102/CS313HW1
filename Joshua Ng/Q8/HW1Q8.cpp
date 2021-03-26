//Question 8
#include <iostream>
#include <ctime>

using namespace std;

//templated class with type T so we can pass any type in to replace T
template <class T>
void findAddends(T array[], int size, T s){
  int count = 0; 
    //brute force method to find a pair of addends
    for (int i = 0; i < size; i++){ //have a first possible addend
      for (int j = i + 1; j < size; j++){ //iterate through the array to find the second addend
        if (array[i] + array[j] == s){
          cout << "(" << array[i] << ", " << array[j] <<  ")" << endl;
          count++;
        }
      }
    }
  if (count == 0) cout << "Two addends weren't found\n";

  int counter =0;
    //brute force method to find three addends
    for (int i = 0; i < size - 2; i++){ //have a possible first addend (we do size - 2 because there wont be space to look for 2 more addends if we are at the end of the array)
      for (int j = i + 1; j < size - 1; j++){ //iterate to find a second possible addend 
        for (int k = j + 1; k < size; k++){ //find the last addend
          if (array[i] + array[j] + array[k] == s){ 
            cout << array[i] << ", " << array[j] << ", " << array[k] << endl; 
            counter++; 
          } 
        } 
      } 
    } 
  if (counter == 0) cout << "Three addends weren't found\n";
} 
  
int main(){
  int size, sumGoal;
  cout << "Please enter the size you want: \n";
  cin >> size;
  int randomArray[size];
  cout << "Enter a number: \n";
  cin >> sumGoal; 
  
  //creation of a random array with a user input size
  cout << "Array is: ";
  for (int i = 0; i < size; i++){
    randomArray[i] = rand()%20+1;
    cout << randomArray[i] << " ";
  }
  cout << endl;
  
  //calling function with type cast
  findAddends<int>(randomArray, size, sumGoal);

  return 0;
}