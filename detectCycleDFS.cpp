/* The closer you see, the less you observe */

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> adj[],int node,int parent,bool visited[]) {
    	
    		visited[node]=true;
    		for(auto it=adj[node].begin();it!=adj[node].end();it++) {
    		//	cout<<"Node detected.."<<*it<<endl;
    			if(!visited[*it]) {
    				if(dfs(adj,*it,node,visited))
    				    return true;
    			}
    			else if(visited[*it]==true and (*it)!=parent) {
    				return true;
    			}
    		}
    		return false;
}

bool isCycle(int V, vector<int>adj[]){
	    // Code here
        bool visited[V]={false};
        bool ans;
        for(int i=0;i<V;i++) {
            if(!visited[i])
            ans=dfs(adj,i,-1,visited);
            if(ans==true)
                return true;
        }
        return ans;
}

int main()
{
    int T;
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
	    adj[v].push_back(u);
        }
	cout<<isCycle(V,adj)<<endl;

}

