#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getrand( int *arr, int n );
double qsortfixed(int *arr, int n);
void qsortcustom(int *arr,int start, int end);
double selection(int arr[], int n);
double bubblesort(int *arr, int n );
double shaker(int arr[] , int n );

int cmpfunc(const void *a , const void *b)
{
	return ( *(int*)a - *(int*)b);
}

int main()
{
  	int n;
  	time_t start,end;
	double mo,taken;

  	scanf("%d",&n);
	int *arr = (int *) malloc(sizeof(int)*n);
    mo = 0 ;
	for(int i = 0 ;i<3;i++)
	{
		getrand(arr, n);
		start = clock();
		qsortcustom(arr,0,n-1);
		end = clock(); 
		printf("%lf\n",difftime(end,start) );
		mo+= difftime(end,start);
	}
	printf("MESOS OROS QUICKSORT : %lf",mo/3);

 	mo = 0 ;
	for(int i = 0 ;i<3;i++)
	{
		getrand(arr, n);
		taken = qsortfixed(arr,n);
		printf("%lf",taken);
		mo += taken;
	}
	printf("MESOS OROS QSORT : %lf",mo/3);

	mo = 0 ;
	for(int i = 0 ;i<3;i++)
	{
		getrand(arr, n);
		taken = selection(arr, n);
		printf("%lf",taken);
		mo += taken	;
	}
	printf("MESOS OROS SELECTION SORT : %lf",mo/3);
	
	mo = 0 ; 
	for(int i = 0 ; i<3 ; i++)
	{
		getrand(arr, n);
		taken = bubblesort(arr,n);
		printf("%lf",taken);	
		mo += taken	;
	}	
	printf("MESOS OROS BUBBLE SORT : %lf",mo/3);

	mo = 0 ; 
	for(int i = 0 ; i<3 ; i++)
	{
		getrand(arr, n);
		taken = shaker(arr,n);
		printf("%lf",taken);	
		mo += taken	;
	}	
	printf("MESOS OROS SHAKER SORT : %lf",mo/3);

	system("pause");
	return 0; 
}


double shaker(int arr[] , int n )
{
	int temp,i,j;

	for(i = 1 ; i<= n/2 ; i++)
	{
		for(j = i-1 ; j<n/2 ;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		for(j = n- i -1;j>=i ; i--)
		{
			if(arr[j]<arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

double bubblesort(int *arr , int n)
{
	time_t start , end;
	start = clock();
	int temp;
	for(int i = 0 ; i<n-1;i++)
	{
		for(int j = 0 ; j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	end = clock(); 
	return difftime(end,start);
}

double selection(int arr[], int n )
{
	time_t start , end ; 
	start = clock();
	int  j , minj ,min;
	for (int i = 0 ; i < n-1 ; i++)
	{
		min = arr[i] ;
		minj = i ;
		for (int j = i+1; j<n ; j++ )
			if (arr[j]<min)
			{
				min = arr[j];
				minj = j ;
			}
		arr[minj] = arr[j] ; 
		arr[i] = min;
	}
	end = clock();
	return difftime(end,start)*60;
}

void getrand(int *arr, int n )
{
	for(int i = 0 ; i<n ; i++)
		arr[i] = rand()%100; 
}

void qsortcustom(int *arr , int start , int end)
{
	long x , left , right , temp ; 
	
	if (start>= end)	
		return ;
	

	left = start;
	right = end;
	x = arr[start];
	while (left < right)
	{
		while ((arr[left]<= x) && (left<end))
			left++;
		
		while (x<arr[right])
			right--;
		
		if (left<right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp ;
		}
	}
	temp = arr[start];
	arr[start] = arr[right];
	arr[right] =  temp;

	if (right>start)
		qsortcustom(arr,start, right-1);
	if (left < end)
		qsortcustom(arr , right+1 , end ); 

}

double qsortfixed(int *arr, int n)
{
	clock_t start , end ;
	
	start = clock();
	qsort(arr , n, sizeof(int), cmpfunc);
	end = clock(); 
	return ((double)((end - start )/CLOCKS_PER_SEC)*60);
}

//serial search 
int i=0; 
int flag = 0 ; 
while(i<n-1 && flag == 0)
{
	if (num == arr[i]) flag = 1 ; 
}

