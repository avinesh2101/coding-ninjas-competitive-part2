#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // N, H and x.
    int n,h,x;
    cin>>n>>h>>x;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m= *max_element (a,a+n);
    

    if(h<=x)
    {
        cout<<"yEs"<<endl;

    }
    else if(x + m>=h)
    {
        cout<<"yEs"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}