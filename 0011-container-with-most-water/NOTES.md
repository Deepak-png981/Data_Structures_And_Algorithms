O(n2) :
int n = height.size();
int area = 0;
for(int i = 0; i<n; i++){
for(int j = i+1; j<n; j++){
area = max ( area , min( height[i] , height[j] ) * ( j - i ) );
}
}
return area;