#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int test;
    cin>>test;
    while(test--){
        int d , t;
        cin>>d>>t;
        cout<<min(3*d , 2*t)<<endl;
    }
}
int main()
{
    solve();
    return 0;
}