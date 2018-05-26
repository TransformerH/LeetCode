  
// dfs-stack
  int findCircleNum(vector<vector<int>>& M) {
    int res = 0;
    if(M.size() == 0)
        return res;
    int size = (int)M.size();
    vector<bool> visited(size, false);
    stack<int> friends;
    for(int i = 0; i < size; i++){
        if(visited[i] == false){
            res++;
            friends.push(i);
            while(!friends.empty()){
                int top = friends.top();
                friends.pop();
                visited[top] = true;
                for(int j = 0; j < size; j++){
                    if(M[top][j] == 1 && !visited[j])
                        friends.push(j);
                }
            }
        }
    }
    return res;
}