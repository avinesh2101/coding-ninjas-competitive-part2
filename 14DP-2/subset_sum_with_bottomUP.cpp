/* Time Complexity: O(N * M) 
Space Complexity: O(N * M)
 where N in the size of the input array and M is the given sum */ 
 bool isSubsetPresent(int *arr, int n, int sum)
  { 
      //dp[i][j] is true if we can create arr subset sum of j from first i elements
       bool **dp = new bool *[n + 1]; 
       //If sum is 0, then answer is true 
       for (int i = 0; i <= n; i++)
        { dp[i] = new bool[sum + 1];
         dp[i][0] = true; 
         } 
//If sum is not 0 and set is empty, then answer is false
 for (int i = 1; i <= sum; i++) 
 { 
     dp[0][i] = false;
     
 } 
 //Fill the table in bottom up manner 
 for (int i = 1; i <= n; i++) 
 {
      for (int j = 1; j <= sum; j++) 
      {
           if (j < arr[i - 1]) 
           { 
               dp[i][j] = dp[i - 1][j];
                } 
                else {
                     dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]; 
                     } 
        } 
} 
bool result = dp[n][sum];
 for (int i = 0; i <= n; i++) 
 {
      delete[] dp[i];
 } 
 delete[] dp; 
 return result; 
 
 }