// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long calSum(int tree[], int n, int target){
        long sum=0;
        
        for(int i=0;i<n;i++){
            if(tree[i]- target>=0){
                sum=sum+(tree[i]- target);
            }
        }
        return sum;
    }
    
    int find_height(int tree[], int n, int k)
    {
        int start=INT_MAX,end=INT_MIN;
        
        if(n==1 and k<=tree[0])
            return tree[0]-k;
        for(int i=0;i<n;i++){
            if(tree[i]<start)
                start=tree[i];
            
            if(tree[i]>end)
                end=tree[i];
        }
        
        while(start<=end){
            int mid=start + (end-start)/2;
            
            if(calSum(tree,n,mid) == k){
                return mid;
            }
            else if(calSum(tree,n,mid) >k){
                start=mid+1;
            }
            else{
                 end=mid-1;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends
