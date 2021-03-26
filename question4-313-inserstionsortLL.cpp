#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <stdlib.h>

using namespace std;
using namespace chrono;

struct node
{
    int data;    // data portion of node
    node *nextN; // node pointer to next node
};

class Linked_List
{
private:
    node *head, *tail; // empty constructor setting the head and tail to point to nothing

public:
    Linked_List()
    {
        head = nullptr;
    }

    void firstnode(node *&head, node *&tail, int value)
    { //if the list is empty then this function will be called
        node *n = new node;
        n->data = value;    //passing in the head and tail pointers by reference and creating a new node inside of the list
        n->nextN = nullptr; //setting the next pointer of the node to nullptr because it is the only one in the list
        head = n;
        tail = n;
    }

    bool isEmpty(node *head)
    {
        if (head == nullptr)
        { //basic function that checks if the list is empty by checking if the head is pointing to anything
            return true;
        }
        else
            return false;
    }

    void insert(node *&head, node *&tail, int value)
    {
        if (isEmpty(head))
        {
            firstnode(head, tail, value);
        }
        else
        {
            node *n = new node; // if the list is empty then call firstnode function
            n->data = value;    // otherwise create a new node and set the values of the node to what was passed in
            n->nextN = nullptr; // next pointer to nullptr because we are adding it at the end
            tail->nextN = n;    // the next pointer of the last node will now point to the new node since it is now the new tail
            tail = n;
        }
    }
};

void printLinkList(node *current)
{

    while (current != nullptr)
    {
        cout << "[" << current->data << "]" //travsersing the list using a while loop and outputting the data value in each node
             << "->";
        current = current->nextN;
    }
    cout << endl;
}

struct node *swap(struct node *ptr1, struct node *ptr2)
{
    struct node *tmp = ptr2->nextN; //need a node temp pointer to store the value of the next pointer of the second node
    ptr2->nextN = ptr1;             // setting the next pointer of the second node to the first one
    ptr1->nextN = tmp;              // setting the next pointer of the first node to the next pointer of the second node
    return ptr2;
}

void insertionSort(struct node *&head)
{
    if (head == nullptr || head->nextN == nullptr)
    {
        return;
    }
    struct node *ptr2 = head->nextN; //placeholder for next node
    while (ptr2 != nullptr)
    {
        int ptr2_data = ptr2->data; //put data of next node into placeholder
        int found = 0;              // variable to see if swapp occured
        struct node *ptr1 = head; // node to start from th beginning of the list
        while (ptr1 != ptr2)
        {
            if (ptr1->data > ptr2->data && found == 0)      
            {
                ptr2_data = ptr1->data; 
                ptr1->data = ptr2->data;            // swapping values 
                found = 1;  
                ptr1 = ptr1->nextN;                
            }
            else
            {
                if (found == 1)
                {
                    int temp = ptr2_data;
                    ptr2_data = ptr1->data;     
                    ptr1->data = temp;
                }
                ptr1 = ptr1->nextN;
            }
        }
        ptr1->data = ptr2_data;
        ptr2 = ptr2->nextN;
    }
}
int main()
{

    Linked_List my_list;

    int value;
    node *head = nullptr;
    node *last = nullptr;

    srand(time(nullptr));

    for (int i = 0; i < 1000; i++)
    {
        value = (rand() % 100 + 1);
        my_list.insert(head, last, value); // inserting  random values in the linked list
    }
    cout << "Before sort: " << endl;
    printLinkList(head);
    cout << "After sort: " << endl;
    auto begin = high_resolution_clock::now();
    insertionSort(head); // calling sort function
    auto end = high_resolution_clock::now();
    printLinkList(head);
    cout << "End " << endl;

    auto duration = duration_cast<microseconds>(end - begin).count();

    cout << "It took " << duration << " microseconds to sort the list using insertion sort. ";
}