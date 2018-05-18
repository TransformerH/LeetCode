vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    set<vector<int>> setRes;
    if(nums.size() < 4)
        return res;
    int size = (int)nums.size();
    sort(nums.begin(), nums.end());
    for(int first = 0; first < size - 3; first++){
        int fourth = size - 1;
        while(fourth >= first + 3){
            int second = first + 1;
            int third = fourth - 1;
            while(second < third){
                int curSum = nums[first] + nums[second] + nums[third] + nums[fourth];
                if(curSum == target){
                    vector<int> result;
                    result.push_back(nums[first]);
                    result.push_back(nums[second]);
                    result.push_back(nums[third]);
                    result.push_back(nums[fourth]);
                    setRes.insert(result);
                }
                if(curSum < target)
                    second++;
                else
                    third--;
            }
            fourth--;
        }
    }
    for(set<vector<int>>::iterator it = setRes.begin(); it != setRes.end(); it++)
        res.push_back(*it);
    return res;
}
