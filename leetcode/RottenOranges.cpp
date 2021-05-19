class Solution {
public:
    
   
    queue<pair<int,int>> q;
    int fresh=0;
    
    void getAllRotten(vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();
       //    cout<<n<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        return;
    }

    bool isValid(int x,int y, int n, int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        if(n==1 and m==1){
            if(grid[0][0]==1)
                return -1;
            else if(grid[0][0]==0)
                return 0;
        }
        getAllRotten(grid);
       // display();
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};

            
        bool **visited = new bool*[n];
        for(int i=0;i<n;i++){
            visited[i]= new bool[m];
            for(int j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
        
        int time=0;
        int totalRotten = q.size();
        
        if(q.size()==0 and fresh==0)
            return 0;
        else if(q.size()==0 and fresh!=0)
            return -1;
            
        
        visited[q.front().first][q.front().second] = true;
        int flag=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();
            totalRotten--;
            for(int i=0;i<4;i++){
    
                if(isValid(x+dx[i],y+dy[i],n,m) and !visited[x+dx[i]][y+dy[i]] and grid[x+dx[i]][y+dy[i]]==1){
                    visited[x+dx[i]][y+dy[i]] = true;
                    q.push({x+dx[i],y+dy[i]});
                    flag=1;
                    fresh--;
                }
            }

            if(totalRotten==0){
                if(flag==1) time++;
                flag=0;
                totalRotten=q.size();
            }

        }
        return (fresh==0)?time:-1;
    }
};
