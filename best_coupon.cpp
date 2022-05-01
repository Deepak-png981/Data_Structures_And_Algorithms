#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int test;
    cin>>test;
    while(test--){
        int amount;
        cin>>amount;
        cout<<max(100 , (amount * 10) / 100) <<endl;
    }
}
int main()
{
    solve();
    return 0;
}