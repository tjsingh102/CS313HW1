//Question 2
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

//class node in order to create node objects and link them to make a linked list
class node{
  public:
    int data;
    node *next;
};

//function to generate a random array, then sort using insertion sort method
int * insertionSort(int array[], int size){
  srand(time(0));
  //creating array filled with random values
  for(int i = 0; i < size; i++){
    array[i] = rand();
  }
  //sorting portion begins, trail follows behind our iterating variable 'i' and temporary holds the value held at the i position in the array 
  int trail, temporary;
  for (int i = 1; i < size; i++){
     trail = i;
     temporary = array[i];
     while (trail > 0 && temporary < array[trail-1]){ 
       //as long as the trail does not reach past the very beginning of the array and the value at position i is less than the value that comes before it
        array[trail] = array[trail-1]; //put the bigger value from the index before our current one into the index that we are at (moving over one place)
        trail--; //decrement the index to continue checking
     }
     array[trail] = temporary; //trail has been decremented so it is the position before our current index, set the value equal to the incoming lesser value (move from the end inwards)
 }
 /*for (int i = 0; i < size; i++){
   cout << array[i] << endl;
 }*/
  return array;
}

//function to create linked list
node* linkedListCreate(int array[], int size){
  //to keep it consistent for testing, i just passed in the random array we generated in the above function
  node * head = new node; //initialize the beginning of the list with a head node
  head->data = array[0]; //put the first array value into the head
  node * n = new node; //initialize a new node that is linked to the head
  head->next = n;
  for (int i = 1; i < size; i++){
    n->data = array[i]; //put data into the node
    n->next = new node; //create a linked new node
    n = n->next; //set the new node as our current node for iteration
  }
  cout << "I just made the linkedlist.\n";
  return head;
}

//normal binary search function that takes in the array, the number we are looking for, and the size of the array
int iterativeBinarySearch(int array[], int searchNumber, int size){
  cout << "The number we're searching for is " << searchNumber << ".\n";
  int left = 0; //left side of the array
  int right = size; //right side of the array 
  int midpoint = (left + right)/2; //midpoint is in between left and right
  while(left <= right){ //if left ever passes right, means value was not found between the two
    if (searchNumber < array[midpoint]){
      right = midpoint - 1; //so we check only the left half of the array
      midpoint = (left+right)/2; //re-set midpoint 
    }
    else if (searchNumber > array[midpoint]){
      left = midpoint + 1; //check only right half of the array
      midpoint = (left+right)/2;
    }
    else{ //we found the number at midpoint position
      cout << "The number " << array[midpoint] << " is at position " << midpoint << endl;
      return midpoint; 
    }//if equal to array[midpoint] then we found our number position
  }
  cout << "Didn't find it.\n";
  return -1; //if left greater than right, havent found
}

int recursiveBinarySearch(int array[], int searchNumber, int left, int right){
  int midpoint = (left+right)/2;
  while(left <= right){
    if (array[midpoint] == searchNumber){ //base case, once midpoint value has the number we're looking for, return it's position
      cout << "The number " << array[midpoint] << " is at position "<< midpoint << endl;
      return midpoint;
      }
    if (searchNumber < array[midpoint]) return recursiveBinarySearch(array, searchNumber, left, midpoint -1); //re-call the function recursively but with the right half cut off
    if (searchNumber > array[midpoint]) return recursiveBinarySearch(array, searchNumber, midpoint + 1, right); //re-call the function recursively but with the left half cut off
  }
  cout << "Didn't recursively find it,\n";
  return -1;
}

int linkedTypeBinarySearch(node * head, int searchNumber, int size){
  int left = 0;
  int right = size;
  int index = (left+right)/2;
  while(left <= right){ //if left ever passes right, means value was not found between the two
  node * midpoint = head;
    for (int i = 0; i <= index; i++){
      midpoint = midpoint->next; //finding true middle for that iteration
    }
    if (searchNumber < midpoint->data){
      right = index - 1;
      index = (left+right)/2;
    }
    else if (searchNumber > midpoint->data){
      left = index + 1;
      index = (left+right)/2;
    }
    else{ 
      cout << "The number " << midpoint->data << " is at position " << index+1<< " in linked binary" << endl;
      return index; 
    } 
  }
  cout << "Didn't find it in linked binary.\n";
  return -1; //if left greater than right, havent found
}

int main() {
  srand(time(0));
  int size = 10000000; //size can be changed to test between 1 million and 10 million
  int * x = new int[size];
  insertionSort(x, size);

  int value = x[rand() % 100];
  
  //timing for iterative binary search
  auto begin = high_resolution_clock::now();
  iterativeBinarySearch(x, value, size);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( end - begin ).count();
  cout << "It took " << duration << " microseconds to find the number using iterative binary search.\n";

  //removing auto bc if use type then it thinks youre instantiating new one, but just variable means reassigning
  //timing for recursive binary search
  begin = high_resolution_clock::now();
  recursiveBinarySearch(x, value, 0, size - 1);
  end = high_resolution_clock::now(); 
  duration = duration_cast<microseconds>( end - begin ).count();
  cout << "It took " << duration << " microseconds to find the number using recursive binary search.\n";

  //timing for linked type binary search
  node * head = linkedListCreate(x, size);
  begin = high_resolution_clock::now();
  linkedTypeBinarySearch(head, value, size);
  end = high_resolution_clock::now(); 
  duration = duration_cast<microseconds>( end - begin ).count();
  cout << "It took " << duration << " microseconds to find the number using linked binary search.\n";
  
  return 0;
}