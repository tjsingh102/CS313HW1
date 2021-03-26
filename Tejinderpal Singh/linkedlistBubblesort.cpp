#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

class node {
    public:
    int data;           // data portion of node
    node* nextN;        // node pointer to next node 
};

class Linked_List {
    private:
    node *head, *tail;

    public:
  

    Linked_List() {
        head = nullptr;
        tail = nullptr;         // empty constructor setting the head and tail to point to nothing
    }

    void firstnode(node *&head, node*& tail, int value) {           //if the list is empty then this function will be called
    node *n = new node;             
    n->data = value;            //passing in the head and tail pointers by reference and creating a new node inside of the list
    n->nextN = nullptr;         //setting the next pointer of the node to nullptr because it is the only one in the list
    head = n;
    tail = n;
    }

    bool isEmpty(node *head)  {
        if (head == nullptr) 
        {
            return true;            //basic function that checks if the list is empty by checking if the head is pointing to anything
        }
        else return false;
    
    }

    

    void insert(node *&head, node *&tail, int value) { 
        if (isEmpty(head)) {
            firstnode(head, tail, value); 
        }
        else {
            node *n = new node;             // if the list is empty then call firstnode function
            n->data = value;                // otherwise create a new node and set the values of the node to what was passed in
            n->nextN = nullptr;             // next pointer to nullptr because we are adding it at the end 
            tail->nextN = n;                // the next pointer of the last node will now point to the new node since it is now the new tail
            tail = n;
        }
    }

};

void printLinkList(node *current) 
{
    
    while (current != NULL) 
    {
        cout << "[" << current->data << "]" << "->";        //travsersing the list using a while loop and outputting the data value in each node
        current = current->nextN; 
    }
    cout << endl;
}

node* swap(node* ptr1, node* ptr2) 
    { 
        node* tmp = ptr2->nextN;        //need a node temp pointer to store the value of the next pointer of the second node
        ptr2->nextN = ptr1;             // setting the next pointer of the second node to the first one
        ptr1->nextN = tmp;              // setting the next pointer of the first node to the next pointer of the second node 
        return ptr2; 
    }

int bubblesort(node** head, int size){
        int swapped;
        node** newNode;

        for(int i = 0; i < size; i++) {
            newNode = head;
            swapped = 0;

            for(int j = 0; j < size - i - 1; j++) {     //nested loop to keep sorting one less node than the previous iteration
                node* n1 = *newNode;
                node* n2 = n1->nextN;

                if(n1->data > n2->data) {           // comparing curent node against the one infront of it 
                    *newNode = swap(n1,n2);
                    swapped = 1;
                }
                newNode = &(*newNode)->nextN;
            }

            if(swapped == 0){
                break;

            }
        }
        return 0;
    }

int main() {
   
    Linked_List my_list;

    int value;
    node* head = nullptr;
    node* last=  nullptr;
    
    srand(time(nullptr));

    for(int i=0; i<1000; i++) {
        value = (rand() % 100 + 1);
        my_list.insert(head, last, value);      // inserting random values in the linked list 
    }
    cout<<"Before sort: "<<endl;
    printLinkList(head);
    cout<<"After sort: "<<endl;
    auto begin = high_resolution_clock::now();
    bubblesort(&head, 1000);                          // calling sort function
    auto end = high_resolution_clock::now();
    printLinkList(head);
    cout<<"End "<<endl;

    auto duration = duration_cast<microseconds>(end - begin).count();
    
    cout << "It took " << duration << " microseconds to sort the list using bubble sort. ";
}