// dp
 int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp;
    dp.push_back(triangle[0]);
    for(int i = 1; i < triangle.size(); i++){
        dp.push_back(vector<int>(triangle[i].size(), 0));
        for(int j = 0; j < triangle[i].size(); j++){
            if(j > 0 && j < triangle[i].size()-1)
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
             else if(j == 0)
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            else if(j == triangle[i].size()-1)
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
        }
        
    }
    int isize = (int)triangle.size();
    int minPath = dp[isize-1][0];
    for(int i = 1; i < dp[isize-1].size(); i++)
        minPath = min(minPath, dp[isize-1][i]);
    return minPath;
}