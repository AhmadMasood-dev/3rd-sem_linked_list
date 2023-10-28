#include <iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date()
	{
		cout << " constructor invoke " << endl;
		day = 0;
		month = 0;
		year = 0;
	}

	Date(int dd, int mm, int yy)
	{
		day = dd;
		month = mm;
		year = yy;
		
	}
	void display() {
		cout << "your current date is " << day << ":" << month << ":" << year << endl;
	}
	int compare(Date D) 
	{		
			int difference;
			difference = year - D.year;
			if (difference<=0)
			{
			difference = difference * (-1);
			}
			difference = difference * 360;
			int FinalY = difference;
			difference = month - D.month;
			if (difference <= 0)
			{
				difference = difference * (-1);
			}
			
			difference = difference * 30+ difference/2;
			

			int FinalM = difference;
			
			
				difference = day - D.day;
				
				if (difference <= 0)
				{
					difference=difference*(-1);
					

				}
			
			
			int FINDALDATE = difference + FinalM + FinalY;
			
			return FINDALDATE;
		
	}
};


int main()
{
	Date date1(27, 2, 2004), date2(27, 1, 2004);

	date1.display();
	date2.display();
	cout << "\n";
	cout<<date1.compare(date2)<<" days difference";
	
	return 0;
}