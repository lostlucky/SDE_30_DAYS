class Solution {
    vector<vector<string>>ans;
    unordered_set<int>right, left, mid;
    
    void f(int x, vector<string>& path, int n){
        if(x == n){
            ans.push_back(path);
            return;
        }
        for(int y = 0;y < n;y++){
            if(!mid.count(y) and !right.count(x - y) and !left.count(x + y)){
                path[x][y] = 'Q';
                mid.insert(y), right.insert(x - y), left.insert(x + y);
                f(x + 1, path, n);
                path[x][y] = '.';
                mid.erase(y), right.erase(x - y), left.erase(x + y);
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        string level = "";
        for(int i = 0;i < n;i++) level += ".";
        vector<string>path(n, level);
        f(0, path, n);
        return ans;
    }
};
