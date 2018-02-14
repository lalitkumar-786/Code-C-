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
int len;
struct node
{
	int data;
	struct node *next;
};
int display(struct node *head)
{
	len=0;
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
		len++;
	}
	cout<<"---- List ended -----"<<endl;
	cout<<"List length : ";
	return len;
}
void reverselist(struct node **head)
{
	struct node *temp,*pre=NULL,*cur;
	cur=*head;
	while(cur!=NULL)
	{
		temp=cur->next;
		cur->next=pre;
		pre=cur;
		cur=temp;
	}
	*head=pre;
}
int main()
{
	boost;
	int x,t;
	cout<<"Enter total nodes "<<endl;
	cin>>t;
	struct node *head,*cur,*temp;
	for(int i=0;i<t;i++)
	{
		cin>>x;
		cur=(node*)malloc(sizeof(node));
		if(i==0)
		{	
			head=(node*)malloc(sizeof(node));
			head->data=x;
			head->next=NULL;
			temp=head;
		}
		else
		{
			cur->data=x;
			cur->next=NULL;
			temp->next=cur;
			temp=cur;
		}
	}
	//Print list and displaying length
	cout<<"Link list "<<endl;
	cout<<display(head)<<endl;
	reverselist(&head);
	//Diplaying the reverse of link list
	cout<<"Reverse Link list "<<endl;
	cout<<display(head)<<endl;
	return 0;
}
