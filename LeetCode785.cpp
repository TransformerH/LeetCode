// bipartite can be solved by coloring the nodes with two different color.
// just remember it.
bool sameColor(vector<vector<int>>& graph,vector<int>& color, int node, int curcolor){
    if(color[node] != -1)
        return color[node] == curcolor;
    color[node] = curcolor;
    for(int aja : graph[node]){
        if(!sameColor(graph, color, aja, 1-curcolor))
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int size = (int)graph.size();
    vector<int> color(size, -1);
    for(int i = 0; i < size; i++){
        if(color[i] == -1 && !sameColor(graph, color, i, 0))
            return false;
    }
    return true;
}