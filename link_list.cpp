#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node  *next;	
};
void printlist(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		cout<<"data "<<temp->data<<endl;
		temp=temp->next;	
	} 
}
void reverselist(struct node **head)
{
	struct node *temp,*pre=NULL,*current;
	current=*head;
	while(current!=NULL)
	{
		temp=current->next;
		current->next=pre;
		pre=current;
		current=temp;
	}
	*head=pre;
}
int main()
{
	std::ios::sync_with_stdio(false);
	struct node *head;
	struct node *first;
	struct node *second;
	struct node *third;
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->next=first;
	first->data=20;
	first->next=second;
	second->data=12;
	second->next=third;
	third->data=23;
	third->next=NULL;
	cout<<"simple "<<endl;
	printlist(head);

	reverselist(&head);
	cout<<"After reversed "<<endl;
 	printlist(head);
	
	 return 0;
}

