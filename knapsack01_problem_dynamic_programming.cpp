#include<iostream>
using namespace std;
#include <algorithm>
class BAG
{
public:
	int max_load;
	int curr_load;
	int *price;
	int *weight;
	int numOfItems;
	int max_profit;
	int **B;
public:	
	BAG()
	{
		this->numOfItems=0;
	}
public:
	void allocateB()
	{
		B=new int *[this->numOfItems];
		for(int i=0;i<this->numOfItems;i++)
		{
			B[i]=new int [this->max_load];
		}
	}
	void setNumOfItems(int numOfItems)
	{
		this->numOfItems=numOfItems;
		this->price=new int[this->numOfItems];
		this->weight=new int[this->numOfItems];
	}
	void setMaxLoad(int max_load)
	{
		this->max_load=max_load;
	}
	void setPrice(int *arr)
	{
		for(int i=0;i<this->numOfItems;i++)
		{
			this->price[i]=arr[i];
		}
	}
	void setWeight(int *arr)
	{
		for(int i=0;i<this->numOfItems;i++)
		{
			this->weight[i]=arr[i];
		}
	}
	void knapsack01()
	{
		this->allocateB();
		this->max_profit=0;
		this->curr_load=this->max_load;
		for(int k=0;k<this->numOfItems;k++)
		{
			if(this->weight[k]>this->curr_load)
			{
				B[k][this->curr_load]=B[k-1][this->curr_load];
			}else
			{
				if(B[k-1][this->curr_load]>B[k-1][this->curr_load-this->weight[k]]+this->price[k])
				{
					B[k][this->curr_load]=B[k-1][this->curr_load];
				}else
				{
					B[k][this->curr_load]=B[k-1][this->curr_load-this->weight[k]]+this->price[k];
					curr_load-=this->weight[k];
					this->max_profit+=this->price[k];
				}
			}
		}
		
	}
};


int main()
{
	int price[]={2,3,4};
	int weight[]={10,16,20};
	BAG *my_bag=new BAG();
	my_bag->setNumOfItems(3);
	my_bag->setMaxLoad(15);
	my_bag->setPrice(price);
	my_bag->setWeight(weight);
	my_bag->knapsack01();
	cout<<"max_profit:"<<my_bag->max_profit<<endl;
	return 0;
}
