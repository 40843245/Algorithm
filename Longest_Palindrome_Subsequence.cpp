#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define NUMOFLETTER 26
//NOT FINISHED 
string longest_palindrome_subsequence(string s)
{
	int count[NUMOFLETTER]={0};
	int first_pos[NUMOFLETTER]={0};
	int last_pos[NUMOFLETTER]={0};
	cout<<last_pos[5]<<endl;
	vector<char> even_freq;
	vector<char> odd_freq;
	
	s=" "+s;
	cout<<s<<endl;
	for(int j=1;j<s.length();j++)
	{
		count[s[j]-'a']++;
		if(first_pos[s[j]-'a']==0)
		{
			first_pos[s[j]-'a']=j;
		}
		last_pos[s[j]-'a']=j;
	}
	for(int k=0;k<NUMOFLETTER;k++)
	{
		cout<<"index:"<<k<<",first_pos:"<<first_pos[k]<<",last_pos:"<<last_pos[k]<<endl;
	}

	for(int j=0;j<NUMOFLETTER;j++)
	{
		cout<<(char)(j+'a')<<":"<<count[j]<<endl;
		if(count[j]%2==0 && count[j]!=0)
		{
			even_freq.push_back((char)(j+'a'));
		}else if(count[j]%2!=0)
		{
			odd_freq.push_back((char)(j+'a'));	
		}
	}
	
	if(even_freq.empty())
	{
		if(odd_freq.empty())
		{
			return "";
		}
		char c=odd_freq.back();
		string answer=string(1,c);
		return answer;
	}
	int first_char_idx=first_pos[even_freq[0]-'a'];
	int last_char_idx=last_pos[even_freq[0]-'a'];
	for(int k=0;k<even_freq.size();k++)
	{
		//cout<<"(k,even_freq[k]):("<<k<<","<<even_freq[k]<<")."<<endl;
		if(first_pos[even_freq[k]-'a']<first_char_idx)
		{
			first_char_idx=first_pos[even_freq[k]-'a'];
		}
		if(last_pos[even_freq[k]-'a']>last_char_idx)
		{
			last_char_idx=last_pos[even_freq[k]-'a'];
		}
	}
	//cout<<"first_char_idx:"<<first_char_idx<<",last_char_idx:"<<last_char_idx<<endl;
	char first_char=s[first_char_idx];
	char last_char=s[last_char_idx];
	if(first_char==)
	return s;
}

int main()
{
	string s;
	cin>>s;
	string answer=longest_palindrome_subsequence(s);
	
	return 0;
}

