static bool compare(vector<int>& pair1, vector<int>& pair2){
    if(pair1[1] < pair2[1])
        return true;
    else
        return false;
}

int findLongestChain(vector<vector<int>>& pairs) {
    if(pairs.size() == 0)
        return 0;
    int size = (int)pairs.size();
    sort(pairs.begin(), pairs.end(), compare);
    int count = 1;
    int end = pairs[0][1];
    for(int i = 1; i < size; i++){
        if(pairs[i][0] > end){
            end = pairs[i][1];
            count++;
        }
    }
    return count;
}

