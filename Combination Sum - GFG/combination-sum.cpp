//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void generate(vector<int>& candidates,int ind, int target, vector<int>& ans, vector<vector<int>>& comb){
        if(ind==candidates.size()){
            if(target==0){
                
                comb.push_back(ans);
            }
            return;
        }
            
        if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            generate(candidates, ind, target-candidates[ind], ans, comb);
            ans.pop_back();
        }

        generate(candidates, ind+1, target, ans, comb);
            
    }

    vector<int> removeRepeated(vector<int>& a){
        int n = a.size();
        vector<int> unq;
        unordered_map<int, int> m;
    
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        for(auto j: m){
            unq.push_back(j.first);
        }
        return unq;
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> comb;
        vector<int> ans;
        
        sort(candidates.begin(), candidates.end());
        candidates = removeRepeated(candidates);
        sort(candidates.begin(), candidates.end());
        
        generate(candidates, 0, target, ans, comb);
        return comb;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends