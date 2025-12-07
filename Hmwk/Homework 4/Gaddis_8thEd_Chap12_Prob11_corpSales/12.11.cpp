#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Division {
    string name;
    int quarter;
    double sales;
};

int main() {
    ofstream fout("corp_sales.txt");
    if(!fout){
        cout << "File open error"<<endl;
        return 1;
    }

    string names[4] = {"East","West","North","South"};
    Division rec;

    cout << fixed << setprecision(2);
    fout << fixed << setprecision(2);

    for(int i=0;i<4;i++){
        for(int q=1;q<=4;q++){
            cout << names[i] << " Q" << q << " sales: ";
            cin >> rec.sales;

            rec.name = names[i];
            rec.quarter = q;

            // write one record per line: <Name> <Quarter> <Sales>
            fout << rec.name << " " << rec.quarter << " " << rec.sales <<endl;
        }
    }

    fout.close();
    cout << "Wrote data to corp_sales.txt"<<endl;
    return 0;
}
