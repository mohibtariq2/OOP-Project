#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>

using namespace std;

class Restaurant{
	private:
		
	char dish[50];
	char description[200];
    int key;
    float price;
    
    public:
	//******************************************** M E N U   E D I T   F U N C T I O N S ********************************************//
void FileAdd() 
		{
			ofstream fout;
			fout.open("Menu.txt",ios::app);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		
void MenuAdd()
    	{
    		cout << "*** N E W   D I S H ***" << endl;
    		cout << "Dish Name: ";
    		cin.ignore();
    		cin.getline(dish,49);
    		cout << endl;
    		cout << "Description: ";
    		cin.ignore();
    		cin.getline(description,199);
    		cout << endl;
    		cout << "Key: ";
    		cin >> key;
    		cout << endl;
    		cout << "Price: $ ";
    		cin >> price;
    		cout << endl;
			FileAdd();	
		}
		
void ShowDish()
	{		cout << "Dish Name: " << dish << endl;
    		
    		cout << "Description: " << description << endl;
    		
    		cout << "Key: " << key << endl;
    	
    		cout << "Price: $ " << price << endl;
    		
	}
		
void FileOrder() 
		{
			ofstream fout;
			fout.open("CustomerOrder.txt",ios::app);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
				
bool CheckDish(int k)
    {
    	bool flag = false;
				ifstream fin;
				fin.open("Menu.txt", ios::in);
				if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
			else
			{
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(k==key)
					ShowDish();
					fin.read((char*)this,sizeof(*this));
					return true;
				}	
			}
			if(flag == false)
			{
				cout << "No such record" << endl;
				return false;
			}
			fin.close();
	}
	
void DisplayMenu()
	{
		ifstream fin;
		    	fin.open("Menu.txt", ios::in);
		    	if(!fin)
		    	{
		    		cout << "\nFile not found" << endl;
				}
				else
				{
					fin.read((char*)this,sizeof(*this));
					while(!fin.eof())
					{
						ShowDish();

						fin.read((char*)this,sizeof(*this));
					}	
					
				}
				fin.close();
	}
	
void UpdateMenu(int k)
		{
			fstream file;
			file.open("Menu.txt", ios::in|ios :: out| ios::ate);
			file.seekg(0);
			file.read((char*)this,sizeof(*this));
			while(!file.eof())
			{
				if(k == key)
			{  
		    MenuAdd();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			}
			file.read((char*)this,sizeof(*this));
	}
}

// ****************************************** C U S T O M E R   O R D E R   F U N C T I O N S ******************************************//
void NewOrder()
		{
		   int k;
	       cout << "*** N E W   O R D E R ***" << endl;
	       cout << "Enter key: ";
	       cin >> k;
	       if (CheckDish(k) == true)
		   {
	       	FileOrder();   
		   } 
		   
		   else
		   {
		   	  return NewOrder();
		   } 
		}

		void CancelOrder(int k)
		{
			ifstream fin;
			ofstream fout;
			fin.open("CustomerOrder.txt",ios::in);
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
						if(k == key)
				{
					fout.write((char*)this,sizeof(*this));
				}
					fin.read((char*)this,sizeof(*this));
				}
				fin.close();
				fout.close();
				remove("CustomerOrder.txt");
				rename("tempOrder.txt","CustomerOrder.txt");
			}
		}
		
void UpdateOrder(int k)
{
	        fstream file;
			file.open("CustomerOrder.txt", ios::in|ios :: out| ios::ate);
			file.seekg(0);
			file.read((char*)this,sizeof(*this));
			while(!file.eof())
			{
				if(k == key)
			{  
		    NewOrder();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			}
			file.read((char*)this,sizeof(*this));
}
}
		

void GenerateBill()
{
	float total;
	ifstream fin;
	fin.open("CustomerOrder.txt", ios::in|ios :: out);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		total+=price;
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();	
	cout << "Total Payment : " << total << endl;

}
void PaymentType()
{
	int ch, num, pin;
	cout << "1. Cash\n2. Credit Card" << endl;
	cin >> ch;
	switch(ch)
	{
		case 1:
			{
				GenerateBill();
				break;
			}
		
		case 2:
			{
				cout << "Credit Card Number: ";
				cin >>num;
				cout << endl;
				cout << "Enter Pin: ";
				cin >> pin;
				cout << endl;
				GenerateBill();
				
			}
	}
	
}

void AdminRestaurant()
{
	int ch,k;
	cout <<"*** E D I T   M E N U ***" << endl;
	cout << "1. Add New Dish in Menu\n2. Display Menu\n3. Update Menu\n0. Exit" << endl;
	cin >> ch;
	switch(ch)
	{
		case 1:
			{
				DisplayMenu();
				MenuAdd();
				ShowDish();
				break;
			}
		
		case 2:
			{
				DisplayMenu();
				break;
			}
			
		case 3:
			{
				cout << "*** C U R R E N T   M E N U ***" << endl;
				DisplayMenu();
				cout << "Enter Dish Key you want to Update: ";
				cin >> k;
				UpdateMenu(k);
				break;	
			}
			
		case 0:
			{
				break;
			}
}
}

void CustomerOrder()
{
	int ch,ans,k;
	cout <<"*** C U S T O M E R  O R D E R ***" << endl;
	cout << "1. Add Order\n2. Delete Order\n3. Update Order\n4. Generate Bil\n0. Exit" << endl;
	cin >> ch;
	switch(ch)
	{
	case 1:
		{
			NewOrder();
			break;
		}
		
	case 2:
		{
			cout << "Do you want to delete the complete order?\n1. Yes\n2. No" << endl;
			cin >> ans;
			if(ans==1)
			{
				remove("CustomerOrder.txt");
			}
			
			else if(ans==2)
			{
				cout << " Enter key of the Dish to be removed from the order: ";
				cin >>k;
				CancelOrder(k);	
			}
			
		break;	
		}
		
	case 3:
		{
			cout << " Enter key of the Dish to be replaced: ";
		    cin >>k;
			UpdateOrder(k);
			break;
		}
		
	case 4:
		{
			PaymentType();
			break;
		}
		
	case 0:
		{
			break;
		}
	}
			
}
};
