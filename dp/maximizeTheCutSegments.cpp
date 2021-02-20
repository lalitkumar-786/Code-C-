nclude<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    // if(n<=0 || x>n || y>n || z>n)
    //     return 0;
    // if(x<=0 and y<=0 and z<=0)
    //     return 0;
    // if(x<=n and x>0)
    //     return max(1+maximizeTheCuts(n-x,x,y,z),maximizeTheCuts(n,0,y,z));
    // if(y<=n and y>0)
    //     return max(1+maximizeTheCuts(n-y,x,y,z),maximizeTheCuts(n,x,0,z));
    // if(z<=n and z>0)
    //     return max(1+maximizeTheCuts(n-z,x,y,z),maximizeTheCuts(n,x,y,0));
    
    if(n==0)
        return 0;
    int dp[n+1]={0};
    
    for(int i=1;i<=n;i++)
        dp[i]=INT_MIN;
    
    for(int i=1;i<=n;i++){
        if(x<=i and x>0)
            dp[i]=max(1+dp[i-x],dp[i]);
        if(y<=i and y>0)
            dp[i]=max(1+dp[i-y],dp[i]);
        if(z<=i and z>0)
            dp[i]=max(1+dp[i-z],dp[i]);
    }
    if(dp[n]<0)
        dp[n]=0;
    return dp[n];
}

