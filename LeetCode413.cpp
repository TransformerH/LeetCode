int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() < 3)
        return 0;
    int result = 0;
    int len = (int)A.size();
    vector<bool> isAS;
    for(int i = 0; i < len - 2; i++){
        if((A[i+1] - A[i]) == (A[i+2] - A[i+1])){
            result++;
            for(int j = i-1; j >= 0; j--){
                if(isAS[j]){
                    result++;
                }else{
                    break;
                }
            }
            isAS.push_back(true);
        }else{
            isAS.push_back(false);
        }
    }
    return result;
}