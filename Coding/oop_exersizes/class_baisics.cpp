#include<iostream>
using namespace std ; 
int validb(int x, int y , int z );
int validy(int x , int y , int z);

class Dayofyear{
	public:
	
	 int year ;
	 int month ; 
	 int day ;  
};


int main()
{
	Dayofyear birthday , today ; 
	do 
	{
	
	cout<<"dose mera";
	cin>>birthday.day ; 
	cout<<"dose mhna";
	cin>>birthday.month ; 
	cout<<"dose xrono";
	cin>>birthday.year ;
	}while(validb(birthday.day,birthday.month,birthday.year));
	do {
	
	cout<<"dose mera";
	cin>>today.day ;
	cout<<"dose mhna";
	cin>>today.month ; 
	cout<<"dose xrono";
	cin>>today.year  ; 
}
	while(validy(birthday.day,birthday.month,birthday.year));
	
	cout << "birthday = "<<birthday.day<<"/"<<birthday.month<<"/"<<birthday.year ;
	cout <<"\ntoday"<<today.day<<"/"<<today.month<<"/"<<today.year;
	return 0 ;	
}

int validb(int x,int y,int z)
{

	if (x>0&&x<=31&&y>0&&y<=12&&z>1900)
		return 0 ; 
	else
	{
	 	cout<<"lathos stixeia " ;
		return 1;
	}
}

int validy(int x,int y,int z)
{
	if (x>0&&x<=31&&y>0&&y<=12&&z>1900)
		return 0 ; 
	else 
		{
		cout<<"lathos stixeia "	;	
		return 1;
		}
}

