#include<bits/stdc++.h>
using namespace std;
int main() {

	int s,n;
    cin>>s>>n;
    int ans[n];
    for(int i=0;i<n;i++)
    { ans[i]=0;}
    ans[0]=1;
    s=s-1;
    int d=n-1;

    while(d>=0)
    {
        
         if(d==0)
        {
            ans[d] +=s;
         }
        if(s>9){
        	ans[d]=9;
            s=s-9;
        }
        else if(s<=9)
        {
            ans[d]+=s; 
            s=0;
        }    
        d--;
    }
    
    
    
    
for (int i = 0; i < n; i++)
	{
		cout << ans[i];
	}
    return 0;
}

// #include<iostream>
// using namespace std;
// void lottery(int s, int n)
// {
// 	int* arr = new int[n];
// 	for (int i = 0; i < n; i++)
// 	{
// 		arr[i] = 0;
// 	}
// 	int sum = s;
// 	arr[0] = 1;
// 	sum -= 1;
// 	int i = n - 1;
// 	while (i >= 0)
// 	{
// 		if (i == 0)
// 		{
// 			arr[i] += sum;
// 		}
// 		if (sum > 9)
// 		{
// 			arr[i] = 9;
// 			sum -= 9;
// 		}
// 		else if (sum <= 9)
// 		{
// 			arr[i] += sum;
// 			sum = 0;
// 		}
// 		i--;
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << arr[i];
// 	}
// }
// int main()
// {
// 	int s, d;
// 	cin >> s >> d;
// 	lottery(s, d);
// }