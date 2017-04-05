#include<bits/stdc++.h>
using namespace std;
	int grundy[1000];
int calculateMex(set<int> Set)
{
    int Mex = 0;
    while (Set.find(Mex) != Set.end())
        Mex++;
 	 return (Mex);
}
int calculateGrundy(int n)
{
	  if (n == 0)
        return 0;
	if(grundy[n]!=-1)
		return grundy[n];
    set<int> Set;
    if(n-2>=0)
            Set.insert(calculateGrundy(n-2));
    if(n-3>=0)
		    Set.insert(calculateGrundy(n-3));
    if(n-5>=0)        
			Set.insert(calculateGrundy(n-5));
    grundy[n]=(calculateMex(Set));
    return grundy[n];
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
    	int ans=0;
    	cin>>n;
    	memset(grundy,-1,sizeof(grundy));
    	ans=calculateGrundy(n);
		(ans==0)?cout<<"Second":cout<<"First";
		cout<<endl;
	}
    return (0);
}
