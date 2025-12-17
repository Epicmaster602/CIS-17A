#include <iostream>
#include <string>

using namespace std;

class RetailItem
{
private:
    string desc;   // Item description
    int units;     // Units in stock
    double price;  // Retail price

public:
    // Constructor sets all values
    RetailItem(string ds, int un, double pr)
    {
        desc = ds;
        units = un;
        price = pr;
    }

    // Mutators
    void setDesc(string ds)
    {
        desc = ds;
    }

    void setUnits(int un)
    {
        units = un;
    }

    void setPrice(double pr)
    {
        price = pr;
    }

    // Accessors
    string getDesc()
    {
        return desc;
    }

    int getUnits()
    {
        return units;
    }

    double getPrice()
    {
        return price;
    }
};

int main()
{
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    cout << item1.getDesc() << endl;
    cout << item1.getUnits() << endl;
    cout << item1.getPrice() << endl << endl;

    cout << item2.getDesc() << endl;
    cout << item2.getUnits() << endl;
    cout << item2.getPrice() << endl << endl;

    cout << item3.getDesc() << endl;
    cout << item3.getUnits() << endl;
    cout << item3.getPrice() << endl;

    return 0;
}
