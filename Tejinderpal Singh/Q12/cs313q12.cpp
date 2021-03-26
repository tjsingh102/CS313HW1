#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int number_of_days_used[5] = {0, 0, 0, 0, 0};       // declaring array that stores the day of the week if it has been used
struct node
{
    int day_of_apt;
    int length_of_apt;   // all of the parts of an appointment
    int time_of_apt;
    int am_pm;
    node *nextN;        //node pointer to next node 
    node *prevN;        // node pointer to previous node
};

class Doubly_Linked_List
{
private:
    node *head;     // node pointer for the head of the list

public:
    Doubly_Linked_List()
    {
        head = nullptr;
    }

    void addAtEnd(node *&head, int day, int length, int timeofday, int morning_or_night)
    {
        node *n = new node;     // create new node within the function to add at the end of the list if it is called on
        node *lastN = head;     // creating node pointer and settting it to head to run through the list and get to the end

        n->day_of_apt = day;
        n->length_of_apt = length;
        n->time_of_apt = timeofday;
        n->am_pm = morning_or_night;            // setting each part of the new node to the parameters we passed in 
        n->nextN = nullptr;

        if (head == nullptr)
        {
            n->prevN = nullptr;
            head = n;                       //if list is empty then make the node the head and exit the function
            return;
        }

        while (lastN->nextN != nullptr)
        {       
            lastN = lastN->nextN;                   //while loop to get to the end of the list
        }       

        lastN->nextN = n;       // add the node to end by making the next pointer of the last node set to the new node
        n->prevN = lastN;       // finish it by making the previous pointer of the new node set to the node before it which was initally the "last" node
    }

    void addBefore(node *&head, node *&next_node, int day, int length, int timeofday, int morning_or_night)
    {
        node *n = new node;
        n->day_of_apt = day;
        n->length_of_apt = length;                   // setting each part of the new node to the parameters we passed in 
        n->time_of_apt = timeofday;
        n->am_pm = morning_or_night;     
        n->prevN = next_node->prevN;                // setting the previous pointer of the new node to the previous pointer of the node ahead of it
        next_node->prevN = n;                   // setting the previous pointer of node that comes after the new node to new node
        n->nextN = next_node;                   // setting the next pointer for the new node to the next node that was passed through

        if (n->prevN != nullptr)
        {
            n->prevN->nextN = n;            // as long as there is a node before the new node, set the next pointer of the previous node to new node
        }
        else
        {
            head = n;           // otherwise make head point to the new node
        }
    }
    void addAfter(node *&previous_n, int day, int length, int timeofday, int morning_or_night)
    {
        node *n = new node;
        n->day_of_apt = day;
        n->length_of_apt = length;          // setting each part of the new node to the parameters we passed in 
        n->time_of_apt = timeofday;
        n->am_pm = morning_or_night;
        n->nextN = previous_n->nextN;       //setting the next pointer of the new node to the next pointer of the node behind it
        previous_n->nextN = n;              //setting the next pointer of the previous node to the new node
        n->prevN = previous_n;             // setting the previous pointer of the new node to the node behind it 

        if (n->nextN != nullptr)
        {
            n->nextN->prevN = n;        //as long as there is a node after the new node, set the previous pointer of the new ahead of it to the new node itself
        }
    }

    void createAppointment(node *&head, int day, int length, int timeofday, int morning_or_night)
    {
        if (number_of_days_used[day] != day)
        {
            addAtEnd(head, day, length, timeofday, morning_or_night);
            number_of_days_used[day] = day;                                 //if the day hasnt been used yet, then add it at the end of the list
            return;                                                          // store the day in the array that remembers which days have been used
        }

        node *curr = head;
        while (curr != nullptr)
        {
            if (curr->day_of_apt == day)    
            {
                break;                              //while loop that stops when the current node reaches the day that is being passed through
            }
            curr = curr->nextN; 
        }

        if ((curr->time_of_apt < timeofday) && (curr->am_pm < morning_or_night))
        {
            addAfter(curr, day, length, timeofday, morning_or_night);
        }
        if ((curr->time_of_apt < timeofday) && (curr->am_pm > morning_or_night))
        {
            addBefore(head, curr, day, length, timeofday, morning_or_night);
        }
        if ((curr->time_of_apt > timeofday) && (curr->am_pm > morning_or_night))        //all of these conditions are checking for placement of the node
        {
            addBefore(head, curr, day, length, timeofday, morning_or_night);
        }
        if ((curr->time_of_apt > timeofday) && (curr->am_pm < morning_or_night))
        {
            addAfter(curr, day, length, timeofday, morning_or_night);
        }
        if ((curr->time_of_apt > timeofday) && (curr->am_pm == morning_or_night))
        {
            addBefore(head, curr, day, length, timeofday, morning_or_night);
        }
        if ((curr->time_of_apt < timeofday) && (curr->am_pm == morning_or_night))
        {
            addAfter(curr, day, length, timeofday, morning_or_night);
        }
    }
};

void printLinkedList(node *current)
{
    while (current != nullptr)
    {
        string timezone;
        if (current->am_pm == 0)
        {
            timezone = "AM";            //converts am 
        }   
        else
        {
            timezone = "PM";            // converts pm
        }

        if (current->day_of_apt == 1)
            cout << "Monday: " << current->time_of_apt << timezone << " -> ";
        if (current->day_of_apt == 2)
            cout << "Tueday: " << current->time_of_apt << timezone << " -> ";
        if (current->day_of_apt == 3)
            cout << "Wednesday: " << current->time_of_apt << timezone << " -> ";            //print function that converts day to weekday
        if (current->day_of_apt == 4)
            cout << "Thursday: " << current->time_of_apt << timezone << " -> ";
        if (current->day_of_apt == 5)
            cout << "Friday: " << current->time_of_apt << timezone << " -> ";

        current = current->nextN;
    }
    cout << endl
         << endl;
}

int main()
{
    Doubly_Linked_List appointments;

    node *head = nullptr;

    appointments.createAppointment(head, 3, 45, 1000, 0);
    appointments.createAppointment(head, 1, 50, 500, 1);
    appointments.createAppointment(head, 1, 30, 1030, 0);
    appointments.createAppointment(head, 2, 35, 400, 1);
    appointments.createAppointment(head, 2, 40, 1030, 0);
    appointments.createAppointment(head, 3, 40, 900, 0);
    appointments.createAppointment(head, 5, 20, 900, 0); 
    appointments.createAppointment(head, 4, 30, 900, 0);        // creating appointments
    appointments.createAppointment(head, 5, 30, 800, 0);

    printLinkedList(head);
}