#include<bits/stdc++.h>
using namespace std;
long long tree[4*100005];
long long a[100005];
void build(long long  node, long long start, long long end)
{
    if(start == end)
	{
		if(a[start]%2==0)
        tree[node] = a[start];
        else
        	tree[node]=-1;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        if(tree[2*node]%2==0 && tree[2*node+1]%2==0)
        	tree[node] = max(tree[2*node],tree[2*node+1]);
        else if(tree[2*node]%2==0 && tree[2*node+1]%2!=0)
        	tree[node]=tree[2*node];
        else if(tree[2*node]%2!=0 && tree[2*node+1]%2==0)
        	tree[node]=tree[2*node+1];
		else
			tree[node]=-1;        
    }
}
void update(long long  node, long long start, long long end, long long idx, long long val)
{
    if(start == end)
    {
    	if((val%2)==0)
    	{
    	a[idx]= val;
        tree[node] = val;	
		}
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}
long long query(long long node, long long start, long long end, long long l, long long r)
{
    if(r < start || end < l)
    {
        return -1;
    }
    if(l <= start && end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}
int main()
{
	long long t,i,j,temp=0,x=0;
	long long n,l,r,q,ans;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	while(q--)
	{
		cin>>t;
		if(t==1)
			{
				cin>>i>>x;
				update(1,1,n,i,x);
			}
		else
		{
			if(t==2)
				{
					cin>>l>>r;
						ans=query(1,1,n,l,r);
						if(ans==-1)
							cout<<"DNE"<<endl;
						else
				cout<<ans<<endl;
				}
		}
	}
	return 0;
}
