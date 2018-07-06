 // dp
 int longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int longest = 0;
    int len = (int)s.length();
    vector<int> dp(len, 1);
    for(int i = 0; i < len; i++){
        if(s[i] == '(') left++;
        if(s[i] == ')'){
            if(left > 0) {
                dp[i]++;
                left--;
            }
        }
    }
    for(int j = len-1; j >= 0; j--){
        if(s[j] == ')' && dp[j] > 1) right++;
        if(s[j] == '('){
            if(right > 0){
                right--;
                dp[j] = 0;
            }
        }
    }
    
    int lastRight = 0;
    for(int k = 0; k < len; k++){
        if(s[k] == ')' && dp[k] > 1){
            lastRight += dp[k];
            longest = max(longest, lastRight);
        }
        if(dp[k] == 1){
            lastRight = 0;
        }
    }
    
    return longest;
}

