// using basic DFS which will give TLE as it has overlapping subproblems
class Solution {
public:
    void dfs(int m,int n,int src, int des, int &paths,bool **visited){
        if(src>=m || des>=n)
            return;
        if(src==m-1 and des==n-1){
            paths+=1;
            return;
        }
        
        if(!visited[src][des]){
            visited[src][des]=true;
            dfs(m,n,src+1,des,paths,visited);
            dfs(m,n,src,des+1,paths,visited);
        }
        visited[src][des]=false;
        return;
    }
    int uniquePaths(int m, int n) {
        bool **visited=new bool*[m];
        
        for(int i=0;i<m;i++){
            visited[i]=new bool[n];
            for(int j=0;j<n;j++)
                visited[i][j]=false;
        }
            
        int paths=0;
        dfs(m,n,0,0,paths,visited);
        return paths;
    }
};

// Bottom up DP
class Solution {
public:
    void dfs(int m,int n,long long **dp){
          
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                    if(i==0 or j==0)
                        dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return;
    }
    
    int uniquePaths(int m, int n) {
      
        long long **dp=new long long*[m+1];
        
        for(int i=0;i<=m;i++){
            dp[i]=new long long[n+1];
            for(int j=0;j<=n;j++){
                    dp[i][j]=0;
            }
        }
        
        dfs(m,n,dp);
        return dp[m-1][n-1];
    }
};
