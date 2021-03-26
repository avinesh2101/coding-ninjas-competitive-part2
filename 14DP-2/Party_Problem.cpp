#include <bits/stdc++.h>
using namespace std;

// void solve(vector<int>&efee,vector<int>&fun,int budget, int n)
void solve(int efee[],int fun[],int budget, int n)
{
    // int**dp =new int *[n+1];
    // for(int i=0;i<=n;i++)
    // {
    //     dp[i] = new int [budget+1];
    // }
    // memset(dp,0,sizeof*dp);
    int dp[n+1][budget+1];
for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=budget;j++)
            {
                dp[i][j]=0;
            }
        }
    // int  maxfun= INT_MIN;
    // int b=0;
    for(int i =1;i<=n;i++ )
    {
        for(int j =1;j<=budget;j++)
        {
          //maybe here
            if(efee[i]<=j)
            {
                dp[i][j] = max(fun[i]+dp[i-1][j-efee[i]],dp[i-1][j]);
            }
            else{
                  dp[i][j]=dp[i-1][j];
            }
            
           
        }
    }
int maxfun=dp[n][budget];
        int minmoney=0;
        for(int j=0;j<=budget;j++)
        {
            if(dp[n][j]==maxfun)
            {
                minmoney=j;
                break;
            }
        }
        cout<<minmoney<<" "<<maxfun<<endl;
}

int main()
{
    while(1)
    {
        int budget;
    int n;
    cin>>budget;
    cin>>n;
        if(budget==0&&n==0)
        {
            break;
        }
    int efee[101];
    int fun[101];
    for(int i = 1;i<=n;i++)	
    {
        cin>>efee[i];
        cin>>fun[i];
    }
    
    solve(efee,fun,budget,n);
        
    }
    
    
    return 0;
}