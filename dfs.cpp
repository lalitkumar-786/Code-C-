#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[100001];
int heightof[100001];
void dfs(int at,int height)
{
    vector<int>::iterator it;
    heightof[at]=height;
    it=adj[at].begin();
    while(it!=adj[at].end())
    {
    //	cout<<"hi"<<endl;
        dfs((*it),height+1);
        it++;
    }
    return;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i,root,par;
        scanf(" %d",&n);
        i=1;
        while(i<=n)
        {
            adj[i].clear();
            i++;
        }
        i=1;
        while(i<=n)
        {
            scanf(" %d",&par);
            if(par==0)
            {
                root=i;
            }
            else
            {
                adj[par].push_back(i);
            }
            i++;
        }
        dfs(root,0);
        i=1;
        long long sumofheights=0,total=(long long)n*(n-1);
        total/=2;
        while(i<=n)
        {
            sumofheights+=(long long)heightof[i];
            i++;
        }
       printf("%lld %lld\n",sumofheights,total-sumofheights);
    }
    return 0;
}
