// calculate from both sides of array.
int longestMountain(vector<int>& A) {
    int size = (int)A.size();
    vector<int> up(size, 0);
    vector<int> down(size, 0);
    int longest = 0;
    for(int i = size-2; i >= 0; i--)
        if(A[i] > A[i+1])
            down[i] = down[i+1]+1;
    for(int j = 0; j < size; j++)
        if(j > 0 && A[j] > A[j-1]){
            up[j] = up[j-1] + 1;
            if(up[j] && down[j])
                longest = max(longest, up[j] + down[j] + 1);
        }
    
    return longest;
}

