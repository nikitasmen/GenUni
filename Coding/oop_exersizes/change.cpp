#include<iostream>
using namespace std ; 

int main()
{
	float price ,given, change ; 
	cout<<"price =";
	cin >>price;
	cout << "money given = "; 
	cin >>given ; 
	if (price==given)
	
		cout<<"0 euro change";
	
	else if (price <given)
	{
		change = given - price ;
		cout << change<<" euros change"; 
	}
	else
	{
		cout<<"more money needed";
	}
}
