#include<iostream>
using namespace std;

class Time 
{
	private:
		int hours;
		int minutes;
		int seconds;
		
	public:
		Time()
		{
		}
		
		Time(int h, int m, int s)
		{
			hours = h;
			minutes = m;
			seconds = s;
		}
		
		int getHrs()
		{
			return hours;
		}
		
		int getMins()
		{
			return minutes;
		}
		
		int getSecs()
		{
			return seconds;
		}
		
		//display time
		void display() 																	
		{																			
		cout << getHrs() << " : "<< getMins() << " : " << getSecs() << endl; 			
		}																				
																	
		
		
		
		// to match time recorded with occured time
		bool operator ==(Time &t)
    	{
     		if(hours == t.hours)
     		{
     			if(minutes == t.minutes)
     			{
     				if(seconds == t.seconds)
     				{
     					return true;
					 }
					 
					 else 
					 {
					 	return false;
					 }
				 }
				 
				 else
				{
					return false;
				}
			 }
			 
			 else
			 {
			 	return false;
			 }	
		}
		
		//to find time taken for the ride
		Time operator - (Time T)
		{
			Time temp;
			temp.hours = hours - T.hours;
			temp.minutes = minutes - T.minutes;
			temp.seconds = seconds - T.seconds;
			return temp;
		}
		
		float calculateTime()
		{
			float test;
			test = (getHrs() * 3600) + (getMins() * 60) + getSecs();
			return (test/3600);
		}
		
};

