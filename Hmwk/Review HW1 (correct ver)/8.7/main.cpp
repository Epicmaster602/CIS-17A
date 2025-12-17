#include <iostream>
#include <string>

using namespace std;

// Binary search for strings
int binSrch(string arr[], int size, string val)
{
    int first = 0;
    int last = size - 1;
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (arr[mid] == val)
            return mid;
        else if (arr[mid] > val)
            last = mid - 1;
        else
            first = mid + 1;
    }

    return -1;
}

int main()
{
    const int SIZE = 10;

    // Sorted array of strings
    string list[SIZE] =
    {
        "apple", "banana", "cherry", "grape", "kiwi",
        "lemon", "mango", "orange", "peach", "pear"
    };

    string find;
    int pos;

    cout << "Enter word to search: ";
    cin >> find;

    pos = binSrch(list, SIZE, find);

    if (pos == -1)
        cout << "Not found" << endl;
    else
        cout << "Found at index " << pos << endl;

    return 0;
}
