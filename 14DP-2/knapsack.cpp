// ------------------------------approach one using normal recursion with memoiation with 2d array------------
int helper(int* weight, int* value, int n, int maxWeight,int**dp)
{
    if(n==0 || maxWeight==0)
    {
        return 0;
    }
    
    if(dp[n][maxWeight] > -1)
    {
        return dp[n][maxWeight];
    }
    
    int ans;
    
    if(weight[0]>maxWeight)
    {
        ans =  helper(weight +1, value+1,n-1,maxWeight,dp);
        
    }
    else{
        ans =max(value[0]+ helper(weight+1 , value+1,n-1,maxWeight-weight[0],dp),  helper(weight+1 , value+1,n-1,maxWeight,dp));
        }
    
    dp[n][maxWeight] = ans ;
    
    return ans;
    
}


int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int**dp = new int*[n+1];
    for(int i =0;i<=n;i++)
    {
        dp[i] = new int [maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    // memset(dp ,-1,sizeof(dp));
    
    int ans = helper(weight , value,n,maxWeight,dp);
        
        for(int i=0;i<n;i++)
        {
            delete [] dp[i];
        }
        delete [] dp ;
        
    return ans;
    
    
    
}



/* -------------------approach two a little more
 better with iterations and using just 
2 1d arrays instead of one big 2d array  to save space  ------------*/

// int solver (int* weight, int* value, int n, int maxWeight)
// {
    
//     int ** dp =new int *[n+1];
    
//     for (int i=0;i<=n;i++)
//     {
//         dp[i] = new int [maxWeight+1];
//     }
    
//     for(int i =0 ;i<=maxWeight;i++)
//     {
//         dp[0][i] = 0;
//     }
//      for(int i =0 ;i<=n;i++)
//     {
//         dp[i][0] = 0;
//     }  
    
//     for(int i=1;i<=n;i++){
//         for(int w=0;w<=maxWeight;w++)
//         {
//             dp[i][w] = dp[i-1][w];
//             if(weight[i-1]<=w)
//             {
            
//                 dp[i][w] = max(value[i-1]+dp[i-1][w-weight[i-1]] ,dp[i][w]);
//             }
            
//         }
//     }
    
//     return dp[n][maxWeight];
// }
// int knapsack(int* weight, int* value, int n, int maxWeight) {

    
//     int ans = solver(weight,value,n,maxWeight);
    
//     return ans;
    
// }




// -------------------------------better with iterations and using just 
//2 1d arrays instead of one big 2d array  to save space  ------------
int knapsack(int* w, int* v, int n, int max_weight)
{
	int* zero = new int[max_weight + 1];
	int* one = new int[max_weight + 1];
	for (int i = 0; i < max_weight + 1; i++)
	{
		zero[i] = 0;
		one[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (j - w[i - 1] >= 0)
			{
				one[j] = max(zero[j], v[i - 1] + zero[j - w[i - 1]]);
			}
			else
			{
				one[j] = zero[j];
			}
		}

		for (int j = 0; j <= max_weight; j++)
		{
			zero[j] = one[j];
			one[j] = 0;
		}
	}
	return zero[max_weight];
}