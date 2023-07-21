APPROACH 1 : O(N2)
vector<int>ans;
for(int i = 0; i<nums.size(); i++){
for(int j = i+1 ; j<nums.size(); j++){
if(nums[i] + nums[j] == target){
ans.push_back(i);
ans.push_back(j);
}
}
}
return ans;
UNORDERED MAP APPROACH: O(N)
int n = nums.size();
vector<int>ans;
unordered_map<int , int>map;
for(int i = 0; i<n; i++){
int tofind = target - nums[i];
if(map.find(tofind) != map.end()){
ans.push_back(i);
ans.push_back(map[tofind]);
return ans;
}
else{
map[nums[i]] = i;
}
}
return ans;