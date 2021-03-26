#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;

struct node {
    int data;
    node* nextN;
};

class linked_list {
    private: 
    node *head,*Evenhead, *Oddhead, *lastEven, *lastOdd;
    
    public:
    linked_list() {
        Evenhead = nullptr;
        Oddhead = nullptr;
        lastEven = nullptr;
        lastOdd = nullptr;
    }

     void firstnode(node *&head, node*& tail, int value) {
        node *n = new node; //creates a new node
        n->data = value;   //set the value of this node
        n->nextN = nullptr;    //pointer to the next node
        head = n;
        tail = n;
    }

    bool isEmpty(node *head)  { // checks if node is empty //
        if (head == nullptr) // Checks if the first node is empty & will return true if it is, else false
        {
            return true;
        }
        else return false;
    
    }

    void insert(node *&head, node *&tail, int value) { // insert 1 value
        if (isEmpty(head)) {
            firstnode(head, tail, value); // will insert the info on the first node
        }
        else {
            node *n = new node; // if first element is full create new node
            n->data = value; // set num value inside node
            n->nextN = nullptr; // next node to equal NULL
            tail->nextN = n;
            tail = n;
        }
    }

    void OddEvenList(node* current) {
        while(current != nullptr) {

            if((current->data) % 2 == 0) { 
                if(Evenhead == nullptr) { //if E.H is equal to nullptr then that means the current node is the first evennode passed in
                    Evenhead = lastEven = current; // initialize both to the current node(first even node)
                }
                else{
                    lastEven->nextN = current; // the pointer of L.E will  now point to the current node(next even node)
                    lastEven = current; // update the last even node to the current node we just passed in 
                }
            }

            if((current->data) % 2 == 1) {
                if(Oddhead == nullptr) { // if O.H is = null that means its the first odd node passed in
                    Oddhead = lastOdd = current; // initialize both to the first odd node
                }
                else {
                    lastOdd->nextN = current; // our L.O node will now point to the current node we passed in(the next odd node)
                    lastOdd = current; // the last odd node is updated to the current node we just passed in.
                } 
            }
            current = current->nextN; // go to the next node of the list
        }
        if(Oddhead != nullptr) { // if there are values in the oddhead
            head = Oddhead; //head node will equal to the oddhead node
            lastOdd->nextN = Evenhead; // the last odd node will now point to the first evenhead node
            lastEven->nextN = nullptr; // the last even head node will point to nullptr so that everything is in order.
        }
        else{
            head = Evenhead; // if no odd values in the odd head node we set head will to evenhead
            lastEven->nextN = nullptr; // the node in the evenhead list will point to null so it doesnt point to previous value of list
        }

        printlist(head); // print the list

    }

    void printlist(node* head) {
        while (head != NULL) // while the current value is not NULL, print value inside node
        {
            cout << "[" << head->data << "]" << "->";
            head = head->nextN; // change & advance the value of current to the next node
        }
        cout << endl;
    }


};

int main() {
    linked_list my_list;
    srand(time(nullptr));
    
    node* head = nullptr;
    node* last = nullptr;

    int value;
    for(int i = 0; i < 10; i++) {
        value = rand() % 20 + 1;
        my_list.insert(head,last,value);
    }

    cout<<"Before sort odd and even link list: "<<endl;
    my_list.printlist(head);
    cout<<"After sorting and putting odd nodes in the front and even in the back: "<<endl;
    my_list.OddEvenList(head);

}