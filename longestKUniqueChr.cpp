// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int longestKSubstr(string s, int k) {
    // your code here

    unordered_map<char,int> freq;
    int count=freq.size();
    int i=0,j=0;
    int l= s.length();

    int ans=-1;
    while(j<l){
        freq[s[j]]++;

        if(freq.size()<k)
            j++;
        else if(freq.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }
        else{
            while(freq.size()>k){
                freq[s[i]]--;
                if(freq[s[i]]==0){
                    auto it=freq.find(s[i]);
                    freq.erase(it);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends
