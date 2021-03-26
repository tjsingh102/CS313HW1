#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

struct node
{
    char data;  // creating the data part of node
    node *nextN;    // node pointer to store next node 
};

class Linked_List
{
private:
    node *head, *tail; // making node head and tail pointers private 

public:
    void firstnode(node *&head, node *&tail, int value)
    {
        node *n = new node;     // this function is called if the linked list is isEmpty
        n->data = value;
        n->nextN = nullptr;  
        head = n;       // head and tail both point to n since this will be the first and only node in the list
        tail = n;
    }

    bool isEmpty(node *head)
    {
        if (head == nullptr)
        {
            return true;            //function that checks if the list is empty by checking if the head is pointing to nothing
        }   
        else
            return false;
    }

    void insert(node *&head, node *&tail, int value)
    { 
        if (isEmpty(head))
        {
            firstnode(head, tail, value);       //if the list is empty then add the node to list using the first node function
        }
        else
        {
            node *n = new node;
            n->data = value;
            n->nextN = nullptr;                 //setting the data value of the new node to the value that was passed through
            tail->nextN = n;                    //setting the next pointer of the last node in the list to the new node         
            tail = n;                          // then setting the tail to the new node
            cout << "[" << n->data << "]" << "->";
        }
    }
};

void printLinkList(node *current)
{
    cout << endl;
    while (current != nullptr)
    {
        cout << "[" << current->data << "]" << "->";            // basic print funtction that outputs the data as we traverse the list using a while loop  
        current = current->nextN;                               // the loop will print the data and then set current to the next node...
    }
    cout << endl << endl;
}

int main()
{
    cout << endl;
    auto begin = high_resolution_clock::now();  // beginning timer  
    Linked_List my_list;

    node *head = nullptr;
    node *last = nullptr;

    srand(time(nullptr));

    for (int i = 0; i <= 100000; i++)
    {
        char value = 'A' + rand() % 26;         // filling the linked list with 100,000 characters
        my_list.insert(head, last, value);
    }

    auto end = high_resolution_clock::now();  // ending timer

    cout << endl;

    auto duration1 = duration_cast<microseconds>(end - begin).count();

    cout << endl << "This is how long it took to complete this operation: " << duration1 << " mircoseconds." << endl;
}