int solver(int*d,int n,int v,int**a)
{
    if(v==0)
    {
        return 1;
    }
    if(v<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 0;
    }
    if(a[v][n]>-1)
    {
        return a[v][n];
    }
    int first = solver(d,n,v-d[0],a);
    int sec = solver(d+1,n-1,v,a);
    a[v][n]=first+sec;
    return first+sec;
    
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	// int a[value+1][numDenominations+1]={-1};
     //int **arr = (int **)malloc(value+1 * sizeof(int *)); 
         int **arr =new int* [value+1];
    for (int i=0; i<value+1; i++) 
         //arr[i] = (int *)malloc(numDenominations+1 * sizeof(int)); 
    arr[i]=new int[numDenominations+1];
        
    for (int i = 0; i <value+1; ++i) {   // for each row
  for (int j = 0; j < numDenominations+1; ++j) { // for each column
   arr[i][j] = -1;
  }
}
    return solver( denominations,  numDenominations, value,arr);
    
}