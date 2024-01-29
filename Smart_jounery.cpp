#include <iostream>
using namespace std;
class Driving_license
{
private:
    int license_id;
    int issue_year;
 
public:
    Driving_license()
    { 
        license_id = 0;
        issue_year = 0;
    }
    Driving_license(int license, int exp)
    {
        license_id = license;
        issue_year = exp;
    } 

    void set_license(int id, int year)
    {
        license_id = id;
        issue_year = year;
    }
    int get_license()
    {
        return license_id;
    }
    int get_issueyear()
    {
        return issue_year;
    }
};

class CNIC
{
private:
    int cnic_id;
    int expiry_cnic;

public:
    CNIC()
    {
        cnic_id = 0;
        expiry_cnic = 0;
    }
    CNIC(int cnic_no, int expiry)
    {
        cnic_id = cnic_no;
        expiry_cnic = expiry;
    }
    void set_cnic(int id)
    {
        cnic_id = id;
    }
    void set_expiry_cnic(int expiry)
    {
        expiry_cnic = expiry;
    }
    int get_cnic()
    {
        return cnic_id;
    }
    int getexpiry_cnic()
    {
        return expiry_cnic;
    }
};

class Document
{
private:
    Driving_license obj_license;
    CNIC cnic;
    int doc_id;

public:
    Document(int doc, int license, int expyear, int cnic_no, int expiry_cnic) : doc_id(doc), obj_license(license, expyear), cnic(cnic_no, expiry_cnic)
    {
        cnic.set_cnic(cnic_no);
        cnic.set_expiry_cnic(expiry_cnic);
    }
    int getdoc_ic()
    {
        return doc_id;
    }
    void Show()
    {
        cout << "\nDoc Id is : " << doc_id << endl;
        cout << "CNIC of person is : " << cnic.get_cnic() << endl;
        cout << "License ID is : " << obj_license.get_license() << endl;

        if (obj_license.get_issueyear() < 1900 && obj_license.get_issueyear() > 2200)
        {
            cout << "License year has been expried with year " << obj_license.get_issueyear() << endl;
        }
        else
        {
            cout << "License year is :  " << obj_license.get_issueyear() << endl;
        }
        if (cnic.getexpiry_cnic() < 1900 && cnic.getexpiry_cnic() > 2200)
        {
            cout << "CNIC year has been expried with year " << cnic.getexpiry_cnic() << endl;
        }
        else
        {
            cout << "CNIC year is :  " << cnic.getexpiry_cnic() << endl;
        }
    }
};
class Stop
{
private:
    string stopName;

public:
    void setstops(string name)
    {
        stopName = name;
    }

    string getStopName()
    {
        return stopName;
    }
};
class Route
{
private:
    int route_id;
    Stop *stops;

public:
    Route()
    {

        stops = new Stop[4];
    }
    void setroute(int id)
    {
        route_id = id;
    }
    int getroute()
    {
        return route_id;
    }

    void addStop(string sptr[], int maxStops)
    {

        for (int i = 0; i < maxStops; i++)
        {

            stops[i].setstops(sptr[i]);
        }
    }
    void print(int maxStops)
    {
        for (int i = 0; i < maxStops; i++)
        {
            cout << "Stops " << i + 1 << " is : \t" << stops[i].getStopName() << endl;
        }
    }
    ~Route()
    {
        delete[] stops;
    }
};
class Transport_Network
{
private:
    Route *route;
    string title;

public:
    Transport_Network(int ptr[], int size)
    {

        route = new Route[size];
        title = "";
        for (int i = 0; i < size; i++)
        {
            route[i].setroute(ptr[i]);
        }
    }
    void settitle(string t)
    {

        title = t;
    }
    void show(int size)
    {
        cout << "Your Network name is : \t";
        cout << title << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "ID of Routes " << i + 1 << " is : ";
            cout << route[i].getroute() << endl;
        }
    }
    ~Transport_Network()
    {
        delete[] route;
    }
};
class Person
{
private:
    string Name;

    Document Doc;

public:
    Person(int doc, int license, int expyear, int cnic_no, int expiry_cnic) : Doc(doc, license, expyear, cnic_no, expiry_cnic) {}
    string setname(string n)
    {
        Name = n;
    }
    string getname()
    {
        return Name;
    }
    void Display()
    {
        cout << "Name is " << Name;
        Doc.Show();
    }
};
class Driver : public Person
{
private:
public:
    Driver(int doc, int license, int expyear, int cnic_no, int expiry_cnic, string n) : Person(doc, license, expyear, cnic_no, expiry_cnic)
    {
        setname(n);
    }
};
int main()
{
    cout << "Enter Name of a person :   ";
    string n;
    cin >> n;
    cout << endl;
    cout << "Enter Documnent ID :   ";
    int id;
    cin >> id;
    cout << endl;
    cout << "Enter License ID :   ";
    int license;
    cin >> license;
    cout << endl;
    cout << "Enter issue year of License :   ";
    int exp;
    cin >> exp;
    cout << endl;
    cout << "Enter CNIC number  :   ";
    int cnic_no;
    cin >> cnic_no;
    cout << endl;
    cout << "Enter CNIC expiry Date  :   ";
    int expiry_cnic;
    cin >> expiry_cnic;
    cout << endl;
    Driver d(id, license, exp, cnic_no, expiry_cnic, n);
    int size;
    cout << "Enter number of routes :   ";
    cin >> size;
    cout << endl;
    int *ptr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter ID of route " << i + 1 << "\t";
        cin >> ptr[i];
        cout << endl;
    }
    Transport_Network obj_network(ptr, size);
    cout << "Enter name of Network :   ";
    string t;
    cin >> t;
    cout << endl;
    obj_network.settitle(t);

    Route route;

    int s;
    int maxStops = 4;
    cout << "Enter number of stops :   ";
    cin >> s;
    while (s > maxStops)
    {
        cout << "Not more than 3 stops" << endl;
        cin >> s;
    }

    cout << endl;
    string *sptr = new string[s];
    for (int i = 0; i < s; i++)
    {
        cout << "Enter Name of Stops " << i + 1 << "\t";
        cin >> sptr[i];
        cout << endl;
    }
    route.addStop(sptr, s);
    cout << "-----About Driver-----" << endl;
    d.Display();
    cout << "\n-----About Routes and Stops-----" << endl;
    obj_network.show(size);
    cout << endl;
    route.print(s);
    cout << endl;
    cout << "----Program End..----" << endl;
    delete[] ptr;
    delete[] sptr;
}