#include <bits/stdc++.h>
using namespace std;

struct city{
    double x,y,f;
    
};

int main()
{
    int n;
    cin>>n;
    vector< city >c(3005);
    double dp[3005];
    
    for(int i=1;i<n+1;i++)
    {
        cin>>c[i].x>>c[i].y>>c[i].f;
    }
    
   
    for(int i=1;i<3005;i++)
    {
        dp[i] = INT_MIN;
    }
     dp[1]=c[1].f;//base case 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {                                       //              x1-x2                   y1-y2
            dp[i] = max( dp[i] , dp[j]+c[i].f - (sqrt( pow( c[i].x-c[j].x,2 ) + pow(c[i].y-c[j].y , 2) ) ) );// max(dp[i],dp[j]+happines at i - distance from jth city )
        }
    }
  
    printf("%.6f",dp[n]);
    return 0;
}
