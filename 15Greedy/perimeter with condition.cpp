
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