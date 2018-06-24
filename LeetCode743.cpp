//Bellman-Ford
// VE
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;
    for(int i = 1; i <= N; i++){
        for(vector<int> e : times){
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }
    int time = 0;
    for(int i = 1; i < dist.size(); i++)
        time = max(time, dist[i]);
    return time==INT_MAX ? -1 : time;
}