First Approach of using a third array :
vector<int>ans;
for(int i = 0; i<m; i++){
ans.push_back(nums1[i]);
}
for(int i = 0; i<n; i++){
ans.push_back(nums2[i]);
}
sort(ans.begin() , ans.end());
for(int i = 0; i<m+n; i++){
nums1[i] = ans[i];
}