// #include<iostream>
// #include<unordered_map>
// #include<string.h>
// #include<vector>
// #include <sstream>
// #define ll long long
// using namespace std;
// void printSubsequence(string input, string output)
// {
//     // Base Case
//     // if the input is empty print the output string
//     if (input.empty()) {
//         // cout << output << endl;
//         return;
//     }
 
//     // output is passed with including
//     // the Ist character of
//     // Input string
//     printSubsequence(input.substr(1), output + input[0]);
 
//     // output is passed without
//     // including the Ist character
//     // of Input string
//     printSubsequence(input.substr(1), output);
// }
// bool ansfunc(string n){
//     string output = "";
//     printSubsequence(n , output);
//     for(int i = 0; i<output.length(); i++){
//         int num1 = (int)output[i];
//         for(int j = i+1; j<output.length(); j++){
//             int num2 = (int)output[j];
//             if((num1 + num2)%2 == 0){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// // bool ansfunc(ll n){
// //     ll sum = 0;
// //     vector<int> lele;
// //     ll remainde = 0 , reverse = 0;
// //     int count = 0;
// //     while(n != 0){
// //         count++;
// //         remainde = n%10;
// //         reverse = reverse*10 + remainde;
// //         n /= 10;
// //         lele.push_back(reverse);
// //         if((n+reverse)%2 == 0){
// //             return true;
// //         }
// //         else{
// //             for(int i = 0; i<lele.size(); i++)
// //             {   if(count == 1)
// //                 break;
// //                 if((lele[i] + remainde) % 2 == 0)
// //                 return true;
// //             }
// //         }
// //     }
// //     return false;
// // }
// void solve(){
//     string n;
//     cin>>n;
//     bool ans = ansfunc(n);
//     if(ans){
//         cout<<"YES"<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }
// }
// int main()
// {
//     int lele;
//     cin>>lele;
//     while(lele--)
//     {
//     solve();
//     }
//     return 0;
// }



//test

#include<bits/stdc++.h>
using namespace std;

void ansDhundh() {
  int i=0, j, n;
  string LELE;
  cin>>LELE;
  int cn1=0, cn2=0;
  while(LELE[i])
  { 
    if((LELE[i]-'0')%2==0) cn1++;
    else cn2++;
    i++;
  }

  
  if(((LELE[LELE.size()-1])-'0')&1)
  {
      if(cn2>=2)
     cout << "YES\n";
      else cout << "NO\n";
  }
  else{
    if(cn1>=2)
    cout << "YES\n";
    else
    cout << "NO\n";
  }
}

int32_t main() {
    int LELE;
    cin >> LELE;
    while(LELE--) {
      ansDhundh();
    }

    return 0;
}