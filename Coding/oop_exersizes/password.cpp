#include <iostream>
using namespace std ; 

int main()
{
    int password= 999 , attemp ;
    int count = 0 ; 
    bool correct = false;

    while (count<3 && correct == false) 
    {
        cout<< "password= ";
        cin >>attemp; 
        if (attemp == password)
        {
        	system("cls");
            cout<<"welcome!!!"; 
            correct = true;
        }
        else
        {
            count +=1;
            if (count<3)
            {
            	system("cls");
            	cout<<3-count<<" tries left \n"; 
			}
            if (count==3)
            {
				system("cls");
				cout<<"Locked!!!";
            	system("pause");
				
			}
        }
        
	}
    return 0; 

}
