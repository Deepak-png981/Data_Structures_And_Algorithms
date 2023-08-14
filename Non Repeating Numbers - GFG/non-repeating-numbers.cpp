//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
     int setbit(int num ,int pos){
            return ((num&(1<<pos))!=0);
        }
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans; 
        int xorsum =0;
        for(int i=0;i<nums.size();i++){
            xorsum ^= nums[i];
        }
        int temp = xorsum;
        int pos = 0;
        int n =0;
        while(n!=1){
            if(xorsum&1){
                n =1;
            }
            xorsum = xorsum>>1;
            pos++;
        }
        
        int temp1 = 0;
        for(int i =0;i<nums.size();i++){
            if(setbit(nums[i],pos-1)){
                temp1 ^= nums[i];
            }
        }
        int second = temp1^temp;
        if(second>temp1){
            ans.push_back(temp1);
            ans.push_back(second);
        }
        else{
            ans.push_back(second);
            ans.push_back(temp1);
        }
        return ans; 
        
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends