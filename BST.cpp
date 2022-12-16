#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
class TREE_NODE 
{
public:
	int key;
	int key_count;
	TREE_NODE *left;
	TREE_NODE *right;
	TREE_NODE *parent;
	
public:
	TREE_NODE(int key=-1,int count=1)
	{
		this->key=key;
		this->left=NULL;
		this->right=NULL;
		this->parent=NULL;	
		this->key_count=count;
	}	
};

class PAIR
{
public:
	int key;
	int times;
public:
	PAIR(int key=0,int times=0)
	{
		this->key=key;
		this->times=times;	
	}
};
class BST
{
public:
	TREE_NODE *root;
public:
	BST()
	{
		this->root=NULL;
	}
	void INORDER_RECURSIVE(TREE_NODE *x)
	{
		if(x->left!=NULL)
		{
			INORDER_RECURSIVE(x->left);
		}
		cout<<"(key,key_count):("<<x->key<<","<<x->key_count<<")"<<endl;
		if(x->right!=NULL)
		{
			INORDER_RECURSIVE(x->right);
		}
	}
	void INORDER_RECURSIVE()
	{
		cout<<"The result of inorder of the binary tree with recursion is:"<<endl;
		INORDER_RECURSIVE(this->root);
		cout<<"end inorder with recursion."<<endl;
	}
	
	void PREORDER_RECURSIVE(TREE_NODE *x)
	{
		cout<<"(key,key_count):("<<x->key<<","<<x->key_count<<")"<<endl;
		if(x->left!=NULL)
		{
			PREORDER_RECURSIVE(x->left);
		}
		if(x->right!=NULL)
		{
			PREORDER_RECURSIVE(x->right);
		}
	}
	void PREORDER_RECURSIVE()
	{
		cout<<"The result of preorder of the binary tree with recursion is:"<<endl;
		PREORDER_RECURSIVE(this->root);
		cout<<"end preorder with recursion."<<endl;
	}
	
	void PREORDER_MSG_RECURSIVE(TREE_NODE *x,TREE_NODE *y,int msg_type)
	{
		if(msg_type==1)
		{
			cout<<x->key<<" is the left child of "<<y->key<<endl;	
		}else if(msg_type==2)
		{
			cout<<x->key<<" is the right child of "<<y->key<<endl;
		}else
		{
			cout<<x->key<<" is the root"<<endl;
		}
		
		if(x->left!=NULL)
		{
			PREORDER_MSG_RECURSIVE(x->left,x,1);
		}
		if(x->right!=NULL)
		{
			PREORDER_MSG_RECURSIVE(x->right,x,2);
		}
	}
	void PREORDER_MSG_RECURSIVE()
	{
		cout<<"The result of preorder of the binary tree with recursion is:"<<endl;
		PREORDER_MSG_RECURSIVE(this->root,this->root,0);
		cout<<"end preorder with recursion."<<endl;
	}
	
	///has problem
	void PREORDER_NONRECURSIVE()
	{
		cout<<"ready to preorder with NON-recursion."<<endl;
		if(this->root==NULL)
		{
			cout<<"There are NO nodes in the binary tree."<<endl;
			return;
		}
		TREE_NODE *curr=new TREE_NODE();
		curr=this->root;
		vector<int> visited;
		vector<int> walk;
		int root_boundary=1;
		int root_visited=1;
		if(this->root->left!=NULL)
		{
			root_boundary++;
			curr=curr->left;
		}
		if(this->root->right!=NULL)
		{
			root_boundary++;
		}
		root_visited=1;
		int cnts=0;
		while(curr!=NULL)
		{
			
			cnts++;
			cout<<"curr_cnts:"<<cnts<<endl;
			int temp=0;
			if(curr->left==NULL)
			{
				if(curr->right==NULL)
				{
					temp=1;
					visited.push_back(curr->key);
					curr=curr->parent;
					continue;
				}
				else
				{
					temp=2;
				}
			}
			else 
			{
				if(curr->right==NULL)
				{
					temp=3;
				}
				else
				{
					temp=4;
				}
			}
			
			int count=0;
			int root_count=0;
			bool isVisited=false;
			int idx=0;
			//check the key visited how many times;
			for (std::vector<int>::iterator it = walk.begin(); it != walk.end(); ++it,++idx)
			{		 
				if((*it)==curr->key)
				{
					count++;
				}
				if((*it)==this->root->key)
				{
					root_count++;
				}
			}			
			visited.push_back(curr->key);
			if(root_count>=root_boundary)
			{
				cout<<"YA"<<endl;
				break;
			}
			if(count==0)
			{
				walk.push_back(curr->key);
			}
			if((temp==2||temp==3)&& count>=1)
			{
				curr=curr->parent;
			}
			else if(temp==4 && count>=2)
			{
				curr=curr->parent;
			}
			else if(temp==4 && count==1)
			{
				curr=curr->right;
			}
			else if(count==0)
			{
				if(temp==2)
				{
					curr=curr->left;
				}
				else if(temp==3)
				{
					curr=curr->right;
				}
				else if(temp==4)
				{
					curr=curr->left;
				}
			}
		}
		cout<<"end preorder with NON-recursion."<<endl;
	}
	void POSTORDER_RECURSIVE(TREE_NODE *x)
	{
		if(x->left!=NULL)
		{
			POSTORDER_RECURSIVE(x->left);
		}
		if(x->right!=NULL)
		{
			POSTORDER_RECURSIVE(x->right);
		}
		cout<<"(key,key_count):("<<x->key<<","<<x->key_count<<")"<<endl;
	}
	void POSTORDER_RECURSIVE()
	{
		cout<<"The result of postorder of the binary tree with recursion is:"<<endl;
		POSTORDER_RECURSIVE(this->root);
		cout<<"end postorder with recursion."<<endl;
	}
	void POSTORDER()
	{
		
	}
	void INSERT(int key)
	{
		if(this->root==NULL)
		{
			TREE_NODE *curr=new TREE_NODE(key);
			this->root=curr;
			return;
		}
		TREE_NODE *curr=new TREE_NODE();
		curr=this->root;
		while(curr!=NULL)
		{
			if(key<curr->key)	
			{
				if(curr->left==NULL)
				{
					TREE_NODE *tnode=new TREE_NODE(key,1);
					tnode->parent=curr;
					curr->left=tnode;
					tnode->left=NULL;
					tnode->right=NULL;
					return;
				}
				curr=curr->left;
			}
			else if(key>curr->key)
			{
				if(curr->right==NULL)
				{
					TREE_NODE *tnode=new TREE_NODE(key,1);
					tnode->parent=curr;
					curr->right=tnode;
					tnode->left=NULL;
					tnode->right=NULL;
					return;
				}
				curr=curr->right;
			}
			else
			{
				
			}
			
		}
	}
	
};
void BST_test()
{
	BST *bst=new BST();
	bst->INSERT(16);
	bst->INSERT(8);
	bst->INSERT(4);
	bst->INSERT(12);
	bst->INSERT(24);
	 
	bst->PREORDER_MSG_RECURSIVE();
	//bst->INORDER_RECURSIVE();
	//bst->PREORDER_RECURSIVE();
	//bst->POSTORDER_RECURSIVE();
	
	
	//bst->PREORDER_NONRECURSIVE(); //BUG
}
int main()
{
	BST_test();
	return 0;
}
