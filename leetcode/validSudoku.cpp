class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char data){
        for(int i=0;i<row;i++){
            if(board[i][col]==data)
                return false;
        }
        for(int j=0;j<col;j++){
            if(board[row][j]==data)
                return false;
        }
        int i=3*(row/3);
        int j=3*(col/3);
        
        for(int tempRow=i;tempRow<=i+2;tempRow++){
            for(int tempCol=j;tempCol<=j+2;tempCol++){
                if(board[tempRow][tempCol]==data and (tempRow!=row and tempCol!=col))
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int row,col;
        row=col=0;
        
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.')
                    continue;
                else{
                    if(!isValid(board,row,col,board[row][col]))
                        return false;
                }
            }
        }
        return true;
    }
};
