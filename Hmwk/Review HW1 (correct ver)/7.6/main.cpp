#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int MONS = 3;
    const int DAYS = 30;

    char weath[MONS][DAYS];
    int cntR[MONS] = {0, 0, 0};
    int cntC[MONS] = {0, 0, 0};
    int cntS[MONS] = {0, 0, 0};

    string mNam[MONS] = {"June", "July", "August"};

    ifstream fin("RainOrShine.txt");
    if (!fin)
        return 0;

    // Read file into array (3 months x 30 days)
    for (int m = 0; m < MONS; m++)
    {
        for (int d = 0; d < DAYS; d++)
        {
            char ch;
            fin >> ch;
            weath[m][d] = ch;

            if (ch == 'R') cntR[m]++;
            else if (ch == 'C') cntC[m]++;
            else if (ch == 'S') cntS[m]++;
        }
    }

    int totR = 0, totC = 0, totS = 0;
    for (int m = 0; m < MONS; m++)
    {
        totR += cntR[m];
        totC += cntC[m];
        totS += cntS[m];
    }

    int maxR = cntR[0];
    int maxM = 0;
    for (int m = 1; m < MONS; m++)
    {
        if (cntR[m] > maxR)
        {
            maxR = cntR[m];
            maxM = m;
        }
    }

    // Report
    for (int m = 0; m < MONS; m++)
    {
        cout << mNam[m] << endl;
        cout << "Rainy: " << cntR[m] << endl;
        cout << "Cloudy: " << cntC[m] << endl;
        cout << "Sunny: " << cntS[m] << endl << endl;
    }

    cout << "Total" << endl;
    cout << "Rainy: " << totR << endl;
    cout << "Cloudy: " << totC << endl;
    cout << "Sunny: " << totS << endl << endl;

    cout << "Most rainy: " << mNam[maxM] << endl;

    return 0;
}
