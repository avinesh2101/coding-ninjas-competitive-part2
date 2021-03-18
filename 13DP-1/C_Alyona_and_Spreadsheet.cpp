#include <bits/stdc++.h> 
#define mod 1000000007
#define inf 1000000000000LL
#define root2 1.41421
#define root3 1.73205 
#define pi 3.14159
#define MAX 100001 
#define cntbit __builtin_popcountll 
#define ll long long int 
#define PII pair<int, int> 
#define f first 
#define s second 
#define mk make_pair 
#define PLL pair<ll, ll> 
#define gc getchar 
#define pb push_back 
using namespace std; 
vector<vector<int> > A, B;
int n, m;
int main()
{
    cin>>n>>m;
    vector<int> dp(n);
    int i, j;
    for(i=0;i<n;i++)
    {
        vector<int>v(m), v2(m, 0);
        for(j=0;j<m;j++)cin>>v[j];
        A.pb(v); 
        B.pb(v2); 
        
    } 
    for(i=0;i<m;i++)
    { 
        B[0][i]=0; 
        for(j=1;j<n;j++) 
        {
            if(A[j][i]>=A[j-1][i])
            B[j][i]=B[j-1][i]; 
            else B[j][i]=j;
            }
    }
    for(i=0;i<n;i++) 
    {
        dp[i]=i;
        for(j=0;j<m;j++)
        dp[i]=min(dp[i], B[i][j]); 
        //cout<<i<<" "<<dp[i]<<endl;
    } 
    int q, l, r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        l--;
        r--; 
        if(dp[r]<=l) 
        cout<<"Yes\n";
        else cout<<"No\n";
    }
}