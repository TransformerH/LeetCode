 // variable-size window
 int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int minLen = INT_MAX;
    
    int left = 0;
    int right = 0;
    int curSum = nums[0];
    int size = (int)nums.size();
    while(left <= right){
        if(curSum < s){
            if(right < size-1){
                right++;
                curSum += nums[right];
            }
            else
                break;
        } else {
            minLen = min(minLen, right - left + 1);
            curSum -= nums[left];
            if(left < size-1){
                left++;
            }
            else
                break;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}