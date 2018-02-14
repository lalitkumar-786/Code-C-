/* The closer you see , the less you observe */

#include<bits/stdc++.h>
using namespace std;
#define boost std::ios::sync_with_stdio(false);
#define LL long long int
#define MOD 1000000007
#define MIN INT_MIN
#define MAX INT_MAX
#define mp make_pair
LL gcd(LL a,LL b)
{
	if(a==0)
	    return b;
	return gcd(b%a,a);
}
int count_pair(map<int,int> mymap,int sum)
{
	int c=0,val,a,b;
	map<int,int>::iterator it;
	for(it=mymap.begin();it!=mymap.end();it++)
	{
		a=it->first;
		mymap[a]=1;
		b=sum-a;
		if(b>0)
		{
			if(mymap[b]==1)
			{
				cout<<"Pair is "<<a<<" "<<b<<endl;
				c++;
			}
		}
	}
	return c;
}
int main()
{
	boost;
	int t,n,x,sum;
	map<int,int> mymap;
	cout<<"Enter total elements : "<<endl;
	cin>>n;
	cout<<"Enter elements "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		mymap[x]=0;
	}
	cout<<"Enter the value of sum : "<<endl;
	cin>>sum;
	cout<<count_pair(mymap,sum)<<endl;
	return 0;
}

