static bool comp(Interval i, Interval j){
        return i.start < j.start;
    }
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    bool addNew = false;
    for(int i = 0; i < intervals.size(); i++){
        if(!addNew && (intervals[i].end >= newInterval.start && newInterval.end >= intervals[i].start)){
                intervals[i].start = (intervals[i].start > newInterval.start)?newInterval.start:intervals[i].start;
                intervals[i].end = (intervals[i].end < newInterval.end)?newInterval.end:intervals[i].end;
                addNew = true;
        }
        if(!res.empty()){
            Interval *last = &(*(res.end()-1));
            if(last->end >= intervals[i].start){
                last->start = (last->start > intervals[i].start) ? intervals[i].start : last->start;
                last->end = (last->end < intervals[i].end) ? intervals[i].end : last->end;
            } else {
                res.push_back(intervals[i]);
            }
        } else {
            res.push_back(intervals[i]);
        }
    }
    if(!addNew){
        res.push_back(newInterval);
        sort(res.begin(), res.end(), comp);
    }
    return res;
}