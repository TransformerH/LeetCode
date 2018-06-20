// BFS
int openLock(vector<string>& deadends, string target) {
      unordered_set<string> deadSet(deadends.begin(), deadends.end());
    if((deadSet.find(target) != deadSet.end()) ||(deadSet.find("0000") != deadSet.end()))
        return -1;
    queue<string> wheelq;
    queue<int> turnq;
    unordered_set<string> visited;
    turnq.push(0);
    wheelq.push("0000");
    visited.insert("0000");
    int turns = INT_MAX;
    while(!wheelq.empty()){
        string top = wheelq.front();
        int curturn = turnq.front();
        wheelq.pop();
        turnq.pop();
        if(top == target){
            turns = (curturn < turns) ? curturn : turns;
        }
        for(int i = 0; i < 4; i++){
            string tempUp = top;
            string tempDown = top;
            int curi = tempUp[i] - '0';
            int curiup = ((curi+1 > 9) ? 0 : curi+1);
            int curidown = ((curi-1 < 0) ? 9 : curi-1);
            tempUp[i] = curiup + '0';
            tempDown[i] = curidown + '0';
            bool findDown = (visited.find(tempDown) == visited.end()) && (deadSet.find(tempDown) == deadSet.end()) && (curidown >= (target[i]-'0'));
            bool findUp = (visited.find(tempUp) == visited.end()) && (deadSet.find(tempUp) == deadSet.end()) && (curiup <= (target[i]-'0'));
            if(findDown){
                wheelq.push(tempDown);
                visited.insert(tempDown);
                turnq.push(curturn+1);
            }
            if(findUp){
                wheelq.push(tempUp);
                visited.insert(tempUp);
                turnq.push(curturn+1);
            }
        }
    }
    return turns==INT_MAX ? -1 :turns;
}