 void permute(vector<int>& nums, int start, int end, set<vector<int>>& setRes){
    if(start == end){
        setRes.insert(nums);
    }
    for(int i = start; i <= end; i++){
        swap(nums[start], nums[i]);
        permute(nums, start + 1, end, setRes);
        swap(nums[start] , nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> setRes;
    if(nums.size() == 0)
        return res;
    permute(nums, 0, (int)nums.size() - 1, setRes);
    for(auto it = setRes.begin(); it != setRes.end(); it++)
        res.push_back(*it);
    return res;
}