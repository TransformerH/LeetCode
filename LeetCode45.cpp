 int jump(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int i = 0, reach = 0, nextreach = 0, times = 0;
        int n = nums.size();
        while(reach - i + 1 > 0) {
            times++;
        for(; i <= reach; i++){
           nextreach = max(nextreach, i + nums[i]);
            if(nextreach >= n-1)
                return times;
        }
            reach = nextreach;
        }
        
        return times;
}