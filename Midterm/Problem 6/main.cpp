#include <iostream>
using namespace std;

void prnP6(){ // prints final results only
    cout << "Problem 6: NASA 4-byte float"<<endl;

    cout << "(a) Base conversions + float hex"<<endl;
    cout << "49.1875     -> bin 110001.0011,  oct 61.14, hex 0x31.3,  float 0x62600006"<<endl;
    cout << "3.07421875  -> bin 11.00010011,  oct 3.046, hex 0x3.13,  float 0x62600002"<<endl;
    cout << "0.2         -> bin 0.001100110011..., oct 0.1463..., hex 0x0.3333..., float 0x666666FE\n"<<endl;

    cout << "(b) Negatives (sign bit set)"<<endl;
    cout << "-49.1875    -> bin -110001.0011,  oct -61.14, hex -0x31.3,  float 0xE2600006"<<endl;
    cout << "-3.07421875 -> bin -11.00010011,  oct -3.046, hex -0x3.13,  float 0xE2600002"<<endl;
    cout << "-0.2        -> bin -0.001100110011..., oct -0.1463..., hex -0x0.3333..., float 0xE66666FE\n"<<endl;

    cout << "(c) Float hex -> decimal"<<endl;
    cout << "69999902 -> 3.3"<<endl;
    cout << "69999903 -> 6.6"<<endl;
    cout << "966667FF -> -.0875"<<endl;


}

int main(){
    prnP6();
    return 0;
}
