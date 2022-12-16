#include <iostream>
using namespace std;
#include <string>
#define ROW 10000
#define COL 10
int change[ROW][COL];
int total_coins[ROW];
bool isValid[ROW];
int min_total_coins=0;

void display_arr(int *arr,int size,string msg)
{
	for(int i=0;i<size;i++)
	{
		cout<<msg<<"["<<i<<"]="<<arr[i]<<endl;
	}	
}
int sum(int *arr,int size)
{
	int total=0;
	for(int i=0;i<size;i++)
	{
		total+=arr[i];
	}
	return total;
}
void decreasing_sort(int *arr1,int size,int (&arr2)[COL])
{
	for(int i=0;i<size;i++)
	{
		arr2[i]=arr1[i];
	}
	arr2[0]=arr1[0];
	for(int i=1;i<size;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(arr2[j]>arr2[j-1])
			{
				int tempI=arr2[j];
				arr2[j]=arr2[j-1];
				arr2[j-1]=tempI;
			}
		}
	}
}

int making(int *denominator,int N,int size)
{
	int curr_change=N;
	int sorted_denominator[COL];
	display_arr(denominator,size,"denominator");
	decreasing_sort(denominator,size,sorted_denominator);
	display_arr(sorted_denominator,size,"sorted_denominator");
	for(int i=0;i<size;i++)
	{
		change[0][i]=curr_change/sorted_denominator[i];
		curr_change=curr_change%sorted_denominator[i];
	}
	if(curr_change!=0)
	{
		isValid[0]=false;
	}
	display_arr(change[0],size,"change[0]");
	total_coins[0]=sum(change[0],size);
	cout<<"total_coins:"<<total_coins[0]<<endl;
}
int main()
{
	int denominator[]={5,7,14,18,27,30};
	int N=140;
	int size=sizeof(denominator)/sizeof(denominator[0]);
	making(denominator,N,size);
	
	return 0;
}
