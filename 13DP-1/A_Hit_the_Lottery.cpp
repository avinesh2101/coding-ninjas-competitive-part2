#include <bits/stdc++.h>

using namespace std;


priority_queue<int> bills;

int main()

{
    long long int mon,sol=0;
    cin>>mon;
    bills.push(100);bills.push(20);bills.push(10);bills.push(5);bills.push(1);

    while(mon){
        while(bills.top()<=mon){
            sol++;
            mon-=bills.top();
        }
        bills.pop();
    }

    cout<<sol<<"\n";
    return 0;

}