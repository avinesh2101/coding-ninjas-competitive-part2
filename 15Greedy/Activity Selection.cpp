Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4


#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >a;
    for(int i=0;i<n;i++)
    {
        int c,b;
        cin>>c>>b;
        a.push_back(make_pair(c,b));
    }
    
    
    sort(a.begin() ,a.end(), sortbysec);
    
//      for(int i=0;i<n;i++)
//     {
//         cout<<a[i].first<<a[i].second<<'\n';
//     }
    
    long ans=1;
    int prev=0;
    for(int i=1;i<n;i++)
    {
        if(a[i].first>=a[prev].second)
        {   ans++;
            prev=i;
        }
       
    }
    cout<<ans<<'\n';
    return 0;
}