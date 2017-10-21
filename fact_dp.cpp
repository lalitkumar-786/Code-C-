#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define M 1000000007
/*LL fact(LL n)
    {
        if(n==0)
            return 1;
        else
        {
            if (cache[n]!=-1)
                return cache[n];
            else
                return (cache[n]=n*fact(n-1));
        }
    }
    */
int main()
{
    int t;
    cin>>t;
    std::ios::sync_with_stdio(false);
    LL cache[100005];
    cache[0]=cache[1]=1;
    for(int i=2;i<=100000;i++)
    {
    	cache[i]=(i*(cache[i-1]))%M;
	}
	while(t--)
    {
        LL n;
        cin>>n;
        cout<<cache[n]<<endl;
    }
    return 0;
}

