#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define INF 1000000007
LL d[100005];
vector<pair<LL,LL> > graph[100001];
vector<pair<LL,LL> > ::iterator itv;
void dijkstra(int root)
{
	set<pair<LL,LL> > Myset;
	set<pair<LL,LL> > ::iterator its;
	int u,v,wt;
	d[root]=0;
	Myset.insert(make_pair(0,root));
	while(Myset.size()!=0)
	{
		its=Myset.begin();
		u=its->second;
		Myset.erase(its);
		for(itv=graph[u].begin();itv!=graph[u].end();itv++)
		{
			v=itv->first;
			wt=itv->second;
			if(d[v]>d[u]+wt)
			{
				if(d[v]!=INF)
				{
					Myset.erase(Myset.find(pair<LL,LL>(d[v],v)));
				}
				d[v]=d[u]+wt;
				Myset.insert(make_pair(d[v],v));
			}
		}
	}	
} 

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		LL n,k,x,m,s,a,b,c,e,src;
		set<pair<LL,LL> > myset;
		cin>>n>>e;
		while(e--)
		{
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b,c));
			graph[b].push_back(make_pair(a,c));
		}
		cin>>src;
		for(int i=1;i<=n;i++)
			d[i]=INF;
		dijkstra(src);
		for (int i=1;i<=n;i++)
			cout<<d[i]<<" ";
		cout<<endl;	
	}
	return 0;
}
