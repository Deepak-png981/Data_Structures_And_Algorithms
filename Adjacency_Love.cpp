// #include <iostream>
// #include <unordered_map>
// #include <string.h>
// #include<vector>
// using namespace std;
// #define ll long long
// void solve()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     ll sum = 0;
//     int count = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         if (arr[i] % 2 == 0)
//         {
//             count++;
//         }
//         int x = arr[i] + arr[i + 1];
//         sum += x;
//     }
//     //   if(count == n)
//     //   cout<<"-1";

//     if (sum % 2 == 1)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
//     else
//     {
//         vector<int>odd , even;
//         int evenCount = 0, oddCount = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] % 2 == 0)
//                 even[evenCount++] = arr[i];
//             else
//                 odd[oddCount++] = arr[i];
//         }
//         //check
//         if (odd.size() == n && (n & 1))
//         {
//             cout << -1 << endl;
//         }
//         else if (odd.size() == 1 && even.size() > 0)
//         {
//             cout << -1 << endl;
//         }
//         else if (odd.size() == 1 && even.size() == 0)
//         {
//             cout << odd[0] << endl;
//         }
//         //checkout
//         for (int i = 0; i < oddCount; i++)
//         {
//             cout << odd[i] << " ";
//         }
//         for (int i = 0; i < evenCount; i++)
//         {
//             cout << even[i] << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int test;
//     cin >> test;
//     while (test--)
//     {
//         /* code */
//         solve();
//     }

//     return 0;
// }

// int main(){
//     int test;
//     cin>>test;
//     while(test--){

  
//    ll lele;
//    cin>>lele;
//    vector<ll>odd;
//    vector<ll>even;
//    for(ll i=0;i<lele;i++){
//     ll y;
//     cin>>y;
//     if(y&1){
//                 odd.push_back(y);
//     }
//     else{
//                 even.push_back(y);
//     }

//    }
//    if(odd.size()==lele && (lele&1)){
//                      cout<<-1<<endl;
//          }
//     else if(odd.size()==1 && even.size()>0){
//                       cout<<-1<<endl;
//                      }
//    else if(odd.size()==1 && even.size()==0){
//                         cout<<odd[0]<<endl;
//                      }

//    else if(odd.size()>=2){
//          if (odd.size()&1){

//                          cout<<odd[0]<<" ";

//              for(ll i=1;i<odd.size();i++){
//                          cout<<odd[i]<<" ";
//              }
//              for(ll i=0;i<even.size();i++){
//                          cout<<even[i]<<" ";
//              }
//              cout<<endl;
//                      }
//               else {
//              for(ll i=0;i<odd.size();i++){
//                          cout<<odd[i]<<" ";
//              }
//              for(ll i=0;i<even.size();i++){
//                          cout<<even[i]<<" ";
//              }
//              cout<<endl;
//                      }

//    }
//      else{
//                cout<<-1<<endl;
//    }
// }
// return 0 ;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int test;
    cin>>test;
    while(test--){
        ll lele;
        cin>>lele;
        vector<ll>odd;
        vector<ll>even;
        for(ll i=0;i<lele;i++){
            ll y;
            cin>>y;
            if(y&1){
                odd.push_back(y);
            }
            else{
                even.push_back(y);
            }           
               
        }
        if(odd.size()==lele && (lele&1)){
            cout<<-1<<endl;
        }
        else if(odd.size()==1 && even.size()>0){
            cout<<-1<<endl;           
        }
        else if(odd.size()==1 && even.size()==0){
            cout<<odd[0]<<endl;       
        }                 
        else if(odd.size()>=2){
            if (odd.size()&1){
                cout<<odd[0]<<" ";
                for(ll i=0;i<even.size();i++){
                    cout<<even[i]<<" ";
                } 
                for(ll i=1;i<odd.size();i++){
                    cout<<odd[i]<<" ";
                }
                cout<<endl;
            }
            else {
                for(ll i=0;i<even.size();i++){
                    cout<<even[i]<<" ";
                } 
                for(ll i=0;i<odd.size();i++){
                    cout<<odd[i]<<" ";
                }
                cout<<endl;
            }     
                 
        }
        else{
            cout<<-1<<endl;
        }
    }
 return 0;
}