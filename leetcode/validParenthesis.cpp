class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        if(s.size()>=1 and (s[0]==')' || s[0]==']' || s[0]=='}'))
            return false;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else if(st.empty() and s[i]!=NULL)
                return false;
            else if((s[i]==')' and st.top()=='(') || (s[i]=='}' and st.top()=='{') ||(s[i]==']' and st.top()=='['))
                st.pop();
            else 
                return false;
        }
        return st.empty()?true:false;
    }
};
