#include<bits/stdc++.h>
using namespace std;
int tree[4*1000000];

int a[100000+1];
void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        a[start]= val;
        tree[node]= val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node],tree[2*node+1]);
      //  printf("tree[%d] is %d\n",node,tree[node]);
    }
}
int query(int node, int start, int end, int l, int r)
{
    if((r < start ) || (end<l))
    {
    //	printf("returnded/....\n");
        // range represented by a node is completely outside the given range
        return 100000000;
    }
    else if(l <= start && end <= r)
    {
    	//printf("yes");
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
     return (min(p1,p2));
}
int main()
{
	int n,i,j,q,l,r;
	char c;
	int ans;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	build(1,0,n-1);
	while(q--)
	{
		cin>>c>>l>>r;
		if(c=='u')
		update(1,0,n-1,l-1,r);
		else
		{
				ans=query(1,0,n-1,l-1,r-1);	
				cout<<ans<<endl;
		}	
	}	
}
