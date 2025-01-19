#include<iostream>
using namespace std; 

int epi(int a , int b)
{
	return a*b;
}
int epi(int a , int b, int c)
{
	return a*b*c;
}

int main()
{
	int a, b, c ; 
	cout <<"dose  arithmo a:"; 
	cin >>a ;
	cout <<"\ndose  arithmo b:"; 
	cin >>b ;
	cout <<"\ndose  arithmo c:"; 
	cin >>c ;
	cout<<"\nginomeno a*b="<<epi(a,b)<<"\n";
	cout <<"ginomeno a*b*c = "<<epi(a,b,c)<<"\n";
	return 0;		
}


