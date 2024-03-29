// Adjacent Bit Counts
// Send Feedback
// For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
// X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
// which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
// AdjBC(011101101) = 3
// AdjBC(111101101) = 4
// AdjBC(010101010) = 0
// Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
// 11100, 01110, 00111, 10111, 11101, 11011
// Input
// The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100.
// Output
// For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k. As answer can be very large print your answer modulo 10^9+7.
// Sample Input
// 10
// 1 5 2
// 2 20 8
// 3 30 17
// 4 40 24
// 5 50 37
// 6 60 52
// 7 70 59
// 8 80 73
// 9 90 84
// 10 100 90
// Sample Output
// 1 6
// 2 63426
// 3 1861225
// 4 168212501
// 5 44874764
// 6 160916
// 7 22937308
// 8 99167
// 9 15476
// 10 23076518



#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
int sol(int n ,int k,int start,int***dp)
{
// ----------base case----------------
    if(k<0){
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    if(n==1){
        if(k==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[n][k][start]!=-1){
        return dp[n][k][start];
    }

// -----------------solving recursively ------------
    if(start==1){
        dp[n][k][start]= (sol(n-1,k-1,1,dp)%m+sol(n-1,k,0,dp)%m)%m;
        return dp[n][k][start];
    }

    if(start ==0){
        dp[n][k][start]= (sol(n-1,k,1,dp)%m+sol(n-1,k,0,dp)%m)%m;
        return dp[n][k][start];
    }
}

int so(int n,int k,int***dp)
{
    return (sol(n,k,0,dp)%m+sol(n,k,1,dp)%m)%m;
}
int main()
{
    int p;
    cin>>p;
    for(int i=0;i<p;i++){

        int num;
        int size;
        int k;
        cin>>num>>size>>k;
        
//--------------3d array-------------------------------------
        int ***dp=new int**[size+1];
        for(int i=0;i<=size;i++){
            dp[i]=new int*[k+1];
            for(int j=0;j<=k;j++){
                dp[i][j]=new int[2];
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }
        }
// -------------------calling function for sol ---------------
        int ans = so(size,k,dp);
        cout<<num<<" "<<ans%m<<endl;

//------------------deleting 3d array -----------------------
        for(int i=0;i<=size;i++){
            for(int j=0;j<=k;j++){
                delete []dp[i][j];
            }
            delete []dp[i];
        }
        delete []dp;
    }
    return 0;
}
