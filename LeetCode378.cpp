// right answer, time limited - same like merge sort
int kthSmallest(vector<vector<int>>& matrix, int k) {
    if(matrix.size() < 1)
        return 0;
    int n = (int)matrix.size();
    vector<int> ordered(n*n + 1, 0);
    ordered[0] = INT_MIN;
    int last = 0;
    for(int i = 0; i < n; i++){
        int next = 0;
        while(next < n){
            if(last < 0)
                last = 0;
            if(matrix[i][next] >= ordered[last]){
                ordered[last + 1] = matrix[i][next];
                next++;
                last = n * i + next;
            }else {
                ordered[last + 1] = ordered[last];
                last--;
            }
        }
    }
    return ordered[k];
}

// binary search range method
// when the array is unordered. but we can get the min and max elements of the array.
/*
算法语言描述：
用元素的数值范围而不是元素的下标值范围对目标值进行逼近。
数组中的元素值范围为lowest...highest，
数组中的所有元素的值都在lowest...mid 和 mid+1... highest两个区间内，
mid不一定是在数组中，可能只是一个参考值，

使用方法：
1. 寻找xth的元素(LeetCode378)：
    如果数组中处于lowest...mid的元素的个数小于x，则xth在mid+1...highest区间内，
    所以将lowest = mid + 1，查找的数值范围减小为原先的一半。
2. 寻找重复的元素(LeetCode287):
    如果数组中小于mid的元素的总个数小于范围值的一半，则证明大于mid的元素中有元素值重复。

*/

 int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int le = matrix[0][0], ri = matrix[n - 1][n - 1];
        int mid = 0;
        while (le < ri)
        {
            mid = le + (ri-le)/2;
            int num = 0;
            for (int i = 0; i < n; i++)
            {
                // array should be sorted
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                // the elements that has index from 0 to pos - 1 are lower than or equal to mid, the number of those elements is pos - 1 - 0 + 1 = pos
                num += pos;
            }
            if (num < k)
            {
                le = mid + 1;
            }
            else
            {
                ri = mid;
            }
        }
        return le;
    }