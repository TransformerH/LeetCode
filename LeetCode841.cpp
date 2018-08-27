  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> enter(rooms.size(), false);
    queue<int> next;
    next.push(0);
    while(!next.empty()){
        int top = next.front();
        next.pop();
        if(!enter[top]){
            enter[top] = true;
            vector<int> nrooms = rooms[top];
            for(int room : nrooms)
                next.push(room);
        }
    }
    
    for(bool room : enter)
        if(!room)
            return false;
    return true;
}