/*You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250*/
#include<bits/stdc++.h>
using namespace std;
struct s {
  		
    int start;
    int finish;
    int profit;
};

bool custom ( s a , s b)
{
    return a.finish<b.finish ;
}

int binarySearch(s a[] ,int i)
{
    int low =0,high = i-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(a[mid].finish<=a[i].start)
        {
            if(a[mid+1].finish<=a[i].start)
                low=mid+1;
            else
                return mid;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}
int magic(struct s a[] , int n){
//     -------------dp----------
    	// int*dp = new int[n+1];
    	// dp[0] = a[0].profit;
    int	dp[n+1];
    dp[0] = a[0].profit;
    for(int i=1;i<n;i++)
    {
    /*  int Nconflict = 0;
        for(int j = i-1;j>=0;j--)
        {
            if(a[j].finish<=a[i].start)
            {
                Nconflict = dp[j];
                break;
            }
        }   */
        //------------using binary search for optimizing o(n^2) to O(nlogn)
       int Nconflict = 0;
        int j = binarySearch(a,i);
        if(j!= -1)
        {
            Nconflict= dp[j];
        }
        int option1 = a[i].profit + Nconflict;//include;
        int option2 = dp[i-1];               //exclude;
         dp[i] = max(option1,option2);
	}
    int ans = dp[n-1];
    // delete [] dp ;
    return ans;
}
    	
int main()
{
    
    int n;
    cin>>n;
    s a[n+1];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i].start>>a[i].finish>>a[i].profit;
    }
//     -----------greedy-------
    sort(a , a+n,custom);
//     --------------dp------
    int ans = magic(a,n);
    cout<<ans<<'\n';
    return 0;
}