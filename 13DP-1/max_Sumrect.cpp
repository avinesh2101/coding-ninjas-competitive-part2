/* Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find 
maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of 
columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29 */

#include <bits/stdc++.h>
using namespace std;
// n^3 with fixing l and r and using kadanes 
int kadane(int* arr, int* start, int* finish, int n)  //n is array size
{  
    // initialize sum, maxSum and  
    int sum = 0, maxSum = INT_MIN, i;  
  
    // for all negative values case  
    *finish = -1;  
  
    // local iterator if sum < 0, start is local_start  
    int local_start = 0;  
  
    for (i = 0; i <n; i++)  
    {  
        sum += arr[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  
  
    // if atleast one non -ve number  
    if (*finish != -1)  
        return maxSum;  
  
    // Special Case: When all numbers 
    // in arr[] are negative  
    maxSum = arr[0];  
    *start = *finish = 0;  //maximum sum = 0
  
    // Find maximum element in array  
    for (i = 1; i < n; i++)  
    {  
        if (arr[i] > maxSum)  
        {  
            maxSum = arr[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
}


int findMaxsum(int**M,int row,int col)
{
    
   // Variables to store the final output  
    int maxSum = INT_MIN;
    int finalLeft, finalRight, finalTop, finalBottom; 
    //dimensions 
    
    int left, right, i;  //left will iterate till col
    int temp[row], sum, start, finish;  
    // temp[row] is auxiliary space
    
   
    // Set the left column  
    for (left = 0; left < col; left++)  
    {  
        // Initialize all elements of temp as 0  
        fill(temp,temp+row,0);
   // memset(temp, 0, sizeof(temp));  
        
        
        // Set the right column for the left 
        // column set by outer loop  
        for (right = left; right < col; right++)  
        {  
              
            // Calculate sum between current left and right for 
            // every row, i  
            for (i = 0; i < row; i++)  
                temp[i] += M[i][right];  
  
            // Find the maximum sum subarray in temp[].  
            // The kadane() function also sets values   
            // of start and finish. So sum is sum of  
            // rectangle between (start, left) and  
            // (finish, right) which is the maximum sum  
            // with boundary columns strictly as left  
            // and right.  
            
            //call kadane() and store in sum
            sum = kadane(temp, &start, &finish, row);  
  
            // Compare sum with maximum sum so far.  
            // If sum is more, then update maxSum and  
            // other output values to fix rectangle dimensions
            if (sum > maxSum)  
            {  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }  
        }  
    }  
 
 return maxSum;
    
    


}


int main()
{
    int row,col;
    cin>>row>>col;
    
    int**matrix = new int* [row];
    
    for(int i=0;i<row;i++)
    {
        matrix[i]= new int [col];
        for(int j=0;j<col;j++)
        {

            cin>>matrix[i][j];
        }
    }
//--------------------------solution----------------
    
  cout<<findMaxsum(matrix,row,col);
    
    
    
//   ---------------------derefferencing---------------------  
    for(int i=0;i<row;i++)
    {
        delete [] matrix[i];  
    
    }
    
    delete [] matrix;
    return 0;
}
