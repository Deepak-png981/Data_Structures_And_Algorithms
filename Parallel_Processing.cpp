#include<iostream>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;
int main(){

    int testcase;
    cin>>testcase;
    while(testcase--){
        int size;
        cin>>size;
        vector<long long> ar, brr;
        ll sum = 0;
        for(int i = 0; i<size; i++){
            cin>>ar[i];
            // sum += ar[i];
            // brr[i] = sum;
        }
        for(int i = 0; i<size; i++){
            sum += ar[i];
            brr[i] = sum;
        }
        ll result = sum;
        for(int i = 0; i<size; i++){
            result = min(max(brr[i] , sum-brr[i]) , result);
        }
        cout<<result<<endl;
               

    }


    return 0;
}