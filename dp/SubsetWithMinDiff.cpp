
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int maxSubsetSum(int a[],int n,int sum){
	       
	       bool dp[n+1][sum+1];
	 
            for(int i=0;i<=n;i++){
                for(int j=0;j<=sum;j++){
                    if(j>=1 && i==0)
                        dp[i][j]=false;
                    if(j==0)
                        dp[i][j]=true;
                }
            }
            
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    if(a[i-1]<=j)
                        dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
	       
	       vector<int> v;
	       int result=INT_MAX;
	       for(int j=0;j<=sum;j++){
	           if(dp[n][j]){
	               v.push_back(j);
	           }           
	       }
	       
			for(int i=0;i<v.size();i++)
		   		result=min(abs(sum-2*v[i]),result);
	       return result;
	}
	
	int minDiffernce(int a[], int n) 
	{ 
	    // Your code goes here
	    long long int sum=0;
	    if(n==0)
	        return 0;  
	    for(int i=0;i<n;i++)
	        sum+=a[i];
	    
	    return maxSubsetSum(a,n,sum);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
