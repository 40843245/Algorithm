#include <iostream>
using namespace std;
#include <climits>
struct Matrix
{
	int x,y;
	Matrix(int x=1,int y=1)
	{
		this->x=x,this->y=y;
	}	
};
class Matrix_Sequence
{
public:
	int numOfMatrix;
	int curr_idx;
	Matrix *seq;
	int *p;
	int **m;
	int **s;
	
public:	
	Matrix_Sequence()
	{
		this->numOfMatrix=0;
		this->curr_idx=0;
	}
	
public:
	void displayAllMatrix()
	{
		for(int i=0;i<this->curr_idx;i++)
		{
			cout<<"Matrix["<<i<<"] size=("<<this->seq[i].x<<","<<this->seq[i].y<<")."<<endl;
		}
	}
	void displayP()
	{
		for(int i=0;i<this->curr_idx;i++)
		{
			cout<<"p["<<i<<"]="<<this->p[i]<<endl;
		}
	}
	void displayM()
	{
		for(int i=0;i<this->curr_idx;i++)
		{
			for(int j=0;j<this->curr_idx;j++)
			{	
				cout<<"m["<<i<<"]["<<j<<"]="<<this->m[i][j]<<endl;
			}	
		}
		cout<<endl;
	}
	void displayS()
	{
		for(int i=0;i<this->curr_idx;i++)
		{
			for(int j=0;j<this->curr_idx;j++)
			{	
				cout<<"s["<<i<<"]["<<j<<"]="<<this->s[i][j]<<endl;
			}	
		}
		cout<<endl;
	}
	void display_Matrix_Multiplication()
	{
		this->displayP();
		this->displayM();
		this->displayS();
			
	}
	void allocateMatrixSequence(int numOfMatrix)
	{
		this->numOfMatrix=numOfMatrix;
		seq=new Matrix[numOfMatrix];
	}
	void appendMatrix(Matrix *m)
	{
		if(this->curr_idx>=this->numOfMatrix)
		{
			cout<<"error!!! Out of bound!!!"<<endl;
			return;
		}
		this->seq[this->curr_idx]=*m;
		this->curr_idx++;
	}
	bool Matrix_Multiplication_Check()
	{
		int prev=this->seq[0].y;
		int curr=this->seq[1].x;
		for(int i=1;i<this->curr_idx;i++)
		{
			if(prev!=curr)
			{
				return -1;
			}
			prev=this->seq[i].y;
			curr=this->seq[i+1].x;
		}
		return 1;
	}
	void allocateTable()
	{
		this->m=new int *[this->curr_idx];
		for(int i=0;i<this->curr_idx;i++)
		{
			this->m[i]=new int[this->curr_idx];
		}
		
		this->s=new int *[this->curr_idx];
		for(int i=0;i<this->curr_idx;i++)
		{
			this->s[i]=new int[this->curr_idx];
		}
	}
	void allocateMatrixSize()
	{
		this->p=new int[this->curr_idx];
		for(int i=0;i<this->curr_idx;i++)
		{
			this->p[i]=this->seq[i].x;
		}
	}
	
	void Matrix_Multiplication()
	{
		bool ok=this->Matrix_Multiplication_Check();
		if(ok!=1)
		{
			cout<<"We can NOT multiply these matrix."<<endl;
			return ;
		}
		this->allocateTable();
		this->allocateMatrixSize();
		this->displayP();
		
		for(int i=0;i<this->curr_idx;i++)
		{
			for(int j=0;j<this->curr_idx;j++)
			{
				this->m[i][j]=0;
				this->s[i][j]=0;
			}
			this->m[i][i]=0;
		}
		
		for(int i=0;i<this->curr_idx;i++)
		{
			for(int j=0;j<this->curr_idx-i;j++)
			{
			
				if(i==j)
				{
					this->m[i][j]=0;
				}else
				{
					int minM=INT_MAX;
					for(int k=i;k<j;k++)
					{
						minM=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
						if(minM<m[i+j][i+j+j])
						{
							m[i+j][i+j+j]=minM;
							s[i][j]=k;
						}
					}
				}
			}
		}
		this->display_Matrix_Multiplication();
	}
};
int main()
{
	Matrix_Sequence *MS=new Matrix_Sequence();
	MS->allocateMatrixSequence(5);
	MS->appendMatrix(new Matrix(5,10));
	MS->appendMatrix(new Matrix(10,100));
	MS->appendMatrix(new Matrix(100,5));
	MS->displayAllMatrix();
	MS->Matrix_Multiplication();
	
	return 0;
}
