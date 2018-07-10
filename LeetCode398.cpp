//  hashmap
class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++){
            pickNum[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = 0;
        vector<int> targetNums = pickNum[target];
        if(targetNums.size() == 1)
            n = targetNums[0];
        else {
            int size = (int)targetNums.size();
            n = targetNums[rand() % size];
        }
        return n;
    }
private:
    unordered_map<int, vector<int>> pickNum;
};

