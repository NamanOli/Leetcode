class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        bool l = false;
        bool w = false;
        for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == 0) w = true;
                    else if(grid[i][j] == 1) l = true;
                }
        }
        if(!l || !w) return -1;


        int md = 1; //keep track of max distance found; answer will be this figure less one because water adjacent to land starts with distance 2.
        bool added = true;
        while(added == true){
            added = false;
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[0].size(); j++){
                    if(grid[i][j] == md){
                        if(i > 0 && grid[i-1][j] == 0){
                            grid[i-1][j] = md + 1;
                            added = true;
                        }
                        if(j > 0 && grid[i][j-1] == 0){
                            grid[i][j-1] = md + 1;
                            added = true;
                        }
                        if(i < grid.size() -1 && grid[i+1][j] == 0){
                            grid[i+1][j] = md + 1;
                            added = true;
                        }
                        if(j < grid[0].size() - 1 && grid[i][j+1] == 0){
                            grid[i][j+1] = md + 1;
                            added = true;
                        }
                    }
                }
            }
            if(added == true) md++;
        }
        return md - 1;     
        }
};