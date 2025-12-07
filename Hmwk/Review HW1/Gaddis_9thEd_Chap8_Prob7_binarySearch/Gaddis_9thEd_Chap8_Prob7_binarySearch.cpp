/* 
 * Author: Tyler Purba
 * Date: 2025-09-12
 * Purpose: Perform a binary search on an array of names
 */

#include <iostream>
#include <string>
using namespace std;
int binarySearch(const string array[], int numElems, string value);

int main() 
{
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {
    "Allen, Jim",
    "Allison, Jeff",
    "Collins, Bill",
    "Griffin, Jim",
    "Harrison, Rose",
    "Holland, Beth",
    "James, Jean",
    "Javens, Renee",
    "Johnson, Jill",
    "Looney, Joe",
    "Pike, Gordon",   // note the extra space after Pike
    "Pore, Bob",
    "Rose, Gerf",
    "Rutherford, Greg",
    "Setzer, Cathy",
    "Smith, Bart",
    "Stamey, Marty",
    "Taylor, Terri",
    "Weaver, Jim",
    "Wolfe, Bill"
};


    string searchName;
    cout << "Enter a name: ";
    getline(cin, searchName);

    int position = binarySearch(names, NUM_NAMES, searchName);

    if (position == -1)
        cout << searchName << " was not found.\n";
    else
        cout << searchName << " was found at position " << position << endl;

    return 0;
}


int binarySearch(const string array[], int numElems, string value)
{
    int first = 0,            // First array element
        last = numElems - 1,  // Last array element
        middle,               // Midpoint of search
        position = -1;        // Position of search value
    bool found = false;       // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint

        if (array[middle] == value)  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;         // If value is in upper half
    }

    return position;
}