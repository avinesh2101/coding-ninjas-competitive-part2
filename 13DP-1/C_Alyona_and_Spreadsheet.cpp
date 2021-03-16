#include<iostream>
#include<climits>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int minval(int*a,int n)
{
    int m =INT_MAX;
    for(int i=0;i<n;i++)
    {
         m = min(a[i],m);
    }

    return m;
}

int main()
{
	int n,m;
	cin>>n>>m;
//----------basic requirements---
	int*row1 = new int [m]; //replace input  2d array
	int*row2 = new int [m];

	int*dp1 = new int [m];//replace dp 2d array
	int*dp2 = new int [m];

	int*res = new int [n];
// --------base case--------
    for(int i=0;i<m;i++)
    {
        cin>>row1[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>row2[i];
    }

    for(int i=0;i<m;i++)
    {
        dp1[i]=0;
    }

    for(int i=0;i<m;i++)
    {
        if(row2[i] >= row1[i])
        {
            dp2[i]=0;
        }
        else{
            dp2[i]=1;
        }
    }

    res[0] = minval(dp1,m);
    res[1] = minval(dp2,m);
//---------general sol -----
    for(int i=2;i<n;i++)
    {
    	  for(int j=0;j<m;j++)  //toggling
        {
            dp1[j]=dp2[j];

        }
        for(int j=0;j<m;j++)  //toggling
        {
            row1[j]=row2[j];
        }
        for(int j=0;j<m;j++)
        {
            cin>>row2[j];
        }
         
       
       
       //-------------------

       for(int j=0;j<m;j++)
       {
           if(row1[j] <= row2[j])
           { 
               dp2[j]=dp1[j];
           }
           else{
               dp2[j]=i;
           }
       }
        res[i]=minval(dp2,m);


    }
// ----------queries--------
	int k;
	cin>>k;
	while(k--)
	{
		int l,r;
		cin>>l>>r;
        if(res[r-1]<l)
        {
            cout<<"Yes"<<endl;
        }
      else{
        cout<<"No"<<endl;
        }

	}
	return 0;
}