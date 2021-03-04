class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,top=0;
        int right=matrix[0].size()-1;
        int bottom=matrix.size()-1;
        vector<int> v;
       
        int dir=0;
        
        while(top<=bottom and left<=right){
            
            if(dir==0){
             for(int i=left;i<=right;i++)
                 v.push_back(matrix[top][i]);
             top++;
            }
            
            if(dir==1){
             for(int i=top;i<=bottom;i++)
                 v.push_back(matrix[i][right]);
             right--;
               
            }
            
            if(dir==2){
             for(int i=right;i>=left;i--)
                 v.push_back(matrix[bottom][i]);
             bottom--;    
            }
            
            if(dir==3){
             for(int i=bottom;i>=top;i--)
                 v.push_back(matrix[i][left]);
             left++;    
            }
            dir++;
            dir=dir%4;
            
        }
        return v;
    }
};
