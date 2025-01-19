#include <iostream>

using namespace std; 

int eisagogh();
int epejergasia();
int diagrafh();

int main()
{

	int choise;
	do
	{
	
		cout<<"1. eisagogh\n2. epejergasia\n3.diagrafh\n4.ejodos\n..........\nEpilogh:";
		cin>>choise;
		switch(choise)
		{
			case 1:
				system("cls");
				eisagogh();
				break;
			case 2 :
				system("cls");
				epejergasia();
				break;
			case 3:
				system("cls");
				
				diagrafh();
				break;
			case 4:
				break;
			default:
				system("cls");
				
		}
	}while(choise==4); 
	return 0;
}

int eisagogh()
{
	cout<<"eisagogh";
	system("pause");
	return 0;
}
int diagrafh()
{
	cout<<"diagrafh";
	system("pause");
	return 0;
}
int epejergasia()
{
	cout<<"epejergasia";
	system("pause");
	return 0;
}

