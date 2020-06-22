class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<int>q;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) q.push(i * n + j);
            }
        }
        
        vector<int>dr = {0, 0, -1, 1}, dc = {-1, 1, 0, 0};
        
        int ans = -1;
        
        bool none = q.empty();
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                int currX = curr / n, currY = curr % n;
                for(int rc = 0;rc < 4;rc++){
                    int x = currX + dr[rc], y = currY + dc[rc];
                    if(x >= 0 and y >= 0 and x < m and y < n and grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push(x * n + y);
                    }
                }
            }
            ++ans;
        }
        
        for(auto &vec:grid){
            for(auto e:vec) if(e == 1) return -1;
        }
        
        if(none) return 0;
        
        return ans;
    }
};
