//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int countZero = 0 , countOne = 0 , countTwo = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0){
                countZero++;
            }
            else if(a[i] == 1){
                countOne++;
            }else{
                countTwo++;
            }
        }
        int i = 0;
        while(countZero--){
            a[i++] = 0;
        }
        while(countOne--){
            a[i++] = 1;
        }
        while(countTwo--){
            a[i++] = 2;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends