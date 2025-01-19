#include <iostream>
using namespace std;
int expfun(int x,int sum);

int main()
{
	int x ,y ; 
	cout <<"dose bash: "; 
	cin >> x ; 
	cout << "\ndose ektheth: ";
	cin >>y ; 
	cout<<"\n apotelesma: "<<expfun(x,y) ; 
	return 0 ; 
}

int expfun(int x, int y )
{
	if(y == 0 )
		return 1; 
	else 
		return (x*expfun(x,y-1));
}
