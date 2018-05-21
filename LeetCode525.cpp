int findMaxLength(vector<int>& nums) {
    if(nums.size() < 2)
        return 0;
    int n = (int)nums.size();
    vector<int> countArr(2*n+1, -n-1);
    countArr[n] = 0;
    int count = 0;
    int len = 0;
    for(int i = 0; i < n; i++){
        count += ((nums[i]^1) == 1) ? -1 : 1;
        // -n -> 0 -> n  2n + 1
        // 0 -> n -> 2n
        if(countArr[count + n] != -n-1){
            len = max(len, i + 1 - countArr[count + n]);
        } else {
            countArr[count + n] = i + 1;
        }
    }
    return len;
}
