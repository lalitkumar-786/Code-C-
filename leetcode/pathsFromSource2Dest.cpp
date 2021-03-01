class Solution {
public:
    
    void dfs(vector<vector<int>>& graph,bool visited[],int source, vector<vector<int>> &res,vector<int> &v,int n){
        
        visited[source]=true;
        v.push_back(source);
        if(source==n-1){
             res.push_back(v);
        }       
        for(auto it=graph[source].begin();it!=graph[source].end();it++){
            if(!visited[*it]){
                dfs(graph,visited,*it,res,v,n);
            }    
        }
       visited[source]=false;
       v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> v;
        int n=graph.size();
        bool visited[16]={false};
        dfs(graph,visited,0,res,v,n);
        return res; 
    }
};
