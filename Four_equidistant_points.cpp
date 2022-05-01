#include<iostream>
#define ll long long
using namespace std;
int main(){
    int tc = 0;
    int tt = 1;
    while(tc++ < tt){
        
    ll lele;
    cin>>lele;
    if(lele%2 == 1)
    {
        cout<<"-1"<<endl;
        continue;
    }
    	else{
            cout << 0 << " " << (lele/2) << endl;
            cout << (lele/2) << " " << 0 << endl;
            cout << 0 << " " << -(lele/2) << endl;
            cout << -(lele/2) << " " << 0 << endl;
        }

    }

    return 0;
}