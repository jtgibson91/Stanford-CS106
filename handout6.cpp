#include <iostream>
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include <cmath>
using namespace std;

// Swaps two elements
template <typename Type>
void Swap(Type &a, Type &b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

/* Default compare function to use with FindMax(). Uses the default binary compare operators, which will work
on built-in types */
template <typename Type>
int default_cmp(Type one, Type two)
{
    if (one == two) {return 0;}
    else
    {
        return (one < two ? -1 : 1);
    }
}

// Finds the largest element in a vector
template <typename Type>
Type FindMax(Vector<Type> vec, int (cmp) (Type one, Type two)=default_cmp)
{
    // Index of the current highest element in the vector
    int max = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        // If the element being examined is greater than the previous largest element, set max to i
        if (cmp(vec[i], vec[max]) == 1)
        {
            max = i;
        }
    }
    // Return the greatest element
    return vec[max];

}

// The Car struct and the following functions related to this struct are for solving problem #3
struct Car {
    string name;
    int weight;
    int numAirbags;
};

void print_car(Car car)
{
    cout << car.name << endl;
    cout << car.numAirbags << endl;
    cout << car.weight << endl;
}

int safer_car(Car car1, Car car2)
{
    if (car1.numAirbags < car2.numAirbags || (car1.numAirbags == car2.numAirbags && car1.weight < car2.weight))
    {
        return -1;
    }

    else if (car1.numAirbags == car2.numAirbags && car1.weight == car2.weight)
    {
        return 0;
    }

    else {return 1;}

}

/* Filters items out of the queue which meet the criteria supplied by criteriaFn predicate function
 * Problem #4
 * */
template <typename Type>
void Filter(Queue<Type> & Q, bool (*criteriaFn)(Type item))
{
    // Temporary holder queue
    Queue<Type> newQ;

    // For each item in the queue
    while (!Q.isEmpty())
    {
        Type item = Q.dequeue();

        // If the item doesn't meet criteria of the Fn, enqueue it into our temporary holder queue
        if (!criteriaFn(item))
        {
            newQ.enqueue(item);
        }
    }

    // Put (non-filtered) items back in the original queue
    while (!newQ.isEmpty())
    {
        Q.enqueue(newQ.dequeue());
    }
}

// Struct for problem #4
struct recordingT {
    string title;
    string genre;
    int rating;
};

// Predicate function for problem #4
bool IsBadAnimation(recordingT show)
{
    return (show.genre == "animation" && show.rating < 8);
}

// Problem #5
template <typename Type>
void RemoveDuplicates(Vector<Type> & vec, int (cmp) (Type one, Type two)=default_cmp)
{
    Vector<Type> newVec;

    newVec.add(vec[0]);

    for (int i = 1; i < vec.size(); i++)
    {
        for (Type item : newVec)
        {
            // If the item in vec has already appeared in vec, delete it
            if (cmp(vec[i], item == 0)) { vec.remove(i); }
        }

    }
}
