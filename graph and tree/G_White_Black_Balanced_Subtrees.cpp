#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define yes   cout<<"YES"<<endl
#define no   cout<<"NO"<<endl
#define all(a) (a).begin(),(a).end()

#define mid(l,r) ((r+l)/2)
#define mx_int_prime 999999937

const double PI = acos(-1);

#define mem(a,b) memset(a, b, sizeof(a) )
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a)/__gcd(a,b))*b

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


// ceil value x = (n+(m-1))/m
int white[4005],black[4005];
vector<int>v[4005];
char arr[4005];
 
void dfs(int u)
{
    if(arr[u]=='B')
    {
        black[u]=1;
    }
    else if(arr[u]=='W')
    {
        white[u]=1;
    }
    for(int i:v[u])
    {
        dfs(i);
        black[u]+=black[i];
        white[u]+=white[i];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
        }
 
        for(int i=2;i<=n;i++)
        {
            int x;
            cin>>x;
            v[x].push_back(i);
        }
 
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int root =1;
        dfs(root);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(black[i]==white[i])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1; i<=n; i++){
            v[i].clear();
            black[i] = white[i] = 0;
        }
    }
 
}