//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    private:
    static bool cmp(Job a , Job b){
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr , arr + n , cmp);
        int maxiDead = INT_MIN;
        for(int i = 0; i<n; i++){
            maxiDead = max(maxiDead , arr[i].dead);
        }
        int deadArray[maxiDead + 1];
        for(int i = 0; i<= maxiDead; i++)
            deadArray[i] = -1;
        int countJobs = 0 , jobProfit = 0;
        for(int i = 0; i<n; i++){
            for(int j = arr[i].dead; j>0; j--){
                if(deadArray[j] == -1){
                    countJobs += 1;
                    jobProfit += arr[i].profit;
                    deadArray[j] = arr[i].id;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(countJobs);
        ans.push_back(jobProfit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends