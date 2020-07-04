class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<int>q;
        vector<int>dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
        if(newColor == image[sr][sc]) return image;
        int n = image[0].size();
        int col = image[sr][sc];
        image[sr][sc] = newColor;
        q.push(sr * n + sc);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int currX = curr / n, currY = curr % n;
            for(int rc = 0;rc < 4;rc++){
                int x = currX + dr[rc], y = currY + dc[rc];
                if(x >= 0 and y >= 0 and x < image.size() and y < n and image[x][y] == col) { q.push(x * n + y); image[x][y] = newColor; }
            }
        }
        return image;
    }
};
