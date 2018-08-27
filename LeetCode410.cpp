 bool canBeCutBy(int max, vector<int>& nums, int cuts){
    int sum = 0;
    for(int num : nums){
        if(num > max)
            return false;
        else if(sum + num <= max)
            sum += num;
        else {
            cuts--;
            sum = num;
            if(cuts < 0)
                return false;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    int left = 0, right = 0;
    for(int num : nums){
        left = max(left, num);
        right += num;
    }
    while(left < right){
        int mid = left + (right - left) / 2;
        if(canBeCutBy(mid, nums, m - 1))
            right = mid;
        else
            left = mid + 1;
    }
    
    return left;
}