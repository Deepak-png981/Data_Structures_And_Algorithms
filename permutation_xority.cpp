#include<iostream>
using namespace std;
void deepakbhaisolvekrenge(){
    int lele;
    cin>>lele;
    int arr[lele];
    if(lele == 2){
        cout<<-1<<endl;
        return ;
    }
    if(lele%2 == 1){
        int x = lele;
        for(int i =0 ;i<lele; i++){
            cout<<x<<" ";
            x--;
        }
        cout<<endl;
        return;
    }
    int x = 1;
    for(int i = 0; i<lele;i++){
        arr[i] = x;
        x++;
    }
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 1;
    for(int i = 0; i<lele; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}

int main(){
     int test;
     cin>>test;
     
     while(test--){
         deepakbhaisolvekrenge();
     }

    return 0;
}