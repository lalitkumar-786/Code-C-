class Solution {
public:
    map<char,int> freq;
    
    void calFreq(string s){
        for(auto it:s)
            freq[it]++;
    }
    
    bool checkMaps(map<char,int> m1, map<char,int> m2){
        if(m1==m2)
            return true;
        else
            return false;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        calFreq(s1);
        
        int k=s1.length();
        int l=s2.length();
        int i=0 ,j=0, ans=0;
        map<char,int> tempFreq;
        
        while(j<l){
            if(freq.find(s2[j])!=freq.end())
                tempFreq[s2[j]]++;
            
            if(j-i+1==k){
                if(checkMaps(freq,tempFreq))
                    ans++;
                
                if(freq.find(s2[i])!=freq.end())
                    tempFreq[s2[i]]--;
                i++;
            }
            j++;
        }
        
        return (ans==0)?false:true;
    }
};
