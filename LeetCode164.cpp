int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int maxn = nums[0], minn = nums[0];
        int size = nums.size();
       
        for(int num : nums){
            maxn = max(maxn, num);
            minn = min(minn, num);
        }
        
        int gap = (int)ceil((double)(maxn - minn) / (size-1));
        vector<int> largest(size-1, INT_MIN);
        vector<int> smallest(size-1, INT_MAX);
        
        for(int i = 0; i < size; i++){
            if(nums[i] == maxn || nums[i] == minn)
                continue;
            int index = (nums[i]-minn) / gap;
            largest[index] = max(largest[index], nums[i]);
            smallest[index] = min(smallest[index], nums[i]);
        }
        
        int previous = minn;
        int res = INT_MIN;
        for(int i = 0; i < size-1; i++){
            if(largest[i] == INT_MIN && smallest[i] == INT_MAX)
                continue;
            res = max(res, smallest[i] - previous);
            previous = largest[i];
        }
        return max(res, maxn - previous);
    }