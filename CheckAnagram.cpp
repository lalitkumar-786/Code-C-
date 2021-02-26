class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mymap;
        int l1=s.length();
        int l2=t.length();
        if(l1!=l2)
            return false;
        
        for(int i=0;i<l1;i++){
            mymap[s[i]]++;
            mymap[t[i]]--;
        }
        
        for(auto i:mymap){
            if(i.second!=0)
                return false;
        }
        return true;
    }
};
