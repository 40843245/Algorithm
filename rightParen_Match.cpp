#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cctype>
using namespace std;

class Symbol
{
protected:
	char leftParen;
	char rightParen;
	char andSymbol;
	char orSymbol;
	char notSymbol;
public:
	Symbol()
	{
		cout<<"This class Symbol - constructor was called."<<endl;
		this->leftParen='(';
		this->rightParen=')';
		this->andSymbol='&';
		this->orSymbol='|';
		this->notSymbol='~';
	}
};
class Paren
{
protected:
	vector<int> left_pos;
	vector<int> right_pos;
public:
	Paren()
	{
		this->left_pos.clear();
		this->right_pos.clear();
	}
};
class NoRightParen:public Symbol,public Paren
{
public:
string text;
int currLeftParen;
int currRightParen;
vector <char> allToken;
//stack <char> leftParethesis;
//stack <char> rightParethesis;
char nextToken;
char prevToken;
int currIdx;
bool isEnd;
bool toEnd;

public:
	NoRightParen(string text)
	{
		this->allToken.clear();
		cout<<"On the NoRightParenconstructor"<<endl;
		this->text=text;
		this->isEnd=false;
		
		cout<<"this->text="<<this->text<<endl;
		cout<<"Its length="<<this->text.length()<<endl;
		system("pause");
		
		this->currLeftParen=0;
		this->currRightParen=0;
		
		this->Resize();
		//this->AutoAddRightParen();
		this->AssignAllToken();
		this->FindParen();
		
		cout<<"Before Insert,"<<endl;
		cout<<"Before trimming,"<<endl;
		this->DisplayVector(this->left_pos,"this->left_pos");
		this->DisplayVector(this->right_pos,"this->right_pos");
		
		this->TrimParenPos();
		
		cout<<"After trimming,"<<endl;
		this->DisplayVector(this->left_pos,"this->left_pos");
		this->DisplayVector(this->right_pos,"this->right_pos");
		
		
		cout<<"Ready to insert"<<endl;
		system("pause");
		
		this->InsertRightParen();
		
		cout<<"After Insert,"<<endl;
		cout<<"Before trimming,"<<endl;
		this->DisplayVector(this->left_pos,"this->left_pos");
		this->DisplayVector(this->right_pos,"this->right_pos");
		
		this->TrimParenPos();
		
		cout<<"After trimming,"<<endl;
		this->DisplayVector(this->left_pos,"this->left_pos");
		this->DisplayVector(this->right_pos,"this->right_pos");
	}
public:
	void SetEnd()
	{
		this->isEnd=(this->currIdx>=this->text.length());
	}
	void AssignAllToken()
	{
		this->allToken.clear();
		for(int i=0;i<this->text.length();i++)
		{
			this->allToken.push_back(this->text[i]);
		}
	}
	void FindParen()
	{
		this->SetEnd();
		while(!this->isEnd)
		{
			this->nextToken=this->text[this->currIdx];
			this->currIdx++;
			if(this->nextToken==this->rightParen)
			{
				this->right_pos.push_back(this->currIdx);
				//cout<<"this->nextToken==this->rightParen"<<endl;
				//system("pause");
				this->currRightParen++;	
			}else if(this->nextToken==this->leftParen)
			{
				this->left_pos.push_back(this->currIdx);
				//cout<<"this->nextToken==this->leftParen"<<endl;
				//system("pause");
				this->currLeftParen++;
			}
			this->SetEnd();
		}
	}
	
	void InsertRightParen()
	{

		int insertedPos=0;
		int currPos=0;
		for(;this->left_pos.empty()==false;)
		{
			currPos=this->left_pos.back();			
			this->nextToken=this->text[currPos];
			currPos++;
			this->SetEnd();
			if(!this->isEnd)
			{						
				if(isalpha(this->nextToken))
				{
					this->nextToken=this->text[currPos];
					currPos++;
					this->SetEnd();
					if(!this->isEnd)
					{					
						if(this->nextToken==this->andSymbol || this->nextToken==this->orSymbol)
						{
							this->nextToken=this->text[currPos];
							currPos++;	
							this->SetEnd();
							if(!this->isEnd)
							{
								if(isalpha(this->nextToken))
								{
									insertedPos=currPos;
								}
							}else
							{
								insertedPos=this->text.length()-1;
							}
						}else if(this->nextToken==this->notSymbol)
						{
							this->nextToken=this->text[this->currIdx];
							currPos++;
							this->SetEnd();
							if(!this->isEnd)
							{
								if(isalpha(this->nextToken))
								{
									insertedPos=currPos+1;	
								}
							}else
							{
								insertedPos=this->text.length()-1;
							}
						}
					}
					else
					{
						insertedPos=this->text.length()-1;
					}
				}
			}else
			{
				insertedPos=this->text.length()-1;
			}
				this->right_pos.push_back(insertedPos);
				this->allToken.insert(this->allToken.begin()+insertedPos,this->rightParen);	
				this->left_pos.pop_back();	
				
		}
	}
	void Resize()
	{
		this->right_pos.resize(100);
		this->allToken.resize(100);	
	}
	void AutoAddRightParen()
	{
		this->nextToken='1';
		
		this->currIdx=0;
		this->SetEnd();
		this->toEnd=false;
		while(!this->isEnd)
		{
			this->prevToken=this->nextToken;
			this->nextToken=this->text[this->currIdx];
			this->allToken.push_back(this->nextToken);
			//cout<<"nextToken="<<this->nextToken<<endl;
			if(this->nextToken!=this->leftParen)
			{
				
				this->currIdx++;
				this->SetEnd();
				
				//cout<<"currIdx="<<currIdx<<endl;
				if(this->isEnd)
				{
					this->toEnd=true;
					//cout<<"The while loop in AutoAddRightParen method was forced to break."<<endl;
					//system("pause");
					break;
				}
				this->CheckLeftParenMatch();
			}
			else
			{	
				this->left_pos.push_back(this->currIdx);
				//cout<<"Ready to call the func LeftParenMatch.";
				this->LeftParenMatched();
			}
			this->currIdx++;
			this->isEnd=(this->currIdx>=this->text.length());
			//cout<<"end of inner while loop"<<endl;
			//system("pause");
			/*
			if(this->nextToken==this->notSymbol)
			{
				this->currIdx++;
			}
			else if(this->nextToken==this->andSymbol ||this->nextToken==this->orSymbol)
			{
				this->currIdx++;
			}
			*/			
		}
		cout<<"end of text"<<endl;
		if(this->toEnd)
		{
			for(int i=0;i<(this->currLeftParen-this->currRightParen);i++)
			{
				this->allToken.push_back(this->rightParen);
			}
		}
	}
	void PrevTokenUpdate()
	{
			if(isalpha(this->prevToken))//prevToken==letter
			{
				cout<<"this->prevToken="<<this->prevToken<<", which is a letter."<<endl;
			}else if(this->prevToken==this->orSymbol || this->prevToken==this->andSymbol)//this->prevToken=='or' or this->prevToken='and'
			{
				cout<<"this->prevToken="<<this->prevToken<<", which is a binary connective symbol."<<endl;
			}else if(this->prevToken==this->notSymbol)
			{
				
				cout<<"this->prevToken="<<this->prevToken<<", which is a unary connective symbol."<<endl;
			}
			system("pause");
	}
	void CheckLeftParenMatch()
	{
		cout<<"The func CheckLeftParenMatch was called."<<endl;
		this->prevToken=this->nextToken;
		this->nextToken=this->text[this->currIdx];
		this->allToken.push_back(this->nextToken);
		if(this->nextToken==this->leftParen)
		{
			this->left_pos.push_back(this->currIdx);
			this->LeftParenMatched();
		}else 
		{
			this->PrevTokenUpdate();
		}
		return;
	}
	
	
	void TrimParenPos()
	{
		cout<<"The method TrimParenPos was called."<<endl;
		vector<int>::reverse_iterator itLeft;
		vector<int>::iterator itRight;
		for(;
		this->right_pos.empty()==false && this->left_pos.empty()==false;
		)
		{
			this->left_pos.pop_back();
			this->right_pos.erase(this->right_pos.begin(),this->right_pos.begin()+1);	
		}
	}
	void DisplayVector(vector<char> vec,string msg)
	{
		cout<<"The method DisplayVector was called."<<endl;
		int i=0;
		for(i=0;i<vec.empty()==false && i<vec.size();i++)
		{
			cout<<msg<<"["<<i<<"]="<<(vec[i])<<endl;
		}
		system("pause");
	}
	void DisplayVector(vector<int> vec,string msg)
	{
		cout<<"The method DisplayVector was called."<<endl;
		int i=0;
		for(i=0;i<vec.empty()==false && i<vec.size();i++)
		{
			cout<<msg<<"["<<i<<"]="<<(vec[i])<<endl;
		}
		system("pause");
	}
	void LeftParenMatch()
	{
		
	}
	void LeftParenMatched()
	{
		cout<<"The func LeftParenMatched was called."<<endl;
		this->currLeftParen++;
		bool isMatched=false;
		this->toEnd=false;
		while(!isMatched)
		{
			//cout<<"In the while loop of LeftParenMatch called,"<<endl;
			this->currIdx++;
			this->SetEnd();
			//cout<<"currIdx="<<currIdx<<endl;
			if(this->isEnd)
			{
				this->toEnd=true;
				//cout<<"The while loop in LeftParenMatch method was forced to break."<<endl;
				//system("pause");
				break;
			}
			this->prevToken=this->nextToken;
			this->nextToken=this->text[this->currIdx];
			//cout<<"nextToken="<<this->nextToken<<"."<<endl;
			this->allToken.push_back(this->nextToken);
			system("pause");
			
			if(this->nextToken==this->rightParen)
			{
				this->right_pos.push_back(this->currIdx);
				//cout<<"this->nextToken==this->rightParen"<<endl;
				//system("pause");
				this->currRightParen++;	
			}else if(this->nextToken==this->leftParen)
			{
				this->left_pos.push_back(this->currIdx);
				//cout<<"this->nextToken==this->leftParen"<<endl;
				//system("pause");
				this->currLeftParen++;
			}
			
			this->PrevTokenUpdate();
			
			//this->DisplayResult();
			isMatched=(this->currLeftParen<this->currRightParen);
		}
		cout<<"End of the func LeftParenMatched called."<<endl;
	}
};
int main()
{
	//NoRightParen *ex1=new NoRightParen("(A&(~(B|C");
	//NoRightParen *ex1=new NoRightParen("(A&(~B|C");
	//NoRightParen *ex1=new NoRightParen("(A&(~B)|C");
	//NoRightParen *ex1=new NoRightParen("(A&(~(B|C))|D");
	//NoRightParen *ex1=new NoRightParen("A&(~(B|C))|D)");
	NoRightParen *ex1=new NoRightParen("(A&(~B|C))|(D|E");
	return 0;
}
