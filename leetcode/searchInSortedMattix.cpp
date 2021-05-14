class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        
        while(i<matrix.size() and j>=0){
            if(target>matrix[i][j])
                i++;
            else if(target<matrix[i][j])
                j--;
            else
                return true;
        }
        return false;
        
    }
};
