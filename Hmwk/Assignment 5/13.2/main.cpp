#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    string addr;
    int age;
    string phone;

public:
    // Mutators
    void setName(string nm)
    {
        name = nm;
    }

    void setAddr(string ad)
    {
        addr = ad;
    }

    void setAge(int ag)
    {
        age = ag;
    }

    void setPhon(string ph)
    {
        phone = ph;
    }

    // Accessors
    string getName()
    {
        return name;
    }

    string getAddr()
    {
        return addr;
    }

    int getAge()
    {
        return age;
    }

    string getPhon()
    {
        return phone;
    }
};

int main()
{
    Person p1;
    Person p2;
    Person p3;

    // Your info
    p1.setName("Tylee (me!)");
    p1.setAddr("123 Verd St");
    p1.setAge(18);
    p1.setPhon("688-7215");

    // Friend or family
    p2.setName("Chris");
    p2.setAddr("456 Oak Rd");
    p2.setAge(21);
    p2.setPhon("555-5678");

    // Friend or family
    p3.setName("Jordan");
    p3.setAddr("789 Pine Ave");
    p3.setAge(45);
    p3.setPhon("555-9012");

    cout << p1.getName() << endl;
    cout << p1.getAddr() << endl;
    cout << p1.getAge() << endl;
    cout << p1.getPhon() << endl << endl;

    cout << p2.getName() << endl;
    cout << p2.getAddr() << endl;
    cout << p2.getAge() << endl;
    cout << p2.getPhon() << endl << endl;

    cout << p3.getName() << endl;
    cout << p3.getAddr() << endl;
    cout << p3.getAge() << endl;
    cout << p3.getPhon() << endl;

    return 0;
}
