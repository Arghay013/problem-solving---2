#include<bits/stdc++.h>
using namespace std;
#define ll long long int

 vector<ll>v[200005];
  ll vis[200005];
  vector<ll>cnt(200005);
  ll ans=0;
  ll n,m;
  void dfs(ll node)
  {
      if(v[node].size()==1&&node!=1)
      {
          ans++;
      }
     vis[node]=1;
      for(auto it:v[node])
      {
          if(vis[it]==0)
          {

              if(cnt[it])
              {
                  cnt[it]+=cnt[node];
                  if(cnt[it]<=m)
                  {
                      dfs(it);
                  }
              }
              else
              {
                  dfs(it);
              }
          }
      }
  }
  int main()
  {

      cin>>n>>m;
      cnt.resize(n+1);
      for(ll i=1;i<=n;i++)
      {
          cin>>cnt[i];
          v[i].clear();
      }
      n--;
      while(n--)
      {
          ll x,y;
          cin>>x>>y;
          v[x].push_back(y);
           v[y].push_back(x);
      }
      dfs(1);
      cout<<ans<<endl;

  }
 