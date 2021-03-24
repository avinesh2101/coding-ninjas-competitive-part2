// ---------------------------------------------approach one using normal recursion with memoiation with 2d array------------
// ---------------------------------------------it failed im  2 testcases ----------------------
// int helper(int* weight, int* value, int n, int maxWeight,int**dp)
// {
//     if(n==0 || maxWeight==0)
//     {
//         return 0;
//     }
    
//     if(dp[n][maxWeight] > -1)
//     {
//         return dp[n][maxWeight];
//     }
    
//     int ans;
    
//     if(weight[0]>maxWeight)
//     {
//         ans =  helper(weight , value,n-1,maxWeight,dp);
        
//     }
//     else{
//         ans =max(value[0]+ helper(weight+1 , value+1,n-1,maxWeight-weight[0],dp),  helper(weight+1 , value+1,n-1,maxWeight,dp));
//         }
    
//     dp[n][maxWeight] = ans ;
    
//     return ans;
    
// }


// int knapsack(int* weight, int* value, int n, int maxWeight) {
// 	// Write your code here
//     int**dp = new int*[n+1];
//     for(int i =0;i<=n;i++)
//     {
//         dp[i] = new int [maxWeight+1];
//         for(int j=0;j<=maxWeight;j++)
//         {
//             dp[i][j]=-1;
//         }
//     }
    
//     // memset(dp ,-1,sizeof(dp));
    
//     int ans = helper(weight , value,n,maxWeight,dp);
        
//         for(int i=0;i<n;i++)
//         {
//             delete [] dp[i];
//         }
//         delete [] dp ;
        
//     return ans;
    
    
    
// }

/* -------------------approach two a little more
 better with iterations and using just 
2 1d arrays instead of one big 2d array  to save space  ------------*/

int knapsack(int* weight, int* value, int n, int maxWeight) {
    
    
}


// -----------------doubts
// how to use memset or something like that for intialization 2d array
