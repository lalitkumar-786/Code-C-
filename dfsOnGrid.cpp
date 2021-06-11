#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int dx[8]={0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8]={1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int x, int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return false;

        return true;
    }

    void dfs(int x,int y,vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m,int &ans){
        visited[x][y] = true;
        ans++;
        //cout<<"ANS at x:y "<<x<<" "<<y<<"---> "<<ans<<endl;
        for(int i=0;i<8;i++){
            if(isValid(x+dx[i],y+dy[i],n,m) and grid[x+dx[i]][y+dy[i]]==1 and !visited[x+dx[i]][y+dy[i]])
                dfs(x+dx[i],y+dy[i],grid,visited,n,m,ans);
        }
    }

    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
        int n,m;
        int res=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=0;
                if(!visited[i][j] and grid[i][j]==1){
                    dfs(i,j,grid,visited,n,m,ans);
                   // cout<<ans<<endl;
                    res=max(res,ans);
                }
            }
        }
        return res;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
} 
