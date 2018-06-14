#include <iostream>
#include "simpio.h"
#include "vector.h"
using namespace std;

// Single unit of a linked list
struct Cell {
    Cell* next;
    int value;
};

/* Usage: Cell* cell = convert_to_list(vector)
 * Effect: Convert the first item in a vector<int> to a Cell*. Then removes the item from the vector.
 * */
Cell* convert_to_list(Vector<int> &vector)
{
    // Initialize new cell on heap
    Cell* newCell = new Cell;
    // Get value (int) of first item in vector
    int value = vector[0];
    // Set value of Cell and set next pointer to NULL
    newCell->value = value;
    newCell->next = NULL;

    // Remove first entry from vector now that we've converted it
    vector.remove(0);

    return newCell;
}

/* Usage: Cell* cell = create_linked_list(vector)
 * Effect: Given a vector<int>, creates a linked list of Cell*'s
 * */
Cell* create_linked_list(Vector<int> &vector)
{
    // Get size of vector
    int length = vector.size();

    // Create first Cell* (head of linked list)
    Cell* listHead = convert_to_list(vector);
    // Permanant pointer pointing to head of list
    Cell* head = listHead;
    // Traversal pointer for moving along list
    Cell* ptr = listHead;

    // Build the list. This adds each new Cell to the END of the linked list
    for (int i = 1; i < length; i++)
    {
        // Create new cell
        Cell* newCell = convert_to_list(vector);
        // Set the next* to the next Cell in the linked list
        ptr->next = newCell;
        // Update the traversal ptr
        ptr = newCell;
    }

    return listHead;
}

/* Usage: int sum = sum_list(list)
 * Effect: Sums the values of all the Cell* in a linked list
 * */
int sum_list(Cell *list)
{
    // Counter
    int sum = 0;
    // Traversal pointer
    Cell* ptr = list;

    // Sums all values except the very last in the linked list
    while (ptr->next)
    {
        sum += ptr->value;
        ptr = ptr->next;
    }

    // Catches the final value in the list
    sum += ptr->value;

    return sum;
}

/* Usage: print_linked_list(list)
 * Effect: Prints to stdout all the values (integers) of all the Cell* in a linked list
 * */
void print_linked_list(Cell* list)
{
    // Traversal pointer
    Cell* ptr;
    // Prints all but the last value in the linked list
    for (ptr = list; ptr->next != NULL; ptr = ptr->next)
    {
        cout << ptr->value << endl;
    }
    // Prints the final value in the linked list
    cout << ptr->value << endl;
}

/* Usage: append_list(list1, list2)
 * Effect: Appends the values of list2 onto list1. Modifies list1 destructively, doesn't change list2.
 * */
void append_list(Cell* &list1, Cell* &list2)
{
    // Permanant pointer pointing at head of list1
    Cell* head1 = list1;
    // Traversal pointer for moving along list
    Cell* ptr;

    for (ptr = list1; ptr->next != NULL; ptr = ptr->next)
    {
        // Move thru list without changing anything...
    }

    // Attach the last Cell in list1 to the first Cell in list2
    ptr->next = list2;
}

// Main function
int main() {

    // Create 2 vectors to test out our functions
    Vector<int> vec;
    Vector<int> vec2;

    // Populate the vectors
    vec.add(1); vec.add(3); vec.add(5); vec.add(7);
    vec2.add(2); vec2.add(4);

    // Turn the vectors into linked lists
    Cell* linkedList1 = create_linked_list(vec);
    Cell* linkedList2 = create_linked_list(vec2);

    // Sum the values contained in list1
    cout << "Sum of list1: " << sum_list(linkedList1) << endl;

    // Append list2 to list1
    append_list(linkedList1, linkedList2);

    // Print the new combined list
    print_linked_list(linkedList1);

    return 0;
}

