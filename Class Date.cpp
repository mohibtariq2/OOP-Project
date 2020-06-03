#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>

using namespace std;

class Date
{
	private:
	int date;
    int month;
    int year;
    
    public:
     	void DisplayDate()
     	{
     		cout << date << "/" << month << "/" << year << endl;
		}
		
        Date operator - (Date d)
        {
        	Date temp;
			temp.date = date - d.date;
			temp.month = month - d.month;
			temp.year = year - d.year;
			return temp;
		}

	
};
