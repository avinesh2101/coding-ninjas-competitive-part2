#include<iostream>
#include<string>
// #include<bits/stdc++.h>
using namespace std;

int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
        int  n;
        cin>>n;
        string a,b;

        cin>>a>>b;

        int count={0};

        for(int i=0;i<n;)
     {
        if(a[i]!=b[i])
        {
            if(  i+1<n && a[i]!=a[i+1] &&a [i+1]!=b[1+i])
            {
                i+=2;
            }
            else{
                i++;
            }
            count++;
        }else{
            i++;
        }
        
      }cout<<count<<endl;

    // }
}