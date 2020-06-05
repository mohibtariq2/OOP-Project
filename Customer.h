#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class Customer
{
	protected:
		char name [50];
        long long  cnic;
  		long long phone_num;
  		char address[100];
  		char gender;
  		int Customer_ID;
  		int Subscription_ID;
  		char email[100];
  		
  	public:
  		void InputData();
  		void showData();
  	    void DisplayCustomer();
  	    void Add();
        void deleteRecord(long long i);
  		int search(long long i);
  		void updateRecord(long long i);
  		int TotalRecords();
  		void Admin_Customer();
  		void Custom_Customer();
  		
			
};
  		
  		
void Customer:: InputData()
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
void Customer::showData()
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
void Customer::DisplayCustomer()
		  {
		  		ifstream fin;
		    	fin.open("record.txt", ios::in);
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
void Customer::Add() 
		{
			InputData();
			ofstream fout;
			fout.open("record.txt",ios::out|ios::app);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		
//delete data
void Customer::deleteRecord(long long i)
{
	ifstream fin;
	ofstream fout;
	fin.open("record.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"File Not Found !"<<endl;
	}
	else
	{
		
		fout.open("temp.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(i!=cnic)
			{
				fout.write((char*)this,sizeof(*this));
			}
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		fout.close();
		getch();
		remove("record.txt");
		getch();
		rename("temp.txt","record.txt");
	}
}

//searchCustomer
int Customer::search(long long i)
			{
				bool flag = true;
				int count=0;
				ifstream fin;
				fin.open("record.txt", ios::in);
				if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
			else
			{
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(i==cnic)
					{
						showData();
						count++;
					}
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
void Customer::updateRecord(long long i)
{
	fstream file;
	file.open("record.txt", ios::in|ios :: out| ios::ate);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(i==cnic)
		{  
		    InputData();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
		}
		file.read((char*)this,sizeof(*this));
	}
}	

int Customer::TotalRecords()
{
			int i=0;
		    	ifstream fin;
		    	fin.open("record.txt", ios::in);
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

void Customer::Admin_Customer()
{
	int x;
	long long nic;
	cout << "*********S E L E C T*********" << endl;
	cout << "<1> Delete a Customer Record\n<2> Edit a Customer Record\n<3> View all Customers\n<4> Total Numbers of Customers\n<0> Exit" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			{
				cout << "Enter the cnic of the customer to be deleted: ";
				cin >> nic;
				cout << endl;
				deleteRecord(nic);
				break;
			}
			
		case 2:
			{
				cout << "Enter the cnic of the customer to be updated: ";
				cin >> nic;
				cout << endl;
				updateRecord(nic);
				break;
			}
			
		case 3:
			{
				cout << "|||||||||||| C U S T O M E R    L I S T ||||||||||||" << endl;
				DisplayCustomer();
				break;
			}
			
		case 4:
			{
				TotalRecords();
				break;
			}
			
		case 0:
			{
				
				break;
			}
			
		default:
			{
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to   continue....!!";
				getch();
			}
	}
	
}

void Customer::Custom_Customer()
{
	int x;
	long long nic;
	cout << "*********S E L E C T*********" << endl;
	cout << "<1> Add a Customer Record\n<2> View all Customers\n<3> Search a specific customer\n<0> Exit" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			{
				cout << "E N T E R   Y O U R   D E T A I L S"<< endl;
				Add();
				break;
			}
			
		case 2:
			{
				cout << "|||||||||||| C U S T O M E R    L I S T ||||||||||||" << endl;
				DisplayCustomer();
				break;
			}
			
		case 3:
			{
				cout << "Enter the cnic of the customer you wish to search: ";
				cin >> nic;
				cout << endl;
				search(nic);
				break;
			}
	}
	
}
