 void subseaquences(vector<int>& cur, vector<int>& nums, set<vector<int>>& res, int start){
    if(cur.size() > 1 && res.find(cur) == res.end()){
        res.insert(cur);
    }
    if(start == nums.size())
        return;
    for(int i = start; i < nums.size(); i++){
        int size = (int)cur.size();
        if((size > 0 && cur[size-1] <= nums[i]) ||(size == 0)){
            cur.push_back(nums[i]);
            subseaquences(cur, nums, res, i+1);
            cur.pop_back();
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> resv;
    set<vector<int>> res;
    vector<int> cur;
    subseaquences(cur, nums, res, 0);
    for(auto it = res.begin(); it != res.end(); it++){
        resv.push_back(*it);
    }
    return resv;
}