//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// currentWeight = 50 , remainig = 0
// finalValue = 160 + (120/30)*20
class Solution
{
    private:
    static bool cmp(Item a , Item b){
        double prizePerKg1 = (double)a.value / (double)a.weight;
        double prizePerKg2 = (double)b.value / (double)b.weight;
        return prizePerKg1 > prizePerKg2;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr , arr + n , cmp);
        int currentWeight = 0;
        double finalValue = 0.0;
        for(int i = 0; i<n; i++){
            if(currentWeight + arr[i].weight <= W){
                currentWeight += arr[i].weight;
                finalValue += arr[i].value;
            }else{
                int remaining = W - currentWeight;
                finalValue += ((double)arr[i].value / (double)arr[i].weight)*remaining;
                break;
            }
        }
        return finalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends