class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // freq = 1 ==>return -1;
        //freq = 3*k ==> k/3
        //fre1= 3*k +1
        //10
        // 3 3 2 2
        //11 
        // 3 3 3 2
        unordered_map<int , int>map; // level of task , freq of the task
        //frequency stored
        for(auto it : tasks){
            map[it]++;
        }
        int rounds = 0;
        for(auto it : map){
            int curr = it.second;
            if(curr == 1){
                return -1;
            }
            if(curr %3 == 0){
                rounds += curr/3;
            }
            else if(curr % 3 == 2){
                rounds += curr/3;
                rounds++;
            }else{
                rounds += curr/3;
                rounds++;
            }
            
        }
        return rounds;
    }
};