#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    string inFile, outFile;
    cout << "Enter input file name: ";
    cin >> inFile;
    cout << "Enter output file name: ";
    cin >> outFile;

    ifstream fin(inFile);
    ofstream fout(outFile);
    if(!fin || !fout){
        cout << "File error"<<endl;
        return 1;
    }

    char ch;
    bool newSent = true;

    while(fin.get(ch)){
        if(isalpha(ch)){
            if(newSent){
                fout << (char)toupper(ch);
                newSent = false;
            } else {
                fout << (char)tolower(ch);
            }
        } else {
            fout << ch;
            if(ch == '.')
                newSent = true;
        }
    }

    fin.close();
    fout.close();
    cout << "Done."<<endl;
    return 0;
}

