/*There are N towns in a line, numbered from 0 to N - 1. Starting from town 0, we want to reach town N - 1. From town i, we can jump to any town j > i with an energy cost of (j-i)*A[i] + (j2 - i2)*A[i]2, where A[i] for all i are given in input.

Find the minimum total energy cost to reach town N - 1 from town 0.

Input

The first line contains a single integer, N.
The next line contains N space separated integers, ith integer denoting the value of A[i] , 0 ≤ i ≤ N - 1.
Output
Output the minimum cost to reach town N.

Constraints
1 ≤ N ≤ 105
-103 ≤ A[i] ≤ 103
Example 1

Input:
5
1 -1 2 2 2

Output:
14
Example 2

Input:
4
2 2 3 4

Output:
42*/
#include<bits/stdc++.h>
using namespace std;


int main(){
int n;
cin>>n;
long long arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}

long curr = 0;
long ans = 0;

while(curr<n-1){
    long next = curr+1;
    while(next < n-1){
        if(abs(arr[curr])>abs(arr[next]) || (abs(arr[curr])==abs(arr[next]) && arr[curr]>0 )){
            break;
            }
        else{
            next++;
            }
        }
    ans += (next-curr)*arr[curr] + (next*next - curr*curr)*arr[curr]*arr[curr];
    curr = next;
    }
cout<<ans;
return 0;
}