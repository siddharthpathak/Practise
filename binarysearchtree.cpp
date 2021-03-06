#include<iostream>
using namespace std;


struct node
{
	int data;
	node *left;
	node *right;
};

struct node* createnode(int x)
{
	struct node* node=new(struct node);
	node->data=x;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct node* insertnode(int x, struct node* root)
{
	if(root==NULL)
	  return createnode(x);
	if(x<root->data)
		root->left=insertnode(x,root->left);
	else if(x>root->data)
		root->right=insertnode(x,root->right);
	return root;
}
void print_preorder(struct node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<endl;
		print_preorder(root->left);
		print_preorder(root->right);
	}
}
void print_inorder(struct node* root)
{
	if(root!=NULL)
	{
		print_inorder(root->left);
		cout<<root->data<<endl;
		print_inorder(root->right);
	}
}

void print_postorder(struct node* root)
{
	if(root!=NULL)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		cout<<root->data<<endl;
	}
}

bool search(struct node* root, int x)
{
	if(root==NULL)
		return false;
	else if(root->data==x)
		return true;
	else if(x<root->data)
		return search(root->left,x);
	else if(x>root->data)
		return search(root->right,x);
}

int tree_size(struct node* root)
{
	if(root!=NULL)
		return(tree_size(root->left)+1+tree_size(root->right));
  return 0;
}

int min_value(struct node* root)
{
	struct node* temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp->data;
}
int main()
{
	int x,ch;
	bool y;
	struct node* root=NULL;
	cout<<"Enter root element\n";
	cin>>x;
	root=createnode(x);
	do
	{
		cout<<"1.Insert nodes\n2.Search\n3.Size\n4.Depth\n5.Minimum Value\n6.Inorder\n7.Preorder\n8.Postorder\n9.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
						  while(true)
					 		{
								cout<<"Enter data to be added\n-1 to stop\n";
								cin>>x;
								if(x==-1)
									break;
								insertnode(x,root);
							}
							break;
			case 2:
							{
								cout<<"Enter node to search\n";
								cin>>x;
								y=search(root,x);
								if(y)
								cout<<"Found\n";
								else
									cout<<"Not found\n";
								break;
							}
			case 3:
							{
								int size=tree_size(root);
						  	cout<<"Size is:"<<size<<endl;
						  	break;
						  }
			case 4:
							{
							  break;
							}
			case 5:
							{
								int min=min_value(root);
								cout<<"Minimum Value:"<<min<<endl;
								break;
							}
			case 6: 
							{
								print_inorder(root);
								break;
							}
			case 7: 
							{
								cout<<"Preorder:\n";
								print_preorder(root);
								break;		
							}
			case 8:
							{
								cout<<"Postorder:\n";
								print_postorder(root);
								break;
							}
		}//switch
	}while(ch!=9);
	
	
	

	

	return 1;
}
