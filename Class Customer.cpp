#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>

using namespace std;

class Customer
{
	private:
		char name [50];
        long int  cnic;
  		long phone_num;
  		char address[100];
  		char gender;
  		int Customer_ID;
  		int Subscription_ID;
  		char email[100];
  		
  	public:
void InputData()
  		{
  			cout << "*** E N T E R   D E T A I L S ***" << endl;
  			cout << "Enter customer name: ";
  			cin.ignore();
  			cin.getline(name,49);
  			cout << endl;
  			cout << "Cnic Number: ";
  			cin >> cnic;
  			cout << endl;
  			cout << "Phone number: ";
  			cin >> phone_num;
  			cout << endl;
  			cout << "Address: ";
  			cin.ignore();
  			cin.getline(address,99);
  			cout << endl;
  			cout << "Enter gender M or F: ";
  			cin >> gender;
  			cout << endl;
  			cout << "Customer ID: ";
  			cin >> Customer_ID;
  			cout << endl;
  			cout << "Subscription ID: ";
  			cin >>  Subscription_ID;
  			cout << endl;
  			cout << "Email Address: ";
  			cin.ignore();
  			cin.getline(email,99);
  			cout << endl;	
		  }
		  
//show data
void showData()
		  {
		  	cout << "Name: " << name << endl;
		  	cout << "Cnic Number: " << cnic << endl;
		  	cout << "Phone number: " << phone_num << endl;
		  	cout << "Address: " << address << endl;
		  	cout << "Gender: " << gender << endl;
		  	cout << "Customer ID: " << Customer_ID << endl;
		  	cout << "Subscription ID: " << Subscription_ID << endl;
		  	cout << "Email Address: " << email << endl;
		  }
		  
//display data from file
void DisplayCustomer()
		  {
		  		ifstream fin;
		    	fin.open("Customer_data.txt", ios::in);
		    	if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
				else
				{
					fin.read((char*)this,sizeof(*this));
					while(!fin.eof())
					{
						showData();
						fin.read((char*)this,sizeof(*this));
					}	
				}
		fin.close();
		  }
		
//add customer
void Add() 
		{
			ofstream fout;
			fout.open("Customer_data.txt",ios::app);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		
//delete data
void deleteRecord(char *s)
{
	ifstream fin;
	ofstream fout;
	fin.open("Customer_data.txt",ios::in);
	if(!fin)
	{
		cout<<"File Not Found !"<<endl;
	}
	else
	{
		fout.open("tempStudents.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(name,s))
			{
				fout.write((char*)this,sizeof(*this));
			}
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		fout.close();
		remove("Customer_data.txt");
		rename("tempStudents.txt","Customer_data.txt");
	}
}

//searchStudent
int search(char *ptr)
			{
				bool flag = false;
				ifstream fin;
				fin.open("Customer_data.txt", ios::in);
				if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
			else
			{
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(strcmp(name,ptr)==0)
					showData();

					fin.read((char*)this,sizeof(*this));
				}	
			}
			if(flag == false)
			{
				cout << "No such record" << endl;
			}
			fin.close();

		}
		
//updateData	
void updateRecord(char *t)
{
	fstream file;
	file.open("Customer_data.txt", ios::in|ios :: out| ios::ate);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(t,name))
		{  
		    InputData();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
}	

int TotalRecords()
{
			int i=0;
		    	ifstream fin;
		    	fin.open("Customer_data.txt", ios::in);
		    	if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
				else
				{
					fin.read((char*)this,sizeof(*this));
					while(!fin.eof())
					{
						i++;
						fin.read((char*)this,sizeof(*this));
					}	
					
				}
				
				cout << "Total records: " << i << endl;
				fin.close();
				return i;
}	
	
		
};

int main()
{
	
}
	
