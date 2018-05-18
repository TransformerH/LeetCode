void sumOfThree(vector<int>& nums, int target, vector<int>& sum, int start,int& res){
    if((int)sum.size() == 3){
        int curSum = 0;
        for(int num : sum)
            curSum += num;
        if(abs(target - res) > abs(target - curSum))
            res = curSum;
        return;
    }
    int curSum = 0;
    for(int num : sum)
        curSum += num;
    for(int i = start; i < nums.size(); i++){
        sum.push_back(nums[i]);
        sumOfThree(nums, target, sum, i+1, res);
        sum.erase(sum.end() - 1);
    }
}

int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    int res = abs(INT_MAX - target);
    vector<int> sum;
    sumOfThree(nums, target, sum, 0, res);
    return res;
}