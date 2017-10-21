#include<bits/stdc++.h>
using namespace std;
#define LL long long int
LL MSS(LL a[],LL n)
{
	LL sum=0,ans=INT_MIN;
	LL temp=a[0];
	for(int i=0;i<n;i++)//for all -ve values
	{
		if(a[i]>temp)
			temp=a[i];
	}
	if(temp<0)
		return temp;
	for(int i=0;i<n;i++)
	{
		if(a[i]+sum>0)
			sum+=a[i];
		else
			sum=0;
		//cout<<"i and sum "<<i<<" "<<sum<<endl;
		ans=max(ans,sum);
	}
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	LL t;
	cin>>t;
	while(t--)
	{
		LL n,non_c_sum=0;
		cin>>n;
		LL a[n+2];
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
				if(a[i]>0)
					non_c_sum+=a[i];
			}
			if(non_c_sum==0)
				cout<<MSS(a,n)<<" "<<MSS(a,n)<<endl;
			else
				cout<<MSS(a,n)<<" "<<non_c_sum<<endl;
			//(non_c_sum==0)?(cout<<MSS(a,n)<<" "<<MSS(a,n)<<endl;):(cout<<MSS(a,n)<<" "<<non_c_sum<<endl;);
	}
 	return 0;
}

