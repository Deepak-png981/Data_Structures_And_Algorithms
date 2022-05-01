#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int test;
    cin>>test;
    while(test--){
        int f , s;
        cin>>f>>s;
        // cout<<max( (f*100)/10 , (s*100)/20 )<<endl;
        if( (f*100)/10 > (s*100)/20)
            cout<<"FIRST"<<endl;
        else if( (f*100)/10 < (s*100)/20)
            cout<<"SECOND"<<endl;
        else
            cout<<"ANY"<<endl;
    }
}
int main()
{
    solve();
    return 0;
}