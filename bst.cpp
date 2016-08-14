#include<iostream>
using namespace std;

struct bstnode
{
	int data;
	bstnode* left;
	bstnode* right;
};

bstnode* getNewNode(int data)
{
	bstnode* newnode=new bstnode();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
bstnode* insert(bstnode* root,int data)
{
	if(root==NULL)
	{
		root=getNewNode(data);
	}
	
	else if(data <= root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	
	return root;
}

void inorder(bstnode* root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
	}
}
int main()
{
 	bstnode* root=NULL;
 	root=insert(root,5);
 	insert(root,7);
 	insert(root,3);
 	insert(root,6);
 	inorder(root);
	return 0;
}
