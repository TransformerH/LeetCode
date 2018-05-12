int binarySearch(vector<int>& nums, int start, int end, int target){
    if(start > end)
        return -1;
    int mid = (start + end) / 2;
    if(nums[mid] == target)
        return mid;
    if(nums[mid] < target)
        start = mid + 1;
    else
        end = mid - 1;
    return binarySearch(nums, start, end, target);
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if(nums.size() == 0)
        return res;
    int size = (int)nums.size();
    int startIndex = binarySearch(nums, 0, size - 1, target);
    if(startIndex != -1){
        int endIndexA = startIndex;
        int endIndexB = startIndex;
        while(endIndexA < size && nums[endIndexA] == target)
            endIndexA++;
        while(endIndexB >= 0 && nums[endIndexB] == target)
            endIndexB--;
        endIndexA--;
        endIndexB++;
        vector<int> indexes;
        indexes.push_back(startIndex);
        indexes.push_back(endIndexA);
        indexes.push_back(endIndexB);
        sort(indexes.begin(), indexes.end());
        res[0] = indexes[0];
        res[1] = indexes[2];
    }
    return res;
}
