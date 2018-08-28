 int islandPerimeter(vector<vector<int>>& grid) {
         int res = 0;
    int size = (int)grid.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
            if(i-1 < 0 || grid[i-1][j] == 0)
                res++;
            if(i+1 >= size || grid[i+1][j] == 0)
                res++;
            if(j-1 < 0 || grid[i][j-1] == 0)
                res++;
            if(j+1 >= grid[i].size() || grid[i][j+1] == 0)
                res++;
            }
        }
    }
    
    return res;
    }