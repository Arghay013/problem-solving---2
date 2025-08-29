#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                c++;
            }
        }
        if(c==k)
        {
            cout<<0<<endl;
            continue;
        }
        if(c>k)
        {
            int a=c,j=-1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='B')
                {
                    a--;
                    if(a==k)
                    {
                       j=i+1;
                       break;
                    }
                }
            }
            cout<<1<<endl;
            cout<<j<<" "<<"A"<<endl;
        }
        else
        {
            int b=c,x=-1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='A')
                {
                    b++;
                    if(b==k)
                    {
                       x=i+1;
                       break;
                    }
                }
            }
            cout<<1<<endl;
            cout<<x<<" "<<"B"<<endl;
        }
    }
}