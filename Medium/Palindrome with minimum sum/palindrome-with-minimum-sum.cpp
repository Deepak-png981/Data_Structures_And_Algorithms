//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool check(string & s)
  {
      int i=0,j=s.size()-1;
      
      int f=0;
      
      while(i<j)
      {
          if(s[i]==s[j])
          {
              i++;
              j--;
          }
          else if(s[i]=='?' && s[j]!='?')
          {
              i++;
              j--;
          }
          else if(s[i]!='?' && s[j]=='?')
          {
              i++;
              j--;
          }
          else
          {
              f=1;
              break;
          }
          
      }
      
      
      
      return f==1?false:true;
      
  }
  
    int minimumSum(string s) {
        
        
        bool p=check(s);
        
        
        int x1=0;
        
         int cnt=0;
        
        if(p==false)
        {
            x1=1;
        }
        else
        {
            

           // Now if the string is palindrome we will put the value of the same character at the other end except the '?'


            string s1="";
            
            int i=0,j=s.size()-1;
            
            while(i<j)
            {
                if(s[i]!='?' && s[j]!='?')
                {
                    i++;
                    j--;
                    
                }
                else if(s[i]!='?' && s[j]=='?')
                {
                    
                    char c1=s[i];
                    s[j]=c1;
                    
                    i++;
                    j--;
                }
                else if(s[i]=='?' && s[j]!='?')
                {
                    
                    char c2=s[j];
                    s[i]=c2;
                    i++;
                    j--;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            
            
            // Now we will make a string of all the elements except the '?'
            
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='?')
                {
                    s1+=s[i];
                }
            }
            
           // After that we will find the sum of the difference of the  adjacent charcter  
           
            if(s1.size()==0)
            {
                cnt=0;
            }
            else
            {
                   
             for(int i=0;i<s1.size()-1;i++)
             {
              cnt+=abs(s1[i+1]-s1[i]);
                
             }
             
             
            }
             
             
            
    

        }

        return x1==1?-1:cnt;        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends