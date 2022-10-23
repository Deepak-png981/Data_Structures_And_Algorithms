class RandomizedSet {
private:
    vector<int>ans;
    unordered_map<int , int>map;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //agar wo hua already ushme to 
        if(map.find(val) != map.end())  return false;
        ans.push_back(val);
        map[val] = ans.size() - 1;  //index ajayega isse
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end())  return false;
        int last = ans.back();
        map[last] = map[val];
        ans[map[val]] = last;
        ans.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return ans[rand() % ans.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */