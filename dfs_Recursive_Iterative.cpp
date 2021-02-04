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
void dfsIterative(int V,vector<int> v[]) {
	int arr[V]={false};
	stack<int> s;
	s.push(0);
	arr[0]=true;
	
	while(!s.empty()) {
		int node=s.top();
		s.pop();

		cout<<node<<" ";
		for(auto it=v[node].begin();it!=v[node].end();it++) {
			if(!arr[*it]) {
				s.push(*it);
				arr[*it]=true;
			}
		}
	}
	cout<<endl;
}

int visited[100]={false};

void dfsRecursive(int V,vector<int> v[],int node) {
	
	visited[node]=true;
	cout<<node<<" ";
	for(auto it=v[node].begin();it!=v[node].end();it++) {
		if(!visited[*it]) {
			visited[*it]=true;
			dfsRecursive(V,v,*it);
		}
	}
}



int main()
{
	boost;
	int t;
	int V,E,a,b;
	cin>>V>>E;
	vector<int> v[V];
	while(E--) {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout<<"DFS using iterative approach.."<<endl;
	dfsIterative(V,v);

	cout<<"DFS using recursive approach.."<<endl;
	dfsRecursive(V,v,0);
	cout<<endl;
	return 0;
}

