#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

void display_arr(int *arr,int size,string msg)
{
	for(int i=0;i<size;i++)
	{
		cout<<msg<<"["<<i<<"]="<<arr[i]<<endl;
	}
	cout<<endl;
}
int maximal_subarray(int *arr,int size)
{
	display_arr(arr,size,"arr");
	int *subarray;
	subarray=new int[size];
	subarray[0]=arr[0];
	for(int i=1;i<size;i++)
	{
		if(subarray[i-1]<=0)
		{
			subarray[i]=arr[i];
		}else
		{
			subarray[i]=subarray[i-1]+arr[i];
		}
	}
	display_arr(subarray,size,"subarray");
	int *elem=max_element(subarray,subarray+size);
	int maximal_length=*elem;
	return maximal_length;
}
int main()
{
	int arr[]={1,-2,3,10,-4,7,2,-5};
	int size=sizeof(arr)/sizeof(arr[0]);
	int ans=maximal_subarray(arr,size);
	cout<<"maximal subarray length:"<<ans<<endl;
	return 0;
}
