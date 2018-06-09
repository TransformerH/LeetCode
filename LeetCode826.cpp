static bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    int pro = 0;
    vector<pair<int, int>> diffPro;
    for(int i = 0; i < profit.size(); i++)
        diffPro.push_back(make_pair(profit[i], difficulty[i]));
    
    sort(diffPro.begin(), diffPro.end(), comp);
    for(int i = 0; i < worker.size(); i++){
        for(int j = 0; j < diffPro.size(); j++){
            if(diffPro[j].second <= worker[i]){
                pro += diffPro[j].first;
                break;
            }
        }
    }
    
    return pro;
}