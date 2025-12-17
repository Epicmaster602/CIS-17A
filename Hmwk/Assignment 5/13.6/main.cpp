#include <iostream>

using namespace std;

class Inventory
{
private:
    int itemNo;
    int qty;
    double cost;
    double totCost;

    // Calculates total cost
    void setTotalCost()
    {
        totCost = qty * cost;
    }

public:
    // Default constructor
    Inventory()
    {
        itemNo = 0;
        qty = 0;
        cost = 0.0;
        totCost = 0.0;
    }

    // Constructor with arguments
    Inventory(int it, int qu, double co)
    {
        setItemNo(it);
        setQty(qu);
        setCost(co);
        setTotalCost();
    }

    void setItemNo(int it)
    {
        if (it >= 0)
            itemNo = it;
        else
            itemNo = 0;
    }

    void setQty(int qu)
    {
        if (qu >= 0)
            qty = qu;
        else
            qty = 0;

        setTotalCost();
    }

    void setCost(double co)
    {
        if (co >= 0)
            cost = co;
        else
            cost = 0.0;

        setTotalCost();
    }

    int getItemNo()
    {
        return itemNo;
    }

    int getQty()
    {
        return qty;
    }

    double getCost()
    {
        return cost;
    }

    double getTotCost()
    {
        return totCost;
    }
};

int main()
{
    Inventory item1(1001, 5, 12.50);
    Inventory item2;

    item2.setItemNo(2002);
    item2.setQty(10);
    item2.setCost(3.75);

    cout << item1.getItemNo() << endl;
    cout << item1.getQty() << endl;
    cout << item1.getCost() << endl;
    cout << item1.getTotCost() << endl << endl;

    cout << item2.getItemNo() << endl;
    cout << item2.getQty() << endl;
    cout << item2.getCost() << endl;
    cout << item2.getTotCost() << endl;

    return 0;
}
