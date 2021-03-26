//Question 1 Part B (Linked List)
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

struct node{
    string data;
    node* nextN;
};


class Linked_List{
    private:
    node *head, *tail;
    
    public:
        Linked_List() {
            head = nullptr;
            tail = nullptr;
        }

    void firstnode(node *&head, node*& tail, string value){
        node *n = new node; //creates a new node
        n->data = value;   //set the value of this node
        n->nextN = nullptr;    //pointer to the next node
        head = n;
        tail = n;
    }

    bool isEmpty(node *head) { // checks if node is empty //
        if (head == nullptr){ // Checks if the first node is empty & will return true if it is, else false
            return true;
        }
        else return false;
    }

    void insert(node *head, node *tail, string value){ // insert 1 r
        if (isEmpty(head)){
            firstnode(head, tail, value); // will insert the info on the first node
        }
        else{
            node *n = new node; // if first element if full, then you move on to the next nodes and change the positions
            n->data = value; // set num r inside node
            n->nextN = nullptr; // next node to equal NULL
            tail->nextN = n;
            tail = n;
        }
    }

    void createLstring(int size){
        int length= 5;
        int r;
        for(int i = 0; i<size; i++) {
            string letter;
            for(int j=0; j<length; j++) {
                r = rand() % 26;
                letter +='A' + r; 
            }
            insert(head,tail,letter);
        }
        printLinkList(head);
    }

    void printLinkList(node *curent){ // print list
        while (curent != NULL){ // while the curent r is not NULL, print r inside node
            cout << "[" << curent->data << "]" << "->";
            curent = curent->nextN; // change & advance the r of curent to the next node
        }
        cout << endl;
    }
};

int main() {
    
    
    //Timing the linked list
    auto Lbegin = high_resolution_clock::now(); //times the list
    //initialize
    Linked_List my_list;

    node* head = nullptr;
    node* last=  nullptr;

    srand(time(nullptr));

    my_list.createLstring(20);

    auto Lend = high_resolution_clock::now();
    auto Ltime = duration_cast<microseconds> (Lend - Lbegin).count();

    cout<<"Linked list took "<< Ltime << " microseconds."<<endl;


}