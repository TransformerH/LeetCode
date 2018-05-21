bool binarySearch(vector<int>& nums, int start, int end, int target){
    int left = start;
    int right = end;
    while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

bool search1(vector<int>& nums, int target) {
    int pivot = 0;
    int n = (int)nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i] - nums[i-1]  < 0){
            pivot = i;
            break;
        }
    }
    
    return binarySearch(nums, pivot, n - 1, target) || binarySearch(nums, 0, pivot - 1, target);
}