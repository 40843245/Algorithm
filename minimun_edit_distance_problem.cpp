#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#define ROW 50
#define COL 50
int c[ROW][COL];
int *tempArr=new int[3];

int C(string s1,string s2)
{
	int s1_length=s1.length();
	int s2_length=s2.length();
	for(int i=0;i<=s1_length;i++)
	{
		for(int j=0;j<=s2_length;j++)
		{
			if(i==0)
			{
				c[i][j]=j;
			}else if(j==0)
			{
				c[i][j]=i;
			}
			else if(s1[i]==s2[j])
			{
				c[i][j]=c[i-1][j-1];
			}
			else
			{
				tempArr[0]=c[i-1][j]+1;
				tempArr[1]=c[i][j-1]+1;
				tempArr[2]=c[i-1][j-1]+1;
				int *elem=min_element(tempArr,tempArr+2);
				int min_val=*elem;
				c[i][j]=min_val;
			}	
		}	
	}
	return c[s1_length][s2_length];
}
int main()
{
	string s1="algorithms";
	string s2="glorious";
	int ans=C(s1,s2);
	cout<<"the minimal edit distance is "<<ans<<endl;
	return 0;
}
