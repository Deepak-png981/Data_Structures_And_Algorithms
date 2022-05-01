// https://www.codechef.com/START36D/problems/BIRDFARM
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int test;
    cin>>test;
    while(test--){
        int chicken , duck , legs;
        cin>>chicken>>duck>>legs;
        if(legs % chicken == 0 and legs%duck == 0)
        cout<<"ANY"<<endl;
        else if(legs%chicken == 0)
            cout<<"CHICKEN"<<endl;
        else if(legs % duck == 0)
            cout<<"DUCK"<<endl;
        else    
            cout<<"NONE"<<endl;
    }
}
int main()
{
    solve();
    return 0;
}