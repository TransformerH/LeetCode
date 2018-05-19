bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int tLine = 0;
    if(matrix.size() > 1){
        tLine = 1;
        for(;tLine < matrix.size(); tLine++){
            if(target < matrix[tLine][0] && target >= matrix[tLine - 1][0])
                break;
        }
         tLine -= 1;
    }
    int left = 0;
    int right = (int)matrix[0].size();
    while(left <= right){
        int mid = (left + right) / 2;
        if(matrix[tLine][mid] == target)
            return true;
        if(matrix[tLine][mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false;
}