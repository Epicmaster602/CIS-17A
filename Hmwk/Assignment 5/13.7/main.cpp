#include <iostream>

using namespace std;

class TestScores
{
private:
    double sc1;
    double sc2;
    double sc3;

public:
    // Constructor
    TestScores(double s1, double s2, double s3)
    {
        sc1 = s1;
        sc2 = s2;
        sc3 = s3;
    }

    // Mutators
    void setSc1(double s)
    {
        sc1 = s;
    }

    void setSc2(double s)
    {
        sc2 = s;
    }

    void setSc3(double s)
    {
        sc3 = s;
    }

    // Accessors
    double getSc1()
    {
        return sc1;
    }

    double getSc2()
    {
        return sc2;
    }

    double getSc3()
    {
        return sc3;
    }

    // Returns average score
    double getAvg()
    {
        return (sc1 + sc2 + sc3) / 3.0;
    }
};

int main()
{
    double a, b, c;

    cout << "Enter test score 1: ";
    cin >> a;

    cout << "Enter test score 2: ";
    cin >> b;

    cout << "Enter test score 3: ";
    cin >> c;

    TestScores scores(a, b, c);

    cout << "Average score: " << scores.getAvg() << endl;

    return 0;
}
