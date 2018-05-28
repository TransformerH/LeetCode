void recursion(int N, int cur, vector<bool>& sits ,int& count){
    bool full = true;
    for(bool sit : sits){
        if(!sit)
            full = false;
    }
    if(full){
        count++;
        return;
    }
    for(int i = 1; i <= N; i++){
        if(cur % i == 0 || i % cur == 0){
            if(!sits[i]){
                sits[i] = true;
                recursion(N, cur + 1, sits, count);
                sits[i] = false;
            }
        }
    }
    
}

int countArrangement(int N) {
    int sum = 0;
    vector<bool> sits(N + 1, false);
    sits[0] = true;
    recursion(N, 1, sits, sum);
    return sum;
}