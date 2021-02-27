class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mymap;
        int l=s.length();
        if(l==1)
            return 1;
        
        for(int i=0;i<l;i++){
            mymap[s[i]]++;
        }
        int res=0,flag=0;
        for(auto i:mymap){
            if(i.second%2==0)
                res+=i.second;
            else{
                flag=1;
                int temp=i.second/2;
                res+=2*temp;
            }
        }
        return (flag==1)?(res+1):res;
    }
};
