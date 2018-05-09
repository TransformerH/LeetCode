int countNumbersWithUniqueDigits(int n) {
    vector<int> ex(n+1 , 1);
    ex[1] = 10;
    for(int i = 2; i <= n; i++){
        ex[i] = 9;
        for(int j = 1, k = 9; j < i; j++, k--){
            ex[i] *= k;
        }
        ex[i] += ex[i-1];
    }
    
    return ex[n];
}
