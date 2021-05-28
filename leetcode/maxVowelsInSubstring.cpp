class Solution {
public:
    int countVowel(char chr){
        int count=0; 
        if(chr=='a' || chr=='e' || chr=='i'|| chr=='o' || chr=='u')
                count++;
       
        return count;
    }
    
    int maxVowels(string s, int k) {
        int l=s.length();
        
        if(l==1 and k==1 and countVowel(s[0])==1)
            return 1;
        else if(l==1 and k>1 and countVowel(s[0])==0)
            return 0;
        
        int i=0,j=0;
        int ans=0;
        int totalVowels=0;
        
        while(j<l){
            
            totalVowels+=countVowel(s[j]);
            if(j-i+1==k){
                ans=max(ans,totalVowels);
                totalVowels-=countVowel(s[i]);
                i++;
                j++;
            }
            else 
                j++;
        }
        
        return ans;
    }
};
