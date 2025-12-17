#include <iostream>
#include <string>

using namespace std;

class NumDays
{
private:
    double hours;

public:
    NumDays(double hrs = 0)
    {
        hours = hrs;
    }

    void setHrs(double hrs)
    {
        hours = hrs;
    }

    double getHrs()
    {
        return hours;
    }

    double getDays()
    {
        return hours / 8.0;
    }
};

class TimeOff
{
private:
    string name;
    int id;

    NumDays maxSick;
    NumDays sickTak;

    NumDays maxVac;
    NumDays vacTak;

    NumDays maxUnp;
    NumDays unpTak;

public:
    // Stores basic info and starts all hours at 0
    TimeOff(string nm, int num) : maxSick(0), sickTak(0), maxVac(0), vacTak(0), maxUnp(0), unpTak(0)
    {
        name = nm;
        id = num;
    }

    void setName(string nm)
    {
        name = nm;
    }

    void setId(int num)
    {
        id = num;
    }

    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    // Set max hours (vac max is capped at 240)
    void setMaxS(double hrs)
    {
        maxSick.setHrs(hrs);
    }

    void setSickT(double hrs)
    {
        sickTak.setHrs(hrs);
    }

    void setMaxV(double hrs)
    {
        if (hrs > 240)
            hrs = 240;
        if (hrs < 0)
            hrs = 0;

        maxVac.setHrs(hrs);
    }

    void setVacT(double hrs)
    {
        vacTak.setHrs(hrs);
    }

    void setMaxU(double hrs)
    {
        maxUnp.setHrs(hrs);
    }

    void setUnpT(double hrs)
    {
        unpTak.setHrs(hrs);
    }

    // Get hours
    double getMaxS()
    {
        return maxSick.getHrs();
    }

    double getSickT()
    {
        return sickTak.getHrs();
    }

    double getMaxV()
    {
        return maxVac.getHrs();
    }

    double getVacT()
    {
        return vacTak.getHrs();
    }

    double getMaxU()
    {
        return maxUnp.getHrs();
    }

    double getUnpT()
    {
        return unpTak.getHrs();
    }

    // Get days (optional helper getters)
    double getMaxSd()
    {
        return maxSick.getDays();
    }

    double getSickTd()
    {
        return sickTak.getDays();
    }

    double getMaxVd()
    {
        return maxVac.getDays();
    }

    double getVacTd()
    {
        return vacTak.getDays();
    }

    double getMaxUd()
    {
        return maxUnp.getDays();
    }

    double getUnpTd()
    {
        return unpTak.getDays();
    }
};

int main()
{
    TimeOff emp("Tylee", 1001);

    emp.setMaxS(80);     // 10 days
    emp.setSickT(16);    // 2 days taken

    emp.setMaxV(300);    // capped to 240 hours
    emp.setVacT(40);     // 5 days taken

    emp.setMaxU(32);     // 4 days
    emp.setUnpT(8);      // 1 day taken

    cout << emp.getName() << endl;
    cout << emp.getId() << endl << endl;

    cout << emp.getMaxS() << " " << emp.getMaxSd() << endl;
    cout << emp.getSickT() << " " << emp.getSickTd() << endl << endl;

    cout << emp.getMaxV() << " " << emp.getMaxVd() << endl;
    cout << emp.getVacT() << " " << emp.getVacTd() << endl << endl;

    cout << emp.getMaxU() << " " << emp.getMaxUd() << endl;
    cout << emp.getUnpT() << " " << emp.getUnpTd() << endl;

    return 0;
}
