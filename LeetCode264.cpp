// dp
// find the current smaller number
int nthUglyNumber(int n) {
    vector<int> uglies(n, 0);
    uglies[0] = 1;
    int factor2 = 0, factor3 = 0, factor5 = 0;
    for(int i = 1; i < n; i++){
        uglies[i] = min(2*uglies[factor2], min(3*uglies[factor3], 5*uglies[factor5]));
        if(uglies[i] == 2*uglies[factor2]) factor2++;
        if(uglies[i] == 3*uglies[factor3]) factor3++;
        if(uglies[i] == 5*uglies[factor5]) factor5++;
    }
    return uglies[n-1];
}