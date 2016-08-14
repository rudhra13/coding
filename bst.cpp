#include<iostream>
#include<queue>
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

int findHeight(bstnode* root)
{
	if(root==NULL)return -1;
	else return (max(findHeight(root->left),findHeight(root->right))+1);
}
//traverse in inorder
void inorder(bstnode* root)
{
	if(root!=NULL)
	{
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	}
}

//traverse in preorder
void preorder(bstnode* root)
{
	if(root!=NULL)
	{
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	}
}

//traverse in postorder
void postorder(bstnode* root)
{
	if(root!=NULL)
	{
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	}
}

void levelorder(bstnode* root)
{
	if(root==NULL)return;
	queue<bstnode*> q;
	q.push(root);
	while(!q.empty())
	{
		bstnode* curr=q.front();
		cout<<curr->data<<" ";
		if(curr->left!=NULL)q.push(curr->left);
		if(curr->right!=NULL)q.push(curr->right);
		q.pop();
	}
	
	
}

int main()
{
 	bstnode* root=NULL;
 	root=insert(root,5);
 	insert(root,7);
 	insert(root,3);
 	insert(root,6);
 	
 	cout<<"inorder traversal: ";
 	inorder(root);
 	
	cout<<"\npreorder traversal: ";
 	preorder(root);
 	
 	cout<<"\npostorder traversal: ";
 	postorder(root);
 	
 	cout<<"\nlevelorder traversal: ";
 	levelorder(root);
 	
 	cout<<"\nheight of tree is: ";
 	cout<<findHeight(root);
 	
 	cout<<endl<<"\nenter the number to search:";
 	int num;
 	cin>>num;
 	if(search(root,num))cout<<"\ndata found";
 	else cout<<"\ndata not found";
 	
	return 0;
}
