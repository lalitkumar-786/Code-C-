/* The closer you see , the less you observe */

#include<bits/stdc++.h>
using namespace std;
#define boost std::ios::sync_with_stdio(false);
#define LL long long int
#define MOD 1000000007
#define MIN INT_MIN
#define MAX INT_MAX
#define mp make_pair
LL gcd(LL a,LL b)
{
	if(a==0)
	    return b;
	return gcd(b%a,a);
}

int lennode;//for storing the lenght of link list//

struct node
{
	int data;
	struct node * left;
	struct node *right;
};
void display(struct node *head)
{
	cout<<"-----Elements are ----"<<endl;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		lennode++;
		cout<<temp->data<<endl;
		temp=temp->right;
	}
}
void revdisplay(struct node *head)
{
	cout<<"---Reverse Link ----"<<endl;
	struct node *temp,*start;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->right;
		if(temp==NULL)
				break;
		start=temp;
	}
	while(start!=NULL)
	{
		cout<<start->data<<endl;
		start=start->left;
	}
}
void remnode(struct node **head,int pos)
{
	struct node *temp;
	temp=*head;
	if(pos==0)
	{
		*head=temp->right;
		free(temp);
	}
	else
	{
		while(pos--)
			temp=temp->right;
		(temp->left)->right=temp->right;
		free(temp);
	}	
}	
int main()
{
	boost;
	int t,n,x,del;
	struct node *head,*cur,*temp;
	cout<<"Enter no. of nodes "<<endl;
	cin>>n;
	cout<<"Enter elements : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		cur=(struct node*)malloc(sizeof(node));
		if(i==0)
		{
			head=(struct node*)malloc(sizeof(struct node));
			head->data=x;
			head->left=NULL;
			head->right=NULL;
			temp=head;
		}
		else
		{
			temp->right=cur;
			cur->data=x;
			cur->right=NULL;
			cur->left=temp;
			temp=cur;
		}
	}
	display(head);
	cout<<"Length is "<<lennode<<endl;
	revdisplay(head);
	cout<<"Enter node to delete "<<endl;
	cin>>del;
	remnode(&head,del);
	display(head);
	return 0;
}

