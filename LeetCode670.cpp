  int maximumSwap(int num) {
    int res = 0;
    vector<int> numv;
    while(num > 0){
        numv.push_back(num % 10);
        num /= 10;
    }
    for(int i = (int)numv.size() - 1; i > 0; i--){
        int max = 0;
        int maxIndex = 0;
        for(int j = 0; j < i; j++ ){
            if(numv[j] > max){
                max = numv[j];
                maxIndex = j;
            }
        }
        if(max > numv[i]){
            swap(numv[i], numv[maxIndex]);
            break;
        }
    }
    
    for(int i = 0; i < numv.size(); i++){
        res += numv[i] * pow(10, i);
    }
    
    return res;
}