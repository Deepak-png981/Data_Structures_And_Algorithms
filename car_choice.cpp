#include<iostream>
#define ll long long
using namespace std;
int main(){
   ll testcase;
   cin>>testcase;
   while(testcase--){
    float x1 , x2 , y1 , y2;
    cin>>x1>>x2>>y1>>y2;
    float sum1 = y1/x1;
    float sum2 = y2/x2;
    if(sum1 == sum2){
        cout<<0<<endl;
    }
    else if(sum1>sum2){
        cout<<1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
   }


    return 0;
}