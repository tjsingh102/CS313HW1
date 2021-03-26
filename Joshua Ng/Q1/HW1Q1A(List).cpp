//Question 1 Part A (Linked List)
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

 struct node {
    int data;
    node* nextN;
};


class Linked_List{
    private:
    node *head, *tail;
    public:
    Linked_List() {
        head = nullptr;
        // tail = nullptr;
    }

    void firstnode(node *&head, node*& tail, int value){
        node *n = new node; //creates a new node
        n->data = value;   //set the value of this node
        n->nextN = nullptr;  //pointer to the next node
        head = n;
        tail = n;
    }

    bool isEmpty(node *head)  { // checks if node is empty 
        if (head == nullptr){ // Checks if the first node is empty & will return true if it is, else false
            return true;
        }
        else return false;
    }

    void insert(node *&head, node *&tail, int value){ // insert 1 value
        if (isEmpty(head)){
            firstnode(head, tail, value); // will insert the info on the first node
        }
        else{
            node *n = new node; // if first element if full, then you move on to the next nodes and change the positions
            n->data = value; // set num value inside node
            n->nextN = nullptr; // next node to equal NULL
            tail->nextN = n;
            tail = n;
        }
    }

    

    void printLinkList(node *current){
        while (current != NULL){ // while the current value is not NULL, print value inside node
            cout << "[" << current->data << "]" << "->";
            current = current->nextN; // change & advance the value of current to the next node
        }
    cout << endl;
    }

};

int main() {
    int value;
    
    //Timing the linked list
    auto Lbegin = high_resolution_clock::now(); //times the list
    //initialize
    Linked_List my_list;

    node* head = nullptr;
    node* last=  nullptr;

    srand(time(nullptr));

    for(int i=0; i<20; i++) {
        value = (rand() % 100 + 1);
        my_list.insert(head, last, value);
    }
    my_list.printLinkList(head);

    auto Lend = high_resolution_clock::now();
    auto Ltime = duration_cast<microseconds> (Lend - Lbegin).count();

    cout<<"Linked list took "<< Ltime << " microseconds."<<endl;


}