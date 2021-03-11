class Solution {
public:
    void genbrackets(int oBrackets,int cBrackets,string s,vector<string> &res){
        if(oBrackets==0 and cBrackets==0){
            res.push_back(s);
            return;
        }
        
        if(oBrackets!=0 || oBrackets==cBrackets){
            string s1=s;
            s1.push_back('(');
            genbrackets(oBrackets-1,cBrackets,s1,res);
        }
        else{
            if(oBrackets==0){
                string s1=s;
                s1.push_back(')');
                genbrackets(oBrackets,cBrackets-1,s1,res);
            }
            else{
                string s1=s;
                string s2=s;
                s1.push_back('(');
                genbrackets(oBrackets-1,cBrackets,s1,res);
                
                s2.push_back(')');
                genbrackets(oBrackets,cBrackets-1,s2,res);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0)
            return res;
        string s="";
        genbrackets(n,n,s,res);
        return res;
    }
};
