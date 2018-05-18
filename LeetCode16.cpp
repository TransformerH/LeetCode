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

// better one


int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3)
        return 0;
    int res = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0; first < nums.size() - 2; first++){
        if(first > 0 && nums[first] == nums[first - 1])
            continue;
        int second = first+1;
        int third = (int)nums.size() - 1;
        while(second < third){
            int curSum = nums[first] + nums[second] + nums[third];
            if(curSum == target)
                return curSum;
            if(abs(target - res) > abs(target - curSum))
                res = curSum;
            if(target < curSum)
                third--;
            else
                second++;
        }
        
    }
    return res;
}
