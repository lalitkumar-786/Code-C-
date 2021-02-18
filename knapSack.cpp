// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack_Recursive(int W, int wt[], int val[], int n) 
{ 
   // Your code here
    if(W==0 || n==0)
        return 0;
    else{
        if(wt[n-1]<=W)
            return max((val[n-1]+knapSack_Recursive(W-wt[n-1],wt,val,n-1)),knapSack_Recursive(W,wt,val,n-1));
        else
            return knapSack_Recursive(W,wt,val,n-1); 
    }
}


// Using  Top -down approach
int knapSack_topDown(int W, int wt[], int val[], int n, int** dp){
    if(W==0 || n==0)
        return 0;
    else{
        if(dp[n][W]!=-1)
            return dp[n][W];
        else{
        if(wt[n-1]<=W)
            return dp[n][W]=max((val[n-1]+knapSack_topDown(W-wt[n-1],wt,val,n-1,dp)),knapSack_topDown(W,wt,val,n-1,dp));
        else
            return dp[n][W]=knapSack_topDown(W,wt,val,n-1,dp); 
        }
    }
}

int knapSack_bottomUp(int W, int wt[], int val[], int n, int** dp){

        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j)
                    dp[i][j]=max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][W];
}

int knapSack(int W, int wt[], int val[], int n){
    
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[W+1];
    }
   
    for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    return knapSack_bottomUp(W,wt,val,n,dp);
}

// Using  Bottom -up approach (fastest )





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
