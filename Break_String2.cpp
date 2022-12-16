#include <iostream>
using namespace std;
#include <cstdlib>
#include <limits>

#define SIZEERROR -1
#define ANS_NOTFOUND -2
#define ANS_FOUNDERROR -3

#define check_error(errno) (errno==ANS_NOTFOUND || errno==ANS_FOUNDERROR || errno==SIZEERROR)

//forward declaration
int break_string(int *,int,int,int,int);
int break_string(int *,int,int,int);
//driver routine for test
int break_string(int *,int);


int break_string(int *L,int n)
{
	if(n<0)
	{
		return ANS_NOTFOUND;
	}
	int sz=sizeof(L)/sizeof(L[0]);
	if(sz<=0)
	{
		return SIZEERROR;
	}
	if(sz==1)
	{
		return n;
	}
	return break_string(L,1,n,sz);
}
int break_string(int *L,int s_v,int e_v,int sz)
{
	return break_string(L,s_v,e_v,1,sz);
}
int break_string(int *L,int s_v,int e_v,int s_i,int e_i)
{
	if(e_v<=s_v)
	{
		return ANS_FOUNDERROR;
	}
	if(e_i-1<=s_i)
	{
		return (e_v-s_v+1);
	}
	int must_cost=e_v-s_v+1;
	int min_cost=INT_MAX;
	for(int k=s_i-1;k<e_i-1;k++)
	{
		int l_pivot=k;
		int l_val=L[l_val];
		int left_val=break_string(L,s_v,l_val,s_i,l_pivot-1);
		
		if(check_error(left_val)==true)
		{
			return ANS_FOUNDERROR;
		}
		int right_val=break_string(L,l_val,e_v,l_pivot+1,e_i);
		if(check_error(right_val)==true)
		{
			return ANS_FOUNDERROR;
		}
		int curr_cost=left_val+right_val+must_cost;
		if(curr_cost<min_cost)
		{
			min_cost=curr_cost;
		}
	}
	return min_cost;
	
}
int main()
{
	int L[]={2,8,10};
	int n=20;
	int sz=sizeof(L)/sizeof(L[0]);
	cout<<"sz:"<<sz<<endl;
	int answer=break_string(L,n);
	cout<<"answer:"<<answer<<endl;
	return 0;
}
