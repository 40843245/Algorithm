#include<iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ROW 1000
#define COL 1000

int c[ROW][COL]={0};
int b[ROW][COL]={0};

void display_arr(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"arr["<<i<<"]="<<arr[i]<<"\t";
	}
	cout<<endl;
}

int LCS(int arr1[100],int arr2[100],int length)
{
	int n=length;
	int m=length;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=0;
	}
	for(int j=0;j<=m;j++)
	{
		c[0][j]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr1[i]==arr2[j])
			{
				c[i][j]=c[i-1][j]+1;	
				b[i][j]=3;
			}
			else 
			{
				if(c[i][j-1]>c[i-1][j])
				{
					c[i][j]=c[i][j-1];
					b[i][j]=2;
				}else
				{
					c[i][j]=c[i-1][j];
					b[i][j]=1;
				}
			}
		}
	}
	return c[n][m];
}
void print_LCS(int arr1[100],int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==3)
	{
		print_LCS(arr1,i-1,j-1);
		cout<<arr1[i];
	}else if(b[i][j]==2)
	{
		print_LCS(arr1,i-1,j);
	}else
	{
		print_LCS(arr1,i,j-1);
	}
}
void increasing_sort(int *arr,int n,int (&arr2)[100])
{
	for(int i=0;i<n;i++)
	{
		arr2[i]=arr[i];
	}

	arr2[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(arr2[j]<arr2[j-1])
			{
				int tempI=arr2[j];
				arr2[j]=arr2[j-1];
				arr2[j-1]=tempI;
			}else
			{
				break;
			}
		}
	}
}

int main()
{
	int arr1[8]={4,5,3,1,2,0,6,7};
	int n1=sizeof(arr1)/sizeof(arr1[0]);
	cout<<"n1:"<<n1<<endl;
	int arr2[100];
	increasing_sort(arr1,n1,arr2);
	cout<<"arr1:"<<endl;
	display_arr(arr1,n1);
	cout<<"arr2:"<<endl;
	display_arr(arr2,n1);
	int ans=LCS(arr1,arr2,n1);
	cout<<"LIS(arr1)="<<ans<<endl;
	print_LCS(arr1,n1,n1);
	return 0;
}
