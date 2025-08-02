#include<iostream>
using namespace std;
#define ll long long int
#include<bits/stdc++.h>
vector<ll>v[200005];
ll cnt[200005];
void dfs(ll node,ll par)
{
    if(v[node].size()==1&& node!=1)
    {
        cnt[node]=1;
    }
    for(auto child:v[node])
    {
        if(child!=par)
        {
            dfs(child,node);
            cnt[node]+=cnt[child];
        }
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            v[i].clear();
            cnt[i]=0;
        }
        for(ll i=1;i<n;i++)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ll node=1,par=-1;
        dfs(node,par);
        ll q;
        cin>>q;
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            cout<<cnt[l]*cnt[r]<<endl;
        }
    }
}
