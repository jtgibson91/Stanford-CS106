#include <iostream>
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include "linkedlist.h"
using namespace std;

template <typename Type>
class myStack {
    public:
        myStack();
        ~myStack();

        void push(Type elem);
        Type pop();

        bool isEmpty();
    private:
        Vector<Type> elems;
};

/* 1)
 *   a) The underlying representation is a vector. It is just the way that we use it will be restricted to the
 * operations of a stack. So to reverse this as an implementor, We would assign vector[-1] = vector[0] and go
 * down the entirety of the vector until the entire thing is flipped. We could use a Swap(a, b) function.
 *
 *   b) As a client, we would be restricted to the functions available to us. I would create 2 stacks, and
 * empty all the items from stack 1 onto stack 2, and then back onto stack 1. That way all the items would be
 * reversed.
 * */

/* 2) A mob is a modified queue that, when dequeue'd, returns a random element (as opposed to a normal queue,
which returns the element which has been in there the longest) */
template <typename Type>
class Mob {
    public:
        Mob();

        void enqueue(Type newElem);
        Type dequeue();
        Type size();

    private:
        Vector<Type> elems;
};

// Below would be in the .cpp fle, while above is in the .h
template <typename Type>
void Mob<Type>::enqueue(Type newElem)
{
    elems.add(newElem);
}

template <typename Type>
Type Mob<Type>::dequeue()
{
    Type elemNum = RandomInteger(0, elems.size()-1);
    Type value = elems[elemNum];
    elems.removeAt(elemNum);
    return value;
}

/* In addition to the above changes, both the interface (header/ .h file) and the implementation (.cpp file)
have to be included in the .h file. This is a quirk of how the C++ language/ compilers handle templatized
classes.
*/

// Single node of a linked list
struct Node {
    int value;
    Node* next;
};

/* Problem #5. This function takes a linked list of Node*'s and creates a duplicate for each node. So a list
 * of 1, 2, 3 becomes 1, 1, 2, 2, 3, 3.
*/
void Stutter(Node* &listHead)
{
    Node* ptr = NULL;

    // Since we are inserting a duplicate node, instead of the normal increment instruction of ptr = ptr->next
    // , there is one duplicate node to skip over and so it is ptr = ptr->next->next
    for (ptr = listHead; ptr != NULL; ptr = ptr->next->next)
    {
        // Create new Node on the heap and get a pointer to it
        Node* newNode = new Node;
        // Copy the value over from ptr->value
        newNode->value = ptr->value;
        // Set the new node's next to ptr->next
        newNode->next = ptr->next;
        // Attach the original node's next pointer to its duplicate
        ptr->next = newNode;
    }
}

// Problem # 6 - Remove adjacent duplicates in a linked list
void RemoveDuplicates(Node* &listHead)
{
    Node* ptr = listHead;
    Node* ahead = ptr->next;

    while (ahead != NULL)
    {
        if (ptr->value == ahead->value)
        {
            Node* nodeToDel = ahead;
            ahead = ahead->next;
            ptr->next = ahead;
            delete nodeToDel;
        }
        else
        {
            ptr = ptr->next;
            ahead = ahead->next;
        }
    }
}

// Main function
int main() {

    Node* node1 = new Node; node1->value = 1;
    Node* node2 = new Node; node2->value = 2;
    Node* node3 = new Node; node3->value = 3;
    Node* node4 = new Node; node4->value = 4;


    Node* ptr = NULL;

    node1->next = node2; node2->next = node3; node3->next = node4; node4->next = NULL;

    /*
    cout << "Before: " << endl;
    for (ptr = node1; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->value << endl;
    }
    */

    Stutter(node1);

    /*
    cout << "After: " << endl;
    for (ptr = node1; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->value << endl;
    }
    */

    RemoveDuplicates(node1);

    for (ptr = node1; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->value << endl;
    }

    return 0;
}

