#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>
using namespace std;


int knapsack01(vector<int> C,vector<int> P,int W,int earn)
{
	cout<<"W:"<<W<<",earn:"<<earn<<endl;
	if(C.empty())
	{
		return earn;
	}
	if(C[0]>W)
	{
		return earn;
	}
	int old_earn=earn;
	int old_W=W;
	
	W=W-C[0];
	earn=earn+P[0];
	C.erase(C.begin()+0);
	P.erase(P.begin()+0);
	int non_selected_val=knapsack01(C,P,old_W,old_earn);
	int selected_val=knapsack01(C,P,W,earn);
	int val=max(non_selected_val,selected_val);
	return val;
}
int knapsack01_NONRECURSIVE(vector<int> C,vector<int> P,int W)
{
	int C_sz=C.size();
	int **arr=new int *[C_sz+1];
	for(int k=0;k<C_sz+1;k++)
	{
		arr[k]=new int[W+1];
		for(int j=0;j<W+1;j++)
		{
			arr[0][j]=0;
		}
	}
	
	for(int k=0;k<C_sz+1;k++)
	{
		arr[k][0]=0;
	}
	for(int j=0;j<W+1;j++)
	{
		arr[0][j]=0;
	}
	
	for(int j=1;j<C_sz+1;j++)
	{
		for(int k=1;k<W+1;k++)
		{
			int no_selected=arr[j-1][k];
			int selected=(arr[j-1][k-C[j]]+P[j]);
			arr[j][k]=max(no_selected,selected);
		}
	}
	int answer=arr[C_sz][W];
	
	for(int j=0;j<C_sz+1;j++)
	{
		delete arr[j];
	}
	delete arr;
	return answer;
}
int main()
{
	vector<int> C;
	C.push_back(10);
	C.push_back(20);
	C.push_back(30);
	vector<int> P;
	P.push_back(1);
	P.push_back(2);
	P.push_back(3);
	int W=60;
	//int earn=knapsack01(C,P,W,0);
	int earn=knapsack01_NONRECURSIVE(C,P,W);
	cout<<"You can earn at most "<<earn<<" money."<<endl;
	return 0;
}
