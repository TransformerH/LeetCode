// greedy algorithm
static bool comp(Interval& in1, Interval& in2){
    return in1.start < in2.start;
}
   vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
       if(intervals.size() == 0)
           return res;
    sort(intervals.begin(), intervals.end(), comp);
    Interval pre = intervals[0];
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start <= pre.end){
            pre.end = pre.end < intervals[i].end ? intervals[i].end : pre.end;
        } else {
            res.push_back(pre);
            pre = intervals[i];
        }
    }
    res.push_back(pre);
    return res;
}