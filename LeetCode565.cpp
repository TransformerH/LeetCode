 int arrayNesting(vector<int>& nums) {
    int len = 0;
    vector<bool> visited(nums.size(), false);
    for(int i = 0; i < nums.size(); i++){
        if(!visited[i]){
            int start = nums[i];
            int j = nums[i];
            visited[i] = true;
            int cur = 1;
            while(nums[j] != start){
                visited[j] = true;
                cur++;
                j = nums[j];
            }
            if(cur > len)
                len = cur;
        }
    }
    return len;
}