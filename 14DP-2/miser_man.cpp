/*Miser Man
Send Feedback
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
Explanation:
1 -> 4 -> 1 -> 3 -> 1: 10
This is marked and shown in the following image: 
Alt Text */



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  n,m;
    cin>>n>>m;
    int arr[n+1][m+1];
    int dp[n+1][m+1];
    memset(dp,0,sizeof dp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
//-------------------base case ---------------------
    for(int i=0;i<m;i++)
    {
        dp[0][i] = arr[0][i];
    }
// ----------------filling dp array ------------
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int o1=INT_MAX,o2=INT_MAX,o3=INT_MAX;
            if(j>0)
            {
                o1=arr[i][j]+dp[i-1][j-1];
            }        //int o1 =if(j>0)?arr[i][j]+dp[i-1][j-1]:INT_MAX;
            o2=arr[i][j]+dp[i-1][j];
            if(j<m-1)
            {
                  o3=arr[i][j]+dp[i-1][j+1];
            }
          
            dp[i][j] = min(o1,min(o2,o3));
        }
    }
// --------------------min in last row of dp will be ans--------------------
    int ans = INT_MAX;
    for(int i =0;i<m;i++)
    {
        ans = min(ans ,dp[n-1][i]);
    }
    cout<<ans<<endl;
    
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //        cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
