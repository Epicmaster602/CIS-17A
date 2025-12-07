#include <iostream>
using namespace std;

int main()
{
    char letter;

    // Ask the user to enter a character
    cout << "Enter a character: ";
    cin >> letter;

    // Display the ASCII code using a type cast
    cout << "The ASCII code for '" << letter << "' is "
         << static_cast<int>(letter) << endl;

    return 0;
}
