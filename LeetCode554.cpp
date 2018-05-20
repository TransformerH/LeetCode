 int leastBricks(vector<vector<int>>& wall) {
    if(wall.size() == 0)
        return 0;
    int largest = 0;
    int sumLen = 0;
    for(int i = 0; i < wall[0].size(); i++)
        sumLen += wall[0][i];
    unordered_map<int, int> cut;
    for(auto i : wall){
        int curLen = 0;
        for(int len : i){
            curLen += len;
            if(curLen < sumLen){
                if(cut.find(curLen) == cut.end())
                    cut[curLen] = 1;
                else
                    cut[curLen]++;
                if(cut[curLen] > largest)
                    largest = cut[curLen];
            }
        }
    }
       
    return (int)wall.size() - largest;
}