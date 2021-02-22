#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}



// function to find longest common subsequence
// ABCD
// ADFF
int lcs_recursive(int x, int y, string s1, string s2){
    
    // your code here
    //base case
    if(x==0 || y==0)
        return 0;
    if(s1[x-1]==s2[y-1]){
        return 1+lcs(x-1,y-1,s1,s2);
    }
    else
        return max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
}

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    //base case
    int dp[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
    }
    
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++)
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[x][y];
}
