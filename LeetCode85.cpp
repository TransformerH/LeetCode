// dp-hard
int maximalRectangle(vector<vector<char>>& matrix) {
       if(matrix.empty())
           return 0;
    int maxArea = 0;
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    for(int i = 0; i < m; i++){
        int cur_left = 0;
        int cur_right = n;
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == '1'){
                left[j] = max(left[j], cur_left);
                height[j]++;
            } else {
                cur_left = j+1;
                left[j] = 0;
                height[j] = 0;
            }
            if(matrix[i][n-1-j] == '1')
                right[n-1-j] = min(right[n-1-j], cur_right);
            else{
                cur_right = n-1-j;
                right[n-1-j] = n;
            }
                
        }
        for(int j = 0; j < n; j++)
            maxArea = max(maxArea, (right[j]- left[j])*height[j]);
    }
    return maxArea;
}