class Solution {
public:
    vector<int>dr,dc;
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if(!grid.size()) return 0;
        dr = {-1,1,0,0},dc = {0,0,-1,1};
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '1') dfs(i,j,grid),++ans;
            }
        }
        return ans;
    }
    
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(int rc = 0;rc < 4;rc++){
            dfs(i + dr[rc],j + dc[rc],grid);
        }
    }
};
