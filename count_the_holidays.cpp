#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int a[] = {6 , 7 , 13 ,14 , 20 ,21 , 27, 28};
    int count = 8;
    unordered_map<int , int> map;
    for(int i = 0; i < 9; i++){
        map[a[i]] = 1;
    }
    for(int i = 0; i<n; i++){
        if(map.count(arr[i]) == 1){
            count  = count;
        }
        else{
            count += 1;
        }
    }
    cout<<count<<endl;
    }
    return 0;

    
}