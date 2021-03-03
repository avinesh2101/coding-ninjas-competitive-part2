#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int balancedBTs(int n) {
    
    
    
    if(n==0||n==1)
    {
        return 1;

    }
    
    long long x=balancedBTs(n-1);
    long long y=balancedBTs(n-2);
    
   // return   (x*x)+(2*x*y);
    
    //it will cross range of integer both 32 bit as well as 64 bit so we do
    int m=pow(10,9)+7;
    long long res1=x*x;
    long long res2=2*x*y;
    
    int ans1=(int)(res1%m);
    int ans2=(int)(res2%m);
    
    int ans=(ans1+ans2)%m;
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}