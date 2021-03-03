#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n ,k,l;
    
    cin>>n>>k>>l;
    
    int a[n];
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==a[i-1]){
            count++;}
        
        }
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1]){
            count++;}
        
        }
    
    
    if(count==n-1)
    {
        cout<<"0"<<endl;
    }
    else
    {
       
        int min1=INT_MAX;
        int max2=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int a2=a[i];
            min1=min(a2,min1);
            max2=max(a2,max2);
        }
        
        int dec=0,inc=0;int cost=0;
        
        int min_cost=INT_MAX;
        for(int i=min1;i<=max2;i++)//pivot
        {  dec=0;inc=0;cost=0;
            for(int j=0;j<n;j++)
            {
                if(a[j]<i)//increse
                {
                    inc+=i-a[j];
                }
                else//decreasing
                {
                    dec+=a[j]-i;
                    
                }
                
            }
           if(inc>=dec)  
     {cost=(dec*k)+((inc-dec)*l);
      if(cost<=min_cost)
      {min_cost=cost;}
     }      
        }
        
        cout<<min_cost<<endl;
        
        
        
    }
    
    
    
    
}
