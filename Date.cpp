#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    void setday(int d)
    {
        day = d;
    }
    void setmonth(int m)
    {
        month = m;
    }
    void setyear(int y)
    {
        year = y;
    }
     
    int getday()
    {
        return day;
    }
    int getmonth()
    {
        return month;
    }
    int getyear()
    {
        return year;
    }
    Date();
    void display();
    ~Date();
};

void Date::display()
{
    cout << day << "/" << month << "/" << year << endl;
}

Date::Date()
{
    cout << "constructor invoke here" << endl;
}
Date::~Date(){
    cout << "Destructor invoke here" << endl;
}
int main()
{
    Date date1, date2;
    date1.setday(27);
    date1.setmonth(1);
    date1.setyear(2004);
    date1.display();
    int d, m, y;
    cout << "enter month";
    cin >> m;

    while (m > 12 || m < 1)
    {

        m = 1;
        date2.setmonth(m);
    }

    cout << "enter day:";
    cin >> d;

    switch (m)
    {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
      {
        if (d > 31)
        {
            d = 31;
            date2.setday(d);
        }
        break;
      }
      case 2:
      {
        if (d > 28)
        {
            d = 28;
            date2.setday(d);
        }
        break;
      }
      case 4:
      case 6:
      case 9:
      case 11:
      {
        if (d > 30)
        {
            d = 30;
            date2.setday(d);
        }
        break;
      }
    }

    cout << "enter year:";
    cin >> y;
    date2.setyear(y);
    cout << "--------------------------" << endl;
    
    cout<<"Your dates are : "<<endl;
    date1.display();
    date2.display();
    cout << "--------------------------" << endl;

    return 0;
}