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

struct Stack {
	int data;
	struct Stack *next;
};

void push(struct Stack** top,int data) {
	struct Stack *new_node = new Stack;
	new_node->data=data;
	new_node->next=*top;
	*top=new_node;
}

void pop(struct Stack **top) {
	if(*top==NULL) {
		cout<<"---- Stack is empty!!"<<endl;
		return;
	}
	else {
		struct Stack *temp;
		temp=*top;
		cout<<"Popped element :"<<temp->data<<endl;
		*top=(*top)->next;
		free(temp);
	}
}

void display(struct Stack **top) {
	struct Stack *cur;
	cout<<"Stack contents..."<<endl;
	cur=*top;
	while(cur!=NULL) {
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}

int main()
{
	boost;
	int t,x,data;
	struct Stack * top=NULL;
	while(1) {
		cout<<"--------------Select an option-----------------"<<endl;
		cout<<"1. Push element"<<endl;
		cout<<"2. Pop element"<<endl;
		cout<<"3. Display stack"<<endl;
		cin>>x;
		switch(x) {
			case(1): cout<<"Enter the data to be inseted.."<<endl;
				 cin>>data;
				 push(&top,data);
				 break;
			case(2): pop(&top);
				 break;
			case(3): display(&top);
				 break;
			case(4): return 0;

		}
	}
	return 0;
}

