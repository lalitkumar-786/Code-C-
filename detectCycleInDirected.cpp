#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool detectCycle(int src, vector<int> adj[], bool visited[], bool tempVisited[]){
        visited[src] = true;
        tempVisited[src] = true;
       // cout<<"Current node "<<src<<endl;
        for(auto it=adj[src].begin();it!=adj[src].end();it++){
         //   cout<<"Loop on node "<<*it<<endl;
            if(!visited[*it]){
                if(detectCycle(*it, adj, visited, tempVisited))
                    return true;
            }
            else{
                if(tempVisited[*it])
                    return true;        
            }
        }
        tempVisited[src] = false;
        
        return false;
    }


	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
        bool *visited =  new bool[V];
        bool *tempVisited = new bool[V];
        
        //set all to false
        for(int i=0;i<V;i++){
            visited[i] = false;
            tempVisited[i] = false;
        }

	   	// code here
           for(int i=0;i<V;i++){
               if(!visited[i]){
                   if(detectCycle(i,adj,visited,tempVisited))
                    return true;
               }
           }
        return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
