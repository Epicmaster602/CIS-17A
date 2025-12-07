#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file."<<endl;
        return 1;
    }

    string line;
    int count = 0;

    while (getline(inFile, line)) {
        cout << line << endl;
        count++;
        if (count == 10)
            break;
    }

    // check if fewer than 10 lines
    if (count < 10) {
        string temp;
        if (getline(inFile, temp)) {
            // do nothing, already displayed 10 lines
        } else {
            cout <<endl<< "The entire file has been displayed (" << count << " lines total)." << endl;
        }
    }

    inFile.close();
    return 0;
}
