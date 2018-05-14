// time limit exceeded, I'll optimize the answer later.
int findTargetSumWays(vector<int>& nums, int S) {
    int num = 0;
    vector<int> sums;
    sums.push_back(nums[0]);
    sums.push_back(0 - nums[0]);
    for(int i = 1; i < nums.size(); i++){
        vector<int> tempSums;
        for(int j = 0; j < sums.size(); j++){
            tempSums.push_back(sums[j] + nums[i]);
            tempSums.push_back(sums[j] - nums[i]);
        }
        sums = tempSums;
    }
    
    for(int k = 0; k < sums.size(); k++)
        if(sums[k] == S)
            num++;
    
    return num;
}