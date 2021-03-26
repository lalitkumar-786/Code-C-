class Solution {
public:
    void magic(vector<vector<char>>& grid, int &count,int m,int n,int x,int y,bool **visited){
            
            visited[x][y]=true;
        
            if(x>=m or y>=n)
                return;
        
            if(x+1<=m-1){        
                if(!visited[x+1][y] and grid[x+1][y]=='1'){
                    magic(grid,count,m,n,x+1,y,visited);
                }    
            }
               
            if((x-1)>=0){
                if(!visited[x-1][y] and grid[x-1][y]=='1'){
                    magic(grid,count,m,n,x-1,y,visited);  
                }
            }
               
            if((y+1)<=(n-1)){
                if(!visited[x][y+1] and grid[x][y+1]=='1'){
                    magic(grid,count,m,n,x,y+1,visited);  
                }
            }
        
            if((y-1)>=0){
                if(!visited[x][y-1] and grid[x][y-1]=='1'){
                    magic(grid,count,m,n,x,y-1,visited);  
                }
            }
                
        }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        bool **visited=new bool*[m];
        for(int i=0;i<m;i++){
            visited[i]=new bool[n];
            for(int j=0;j<n;j++)
                visited[i][j]=false;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(!visited[i][j] and grid[i][j]=='1'){
                    magic(grid,count,m,n,i,j,visited);
                    count++;
                }           
        }
        
        return count;
    }
};



// NUmber of islands using DFS approach for GRID
class Solution {
public:
    bool isValid(int row,int col,int m,int n){
        if(row>=m || col>=n || row<0 || col<0)
            return false;
        return true;
    }
    
    void dfs(vector<vector<char>>& grid,int row,int col,int dx[],int dy[],int m,int n, bool** visited){
        
        for(int i=0;i<4;i++){
                if(isValid(row+dx[i],col+dy[i],m,n) and !visited[row+dx[i]][col+dy[i]] and grid[row][col]=='1'){
                    visited[row+dx[i]][col+dy[i]]=true;
                    dfs(grid,row+dx[i],col+dy[i],dx,dy,m,n,visited);
            }
        }
        return ;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        bool **visited=new bool*[m];
        for(int i=0;i<m;i++){
            visited[i]=new bool[n];
            for(int j=0;j<n;j++)
                visited[i][j]=false;
        }
        
        int dx[]={-1,0,1,0};//up, right, down , left
        int dy[]={0,1,0,-1};
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] and grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,dx,dy,m,n,visited);
                }
            }
        }
         return count;
    }
};
