#include <iostream>
#include <string>

using namespace std;

class Numbers
{
private:
    int number;   // Value to translate

    // Word lookups
    static string less20[20];
    static string tens[10];
    static string hund;
    static string thou;

public:
    // Stores the number
    Numbers(int num)
    {
        number = num;
    }

    // Prints the English description
    void print()
    {
        int num = number;

        if (num == 0)
        {
            cout << less20[0];
            return;
        }

        // Thousands place
        if (num >= 1000)
        {
            cout << less20[num / 1000] << " " << thou << " ";
            num %= 1000;
        }

        // Hundreds place
        if (num >= 100)
        {
            cout << less20[num / 100] << " " << hund << " ";
            num %= 100;
        }

        // Tens place
        if (num >= 20)
        {
            cout << tens[num / 10] << " ";
            num %= 10;
        }

        // Ones (or teens)
        if (num > 0)
        {
            cout << less20[num];
        }
    }
};

// Static member definitions
string Numbers::less20[20] =
{
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[10] =
{
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

string Numbers::hund = "hundred";
string Numbers::thou = "thousand";

int main()
{
    int num;

    cout << "Enter a number (0 - 9999): ";
    cin >> num;

    if (num < 0 || num > 9999)
        return 0;

    Numbers n(num);
    n.print();

    cout << endl;
    return 0;
}
