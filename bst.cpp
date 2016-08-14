#include<iostream>
using namespace std;

struct bstnode
{
	int data;
	bstnode* left;
	bstnode* right;
};
//create new node
bstnode* getNewNode(int data)
{
	bstnode* newnode=new bstnode();
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

//insert new node
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

bool search(bstnode* root,int data)
{
	if(root==NULL)return false;
	else if(data == root->data)return true;
	else if(data <= root->data)search(root->left,data);
	else if(data > root->data)search(root->right,data);
	else return false;
	
}
//traverse in inorder
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
 	cout<<endl<<"enter the number to search:";
 	int num;
 	cin>>num;
 	if(search(root,num))cout<<"\ndata found";
 	else cout<<"\ndata not found";
	return 0;
}
