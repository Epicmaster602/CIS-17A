#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    string num;
    string hdate;

public:
    Employee() {
        name = "";
        num = "";
        hdate = "";
    }

    Employee(string n, string id, string hd) {
        name = n;
        num = id;
        hdate = hd;
    }

    void setName(string n) { name = n; }
    void setNum(string id) { num = id; }
    void setHdate(string hd) { hdate = hd; }

    string getName() { return name; }
    string getNum() { return num; }
    string getHdate() { return hdate; }
};

class ProdWkr : public Employee {
private:
    int shft;     // 1 or 2
    double pay;   // hourly

public:
    ProdWkr() : Employee() {
        shft = 0;
        pay = 0.0;
    }

    ProdWkr(string n, string id, string hd, int s, double p)
        : Employee(n, id, hd) {
        shft = s;
        pay = p;
    }

    void setShft(int s) { shft = s; }
    void setPay(double p) { pay = p; }

    int getShft() { return shft; }
    double getPay() { return pay; }
};

int main() {
    ProdWkr w("Big Yoshi", "A123", "01/05/24", 1, 22.5);

    cout << "Name: " << w.getName() << endl;
    cout << "ID: " << w.getNum() << endl;
    cout << "Hire: " << w.getHdate() << endl;
    cout << "Shift: " << w.getShft() << endl;
    cout << "Pay: $" << w.getPay() << endl;

    return 0;
}
