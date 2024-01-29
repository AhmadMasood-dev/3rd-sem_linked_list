#include <iostream>
#include <list>
using namespace std;
void display(list<int> &li)
{
  list<int>::iterator iter;
  for (iter = li.begin(); iter != li.end(); iter++)
  {
    cout << *iter << "  ";
  }
  cout << endl;
}
int main()
{
  list<int> list1;
  list<int> list2(3);
  for (int i = 0; i < 5; i++) 
  {

    list1.push_back(i + 3);
  }
  display(list1);
  cout << "add 1 element at the end by doing pushback() :   ";
  list1.push_back(1);
  display(list1);
  cout << "delete last value by pop_back():   ";
  list1.pop_back(); // delete last value
  display(list1);
  cout << "delete first value by pop_front() :   ";
  list1.pop_front(); // delete first value
  display(list1);
  cout << "add 1 element at the end by doing pushback() :   ";
  list1.push_back(5);
  display(list1);
  list1.remove(3); // remove the given numver
  cout << "remove the enter word in parameters by list1.remove(word):   ";
  display(list1);
  list<int>::iterator iter;
  iter = list2.begin();
  *iter = 9;
  iter++;
  *iter = 8;
  iter++;
  *iter = 7;
  iter++;
  cout << endl;
  cout << "Second list :   ";
  display(list2);
  list1.merge(list2);
  cout << "list 1 merge with list 2 and data store in list 1 : ";
  display(list1);
  cout << "Reverse the list1 :   ";
  list1.reverse();
  display(list1);
  cout << "Sorting the list1 :   ";
  list1.sort();
  display(list1);
  cout << "remove dulication in the list :   ";
  list1.unique();
  display(list1);
  return 0;
}