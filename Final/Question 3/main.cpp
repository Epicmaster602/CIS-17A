#include <iostream>
#include "Prob3Table.h"

using namespace std;

int main()
{
    cout << "Entering problem number 3" << endl;

    int rows = 5;
    int cols = 6;

    Prob3TableInherited<int> tab("Problem3.txt", rows, cols);

    const int *naugT = tab.getTable();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    const int *augT = tab.getAugTable();
    for(int i = 0; i <= rows; i++)
    {
        for(int j = 0; j <= cols; j++)
        {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }

  //Extra Credit #3
    cout << endl<<"[EXTRA CREDIT #3] Overloaded + used to add two tables" << endl;

    // Add the table to itself (easy proof, no second file needed)
    int *sum = tab + tab;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << sum[i * cols + j] << " ";
        }
        cout << endl;
    }

    delete [] sum;

    return 0;
}