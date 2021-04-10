/*Perimeter with conditions
Send Feedback
Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.
Input Format
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Constraints
1 =< N <= 10^5 
1 <= A[i] <= 10^9
Time Limit: 1 second
Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3 
Sample Input2:
3
2 2 4
Sample Output3:
-1 
Explaination
In the First Sample case, the elements that form a triangle with maximum perimeter is 1,3,3.
In the Second Sample case, the elements that can form a triangle are degenerate, so, we printed -1.*/
#include<bits/stdc++.h>
using namespace std;
bool isvalid(int a, int b, int c){
    return c+b>a;
}
 
int main()
{
	int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; ++i){
      cin>>v[i];
    }
    sort(v.begin(), v.end());

    for(int i = n-1; i>1; i--)`{
    if(isvalid(v[i], v[i-1], v[i-2])){
        cout<<v[i-2]<<" "<<v[i-1]<<" "<<v[i]<<endl;
        return 0;
      }
    }
   cout<<-1<<endl;

	return 0;
}
// In simple term,first sort the a, b, c in ascending order then check below condition

// a + b <= c