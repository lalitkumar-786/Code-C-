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
stack<int> s1,s2;
void enqueue(int x) {
	s1.push(x);
}

void dequeue() {
	if(s2.empty()) {
		if(s1.empty())
			return;
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
}

void display() {
	if(s2.empty()) {
		if(s1.empty())
			return;
		while(!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
	}
	cout<<s2.top()<<endl;
}

int main()
{
	boost;
	int t,q,x,choice;
	cin>>q;
	while(q--) {
		cin>>choice;
		switch(choice) {
			case(1): cin>>x;
				 enqueue(x);
				 break;
			case(2): dequeue();
				break;
			case(3): display();
				break;
		}
	}
	return 0;
}

