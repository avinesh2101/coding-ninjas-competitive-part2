#include <iostream>
#include <cstring>
using namespace std;

int edHelper(string s1,string s2,int m,int n,int**dp)
{
    if(m==0 || n==0)
    {
        // if(m==0)
        // {return n; }
        // else if(n==0)
        // {return m;}
        // else {
        //     return 0;
        // }

        return 0;
    }
    
    if(dp[m][n]>-1)
    {
        return dp[m][n];
    }
    int ans =0;
    
    if(s1[0] == s2[0])
    {
       ans = 1 + edHelper(s1.substr(1) ,s2.substr(1),m-1,n-1, dp);
    }
    else{
        ans = min(1+edHelper(s1.substr(1),s2,m-1,n,dp) ,      //delete
                  min(1+edHelper(s1,s2.substr(1),m,n-1,dp) ,   //insert
                      1+edHelper(s1.substr(1),s2.substr(1),m-1,n-1,dp) ));  // substitute
    }
    
    dp[m][n] = ans;
    return ans;
}

int editDistance(string s1, string s2)
{ 
    int m = s1.size();
    int n = s2.size();
    int ** dp =new int *[m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int [n+1];
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans =  edHelper(s1,s2,m,n,dp);
    
    for(int i=0;i<=m;i++)
    {
        delete [] dp[i];
    }
    
    delete [] dp ;
    
    return ans;
}
 
int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}