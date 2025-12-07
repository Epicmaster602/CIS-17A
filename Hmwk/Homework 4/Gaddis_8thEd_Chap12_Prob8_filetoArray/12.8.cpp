#include <iostream>
#include <fstream>
using namespace std;

void arrayToFile(const char* fileName, int* arr, int size) {
    ofstream fout(fileName, ios::out | ios::binary);
    if(!fout){
        cout << "File open error"<<endl;
        return;
    }
    fout.write(reinterpret_cast<char*>(arr), sizeof(int)*size);
    fout.close();
}

void fileToArray(const char* fileName, int* arr, int size) {
    ifstream fin(fileName, ios::in | ios::binary);
    if(!fin){
        cout << "File open error"<<endl;
        return;
    }
    fin.read(reinterpret_cast<char*>(arr), sizeof(int)*size);
    fin.close();
}

int main() {
    const int SIZE = 5;
    int nums[SIZE] = {10, 20, 30, 40, 50};
    int copy[SIZE] = {0}; // empty array for reading back

    const char* fileName = "numbers.dat";

    // Write array to file
    arrayToFile(fileName, nums, SIZE);

    // Clear the original array to test read-back
    for(int i=0;i<SIZE;i++)
        nums[i] = 0;

    // Read from file back into array
    fileToArray(fileName, nums, SIZE);

    // Display to confirm
    cout << "Array read from file:"<<endl;
    for(int i=0;i<SIZE;i++)
        cout << nums[i] << " ";
    cout << endl;

    return 0;
}
