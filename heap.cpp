/* The closer you see , the less you observe */

// A MAX HEAP

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
class Heap {
	
private:
	vector<int> v;
	int parent(int index) {return (index-1)/2;};
	int lchild(int index) {return (index*2)+1;};
	int rchild(int index) {return (index*2)+2;};
public:
	void display();
	void heapifyUp(int index);
	void heapifyDown(int index);
	void extractMax();
	void insertHeap(int data);
};

void Heap::heapifyUp(int index) {
	if(index<1 or index>v.size())
		return;
	if(v[index]>v[parent(index)]) {
		swap(v[index],v[parent(index)]);
		heapifyUp(parent(index));
	}
}

void Heap::heapifyDown(int index) {
	if(index<0 or index>=v.size())
		return;
	int greater=index;
	if(v[index]<=v[lchild(index)] and lchild(index)<v.size())
		greater=lchild(index);
	if(v[greater]<v[rchild(index)] and rchild(index)<v.size()) 
		greater=rchild(index);
	if(index!=greater) {
		swap(v[index],v[greater]);
		heapifyDown(greater);
	}
}

void Heap::insertHeap(int data) {
	v.push_back(data);
	heapifyUp(v.size()-1);
	cout<<"Element has been inserted successfully.."<<endl;
}

void Heap::extractMax() {
	if(v.size()==0)
		return ;
	int result=v[0];
	v[0]=v[v.size()-1];
	v.pop_back();
	heapifyDown(0);
	cout<<"-----> The Element has been deleted successfully "<<result<<endl;
}

void Heap::display() {
	cout<<"Level order traversal: "<<endl;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	boost;
	int t,data,choice;
	Heap h;
	while(1) {
		cout<<"Enter the choice: "<<endl;
		cout<<"1. Insert a number \n2. Extract max number\n3. Display the items"<<endl;
		cin>>choice;
		switch(choice) {
			case(1):cout<<"Enter data to be inserted.. "<<endl; 
				cin>>data;
				h.insertHeap(data);
				break;
			case(2): h.extractMax();
				break;
			case(3):h.display();
				break;
		}
	}
	return 0;
}

