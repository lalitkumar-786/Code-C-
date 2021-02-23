
#include<bits/stdc++.h>
using namespace std;

// Function to return Next larger elements
// 8 0
//   -1

vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    vector<long long> res;
    stack<long long> s;
    if(n==0){
        return res;
    }
    for(int i=n-1;i>=0;i--){
        if(s.empty())
            res.push_back(-1);
        else if(!s.empty() and arr[i]<s.top())
            res.push_back(s.top());
        else {
            while(!s.empty() and s.top()<=arr[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(res.begin(),res.end());
    return res;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
