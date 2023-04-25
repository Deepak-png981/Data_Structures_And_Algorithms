class SmallestInfiniteSet {
public:
    map<int,int>m;
    
    SmallestInfiniteSet() {
		//we will put all the numbers till 1001 so that even after all the pop operation map not become empty
        for(int i=1;i<1002;i++){
            m[i]++;
        }
    }
    
    int popSmallest() {
		//we will store the value of top element as in map they are sorted in asending order
        int val=m.begin()->first;
		//Erasing the element from the map
        m.erase(m.begin());
		//returning the value
        return val;
    }
    
    void addBack(int num) {
		//adding to the map 
        m[num]++;
    }  
    
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */