#include<bits/stdc++.h>
using namespace std;
long long treev[4*100005];
long long treeo[4*100005];
long long a[100005];
void builde(long long  node, long long start, long long end)
{
    if(start == end)
	{
		if(a[start]%2==0)
        treev[node] = a[start];
        else
        	treev[node]=-1;
    }
    else
    {
        int mid = (start + end) / 2;
        builde(2*node, start, mid);
        builde(2*node+1, mid+1, end);
        if(treev[2*node]%2==0 && treev[2*node+1]%2==0)
        	treev[node] = max(treev[2*node],treev[2*node+1]);
        else if(treev[2*node]%2==0 && treev[2*node+1]%2!=0)
        	treev[node]=treev[2*node];
        else if(treev[2*node]%2!=0 && treev[2*node+1]%2==0)
        	treev[node]=treev[2*node+1];
		else
			treev[node]=-1;        
    }
}
void buildo(long long node, long long start, long long end)
{
    if(start == end)
	{
		if(a[start]%2!=0)
        	treeo[node] = a[start];
        else
        	treeo[node]=-1;
    }
    else
    {
        int mid = (start + end) / 2;
        buildo(2*node, start, mid);
        buildo(2*node+1, mid+1, end);
        if(treeo[2*node]%2!=0 && treeo[2*node+1]%2!=0)
        	treeo[node] = max(treeo[2*node],treeo[2*node+1]);
        else if(treeo[2*node]%2!=0 && treeo[2*node+1]%2==0)
        	treeo[node]=treeo[2*node];
        else if(treeo[2*node]%2==0 && treeo[2*node+1]%2!=0)
        	treeo[node]=treeo[2*node+1];
		else
			treeo[node]=-1;        
    }
}
void updatee(long long  node, long long start, long long end, long long idx, long long val)
{
    if(start == end)
    {
    	if((val%2)==0)
    	{
    	a[idx]= val;
        treev[node] = val;	
		}
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            updatee(2*node, start, mid, idx, val);
        else
            updatee(2*node+1, mid+1, end, idx, val);
        treev[node] = max(treev[2*node],treev[2*node+1]);
    }
}
void updateo(long long  node, long long start, long long end, long long idx, long long val)
{
    if(start == end)
    {
    	if((val%2)!=0)
    	{
     	a[idx] = val;
        treeo[node] = val;		
		}
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            updateo(2*node, start, mid, idx, val);
        else
            updateo(2*node+1, mid+1, end, idx, val);
        treeo[node] = max(treeo[2*node],treeo[2*node+1]);
    }
}
long long queryo(long long node, long long start, long long end, long long l, long long r)
{
    if(r < start || end < l)
    {
        return -1;
    }
    if(l <= start && end <= r)
    {
        return treeo[node];
    }
    int mid = (start + end) / 2;
    int p1 = queryo(2*node, start, mid, l, r);
    int p2 = queryo(2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}
long long querye(long long node, long long start, long long end, long long l, long long r)
{
    if(r < start || end < l)
    {
        return -1;
    }
    if(l <= start && end <= r)
    {
        return treev[node];
    }
    int mid = (start + end) / 2;
    int p1 = querye(2*node, start, mid, l, r);
    int p2 = querye(2*node+1, mid+1, end, l, r);
    return max(p1,p2);
}
int main()
{
	long long t,i,j,temp=0,x=0;
	long long n,l,r,q,ans;
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	builde(1,1,n);
	buildo(1,1,n);
	while(q--)
	{
		cin>>t;
		if(t==1)
			{
				cin>>i>>x;
				updateo(1,1,n,i,x);
				updatee(1,1,n,i,x);
			}
		else
		{
			if(t==2)
				{
					cin>>l>>r;
						ans=querye(1,1,n,l,r);
						if(ans==-1)
							cout<<"DNE"<<endl;
						else
				cout<<ans<<endl;
				}
			else
				{
					cin>>l>>r;
					ans=queryo(1,1,n,l,r);
					if(ans==-1)
						cout<<"DNE"<<endl;
					else
						cout<<ans<<endl;
				}
		}
	}
	return 0;
}
