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
        //whereever sorting doesnt matter, use unordered_map
        unordered_map<char,int> freq;
        int ans=0;
        while(j<l){
            
            freq[s[j]]++;
            if(freq.size()<j-i+1){
                while(freq.size()<j-i+1){
                    freq[s[i]]--;  
                    if(freq[s[i]]==0){
                        //unlike vectors, in map, erase can take position like this
                        freq.erase(s[i]);
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
