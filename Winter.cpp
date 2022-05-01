#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,n) for(int i = 0; i<n; i++)
void ansDede() {
    ll int i, j, n, m, k;
    //TODO
    cin >> n >> m >>k; 
    vector<int>       phla(n+1,0);      //vis(n+1,0);
    vector<int>      dusra[n+1];                     //adj[n+1]; 
    for(int i = 0;i<m;i++) {
        int u, v; 
        cin >> u >> v;
        dusra[u].push_back(v); 
        dusra[v].push_back(u); 
    }
    vector<pair<int,int>> hero;
    fo(i,k){
      int t1,t2;
      cin>>t1>>t2;
      hero.push_back(make_pair(t1,t2));
    }
    // for(auto v : adj){
    //   for(int& ele : v) cout<<ele<<" ";
    //   cout<<endl;
    // }
    // for(auto pairs : query) cout<<pairs.first<<" "<<pairs.second<<endl;
    for(auto p : hero){
      int type = p.first;
      int u = p.second;
      if(type==1){
        phla[u] = 1;
      }
      else if(type==2){
          queue<int> q;
          fo(i,n+1){
            if(phla[i]==1) q.push(i);
          }
            int time  = u;
            while(time > 0){
              while(q.size() > 0){
                int cur = q.front();
                q.pop();
                // cout<<cur<<"-->Adj :"<<endl;
                for(auto it : dusra[cur]) {
                  if(!phla[it]) {
                      // cout<<it<<" ";
                      // q.push(it); 
                      phla[it] = 1; 
                  }
                }
                // cout<<"New vis: ";
                // printA(vis,n+1);
                // cout<<endl;
              }
              time--;
          }
        }      
      else{
        if(phla[u]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      }
    }
  }
int main(){
    int test;
    cin>>test;
    while (test--)
    {
        ansDede();
    }
    return 0;
}