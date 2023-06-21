//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &arr) {
        int countFive = 0 ,countTen = 0 , countTwenty = 0;
        for(int i = 0; i<N; i++){
            // 20
            if(arr[i] > 5){
                int val = arr[i] - 5; // 20 - 5 = 15
                while(val > 0){
                    if(val >= 20 and countTwenty > 0){
                        countTwenty--;
                        val = val - 20;
                    }else if(val >= 10 and countTen > 0){
                        countTen--;
                        val = val - 10;// 15 - 10 = 5
                    }else if(val >= 5 and countFive > 0){
                        countFive--;
                        val = val - 5; // 5 - 5 = 0
                    }
                    else 
                        return false;
                }
            }
            if(arr[i] == 5)
                countFive++; //1
            else if(arr[i] == 10)
                countTen++; //0
            else if(arr[i] == 20)
                countTwenty++; // 1
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends