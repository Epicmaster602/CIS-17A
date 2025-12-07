#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fname;
    cout << "Enter file name: ";
    getline(cin, fname); 

    ifstream in(fname.c_str());
    if (!in.is_open()) {
        cout << "Could not open file."<<endl;
        return 1;
    }

    string line;
    int lines = 0; // how many lines we've printed 
    int total = 0;

    while (getline(in, line)) {
        cout << line << endl;
        lines++;
        total++;

        if (lines == 24) {
            cout << "Press Enter to continue";
            cin.get();         // just wait for Enter (simplest)
            lines = 0;         // reset page counter
            cout << endl;      // add a tiny gap
        }
    }



    in.close();
    return 0;
}
