int sort(vector<Interval>& intervals,int s,int f){
    int x = s;
    int y = f+1;
    Interval stemp = intervals[s];
    while(1){
        while(intervals[++x].end < stemp.end);
        while(intervals[--y].end > stemp.end);
        if(x>=y)
            break;
        Interval swap = intervals[x];
        intervals[x] = intervals[y];
        intervals[y] = swap;
    }
    intervals[s] = intervals[y];
    intervals[y] = stemp;
    return y;
}

void quick(vector<Interval>& intervals, int s,int f){
    if(s<f){
        int m = sort(intervals,s,f);
        quick(intervals, s, m-1);
        quick(intervals, m+1, f);
    }
}
    
 int eraseOverlapIntervals(vector<Interval>& intervals) {
     if(intervals.size() == 0)
         return 0;
    int count = 0;
    quick(intervals, 0, (int)intervals.size() - 1);
    int end = intervals[0].end;
    
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start < end)
            count++;
        else
            end = intervals[i].end;
    }
    return count;
}

//can't use sort(,,compare) on LeetCode

bool comp(Interval& in1, Interval& in2){
    if(in1.end <= in2.end)
        return true;
    else
        return false;
}

int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size() == 0)
        return 0;
    int count = 0;
    sort(intervals.begin(), intervals.end(), comp);
    int end = intervals[0].end;
    
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i].start < end)
            count++;
        else
            end = intervals[i].end;
    }
    return count;
}

