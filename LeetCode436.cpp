vector<int> findRightInterval(vector<Interval>& intervals) {
    vector<int> result(intervals.size(), -1);
    map<int, int> startMap;
    for(int i = 0; i < intervals.size(); i++){
        startMap[intervals[i].start] = i;
    }
    for(int j = 0; j < intervals.size(); j++){
        map<int, int>::iterator startMapIt = startMap.lower_bound(intervals[j].end);
        if(startMapIt != startMap.end())
            result[j] = startMapIt->second;
    }
    return result;
}