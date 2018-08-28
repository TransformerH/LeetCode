class MovingAverage {
    queue<int> q;
    int sum = 0;
    int s = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        if(q.size() == s){
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (double)sum / (double)q.size();
    }
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */