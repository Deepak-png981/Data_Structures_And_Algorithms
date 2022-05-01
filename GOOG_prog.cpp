#include<iostream>
#include<algorithm>
#define lamba long long
using namespace std;
int main(){

        lamba test;
        cin>>test;
        while(test--){
            float lele;
            cin>>lele;
            float ans = lele/4;
            if(int(ans) == ans)
            cout<<"GOOD"<<endl;
            else
            cout<<"NOT GOOD"<<endl;
        }


    return 0;
}