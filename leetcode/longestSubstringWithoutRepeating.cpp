class Solution {
public:
    /*
    s = "pwwkew"
    Output: 3 wke
    */
    int lengthOfLongestSubstring(string s) {
        int i,j;
        i=j=0;
        
        int l=s.length();
        if(l<=1)
            return l;
        
        map<char,int> freq;
        int ans=0;
        while(j<l){
            
            freq[s[j]]++;
            if(freq.size()<j-i+1){
                while(freq.size()<j-i+1){
                    freq[s[i]]--;  
                    if(freq[s[i]]==0){
                        auto it=freq.find(s[i]);
                        freq.erase(it);
                    }
                    i++;
                }
                j++;
            }
            else if(freq.size()==j-i+1){
                ans=(freq.size()>ans)?freq.size():ans;
                j++;
            }
        }
        return ans;
    }
};
