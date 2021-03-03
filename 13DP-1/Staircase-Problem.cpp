#include<iostream>
#include<vector>
// int f(vector<int> &v){
//     return 0;
// }

long staircase(int n)
{
    
//     long *a=new long [n+4];
//     fill(a,a+n,0);
//     memset(a,0,sizeof(a));
//     vector<int> v(n , 0);
    
//     a[0]=1;
//     a[1]=1;
//     a[2]=2;
    
//     int l=1,m=2,np=3;
//     for(int i=3;i<n,l<n,m<n,np<n;i++)
//     {
//         a[i]=a[l]+a[m]+a[np];
//         l++;m++;np++;
//     }

//     long output=a[n];
    
//     delete [] a;
//     return output;
    
    vector<long long> dp(n+5,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int  i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i -2] + dp[i - 3];
    }
    
    return dp[n];
    
    
}

// --------------------------------recursive----------------------------------------------

// long solver(long*a,int n)
// {
//     if(n==0 || n==1)
//     {
//         return 1;
//     }
//     if(n==2)
//     {
//         return 2;
//     }
    
//     if(a[n]>0)
//     {
//         return a[n];
//     }
//         long output = solver(a,n-1)+solver(a,n-2)+solver(a,n-3);
    
//     a[n]=output;
    
//     return output;
// }


// long staircase(int n)
// {
//     long a[10000];
// //     how do i intialize whole array/vector with zero
//     for(int i=0;i<n;i++)
//     {
//         a[i]=0;
//     }
//     long output=solver(a,n);
    
//     return output;
    
    
// }