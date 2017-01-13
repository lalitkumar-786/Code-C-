#include<bits/stdc++.h>
using namespace std;
multiset<int> graph[4*100005];
multiset<int>::iterator itm,itma,itmb;
vector<pair<int,int> > oedges;
set<pair<int,int> > fedges;  
set<pair<int,int> >::iterator itv,its;
int v,e,a,b,parentnode,src;
bool visited[4*100005]={false};
void bfs()
{
    queue<int> Q;
    Q.push(parentnode);
    visited[parentnode] = true;
    while(!Q.empty())
	{
        int vertex = Q.front();
		 Q.pop();
        for(itm =graph[vertex].begin();itm!=graph[vertex].end();itm++)
		{         
		   if(!visited[*itm])
            {
            Q.push(*itm);
           visited[*itm] = true;
			}       
        }
    }
}
bool isconnected()
{
	int i;
	for(i=1;i<=v;i++)
	{
		if(visited[i]==false)
			return false;
	}
	return true;
}
int main()
{
	int count=0,flag=0,i,cur,next;
	cin>>v>>e;
	int eg=e;
	while(eg--)
	{
		cin>>a>>b;
		if(count==0)
			parentnode=a;
		graph[a].insert(b);
		graph[b].insert(a);
		oedges.push_back(make_pair(a,b));
		count++;
	}
	bfs();
	bool is_in1,is_in2;
	int degree=0;
	for(i=1;i<=v;i++)
	{
		if(graph[i].size()%2==0)
			continue;
		else
			{
				degree=1;
				break;
			}
	}
	if(degree==1)
	{
					cout<<"NO"<<endl;
	}
	else
		{
		if(isconnected())
		{
	   	for(i=1;i<=v;i++)
		{
			parentnode=cur;
			//cur=parentnode;
			cur=i;
			while(graph[cur].size()!=0)
			{
				itm=graph[cur].begin();	
				next=*itm;
			//		cout<<"for node "<<cur<<endl;					
			if(is_in1=graph[cur].find(*itm)!=graph[cur].end())
				{
					itma=graph[cur].find(*itm);
					graph[cur].erase(itma);
					fedges.insert(make_pair(cur,next));
				}
				if(is_in2=graph[next].find(cur)!=graph[next].end())	
				{
					itmb=graph[next].find(cur);
					graph[next].erase(itmb);	
				}
				//itm++;
				if(next==parentnode)
				{
		//			cout<<"----parent node terminated..----"<<endl;
							break;
					
				}
				cur=next;
			}
		}
			itv=fedges.begin();
	/*	for(i=1;i<=e;i++)
		{
			cout<<"----"<<endl;
			cout<<itv->first<<" "<<itv->second<<endl;
			itv++;
		}*/
		cout<<"YES"<<endl;
		set<pair<int,int> >:: iterator it;
		it=fedges.begin();
		vector<pair<int,int> >::iterator ite;
		ite=oedges.begin();
		bool is_in;
		for(i=1;i<=e;i++)
		{
			if(is_in=fedges.find(*ite)!=fedges.end())
				cout<<ite->first<<" "<<ite->second<<endl;
			else
				cout<<ite->second<<" "<<ite->first<<endl;
				ite++;
		}
		}
		else
		cout<<"NO"<<endl;
		}

	

}
