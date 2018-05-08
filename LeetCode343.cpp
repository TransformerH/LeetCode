int integerBreak(int n) {
    vector<int> mp(n+1,0);
    mp[1] = 1;
    mp[2] = 1;
    
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= i/2; j++){
            int first = (j > mp[j]) ? j : mp[j];
            int second = ((i - j) > mp[i-j]) ? (i-j) : mp[i-j];

            if(mp[i] < first * second)
                mp[i] = first * second;
        }
    }
    return mp[n];
}
