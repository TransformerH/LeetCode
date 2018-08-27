 // 余数相同的数字相减之后余数抵消，所以差值是k的倍数
// 而连续的subarray则是拥有相同余数的从1累加到j 和 i之间的数字
// 总之求连续的subarray的和，还是用S(i, j) = S(1, j) - S(1, i)
 bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if (k != 0) sum %= k;
        if(map.find(sum) != map.end()){
            if(i - map[sum] > 1)
                return true;
        }
        else
            map[sum] = i;
    }
    return false;
}