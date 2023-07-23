//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    // Code here
	    string ans="";
       if(numerator==0){
           return "0";
       }
     
       long num=labs(numerator);
       long den=labs(denominator);
   long up=num/den;
   string temp=to_string(up);
   ans+=temp;
      
    long rem=num%den;
   if(rem==0){
       return ans;
   }
   ans+=".";
   unordered_map<long,int>mp;
  string tempans="";
  int i=0;
   while(rem){
       if(mp.find(rem)!=mp.end()){
         
          for(int k=0;k<mp[rem];k++){
              ans+=tempans[k];
          }
           ans+='(';
          for(int k=mp[rem];k<i;k++){
              ans+=tempans[k];
          }
          ans+=')';
          break;
       }
       else{
           mp[rem]=i;
           i++;
           rem=rem*10;
           long tempres=rem/den;
           rem=rem%den;
           tempans+=to_string(tempres);
              if(rem==0){
                  ans+=tempans;
              }
       }
   }
   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends