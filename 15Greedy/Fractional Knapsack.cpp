Fractional Knapsack
Send Feedback
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
Input Format:
The first line of input contains two space separated integers, that denote the value of N and W.
Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec

#include<bits/stdc++.h>
using namespace std;

struct s{
    int weight;
    int value;
    
};

bool custom(struct s a,struct s b)//while checking it we only send 1 element no
{

    double x = ((double)a.value / a.weight );
    double y = ((double)b.value / b.weight );
    
    return x>y;
    
}

double fknapsack(struct s arr [] ,int n, int w)
{
     double currW =0.0;
     double fvalue= 0.0;
        
    for(int i =0;i<n;i++)
    {
        if(currW+arr[i].weight<=w)
        {
            fvalue +=arr[i].value ;
            currW += arr[i].weight;
            
        }
        else
        {
            int remainW = w-currW;
            fvalue += arr[i].value*((double)remainW / (double)arr[i].weight);
              break;
            
        }
    }
    
    return fvalue;
}

int main(){
  int n,w;
    cin>>n>>w;
    
    s arr[n+1];//array of struc
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value>>arr[i].weight;
    }
    
    sort(arr , arr+n ,custom );
    
    // double ans = fknapsack(arr,n,w);
    cout<<fixed<<setprecision(6)<<fknapsack(arr,n,w);
    return 0;
}