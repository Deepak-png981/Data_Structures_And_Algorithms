// https://www.codechef.com/START36D/problems/PRESENTS

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll test;
    cin>>test;
    while(test--)
    {
        ll paisa;
        cin>>paisa;
        if(paisa == 4)
        cout<<paisa<<endl;
        else
        cout<<paisa - paisa/5 ;
    }
}
int main()
{
    solve();
    return 0;
}