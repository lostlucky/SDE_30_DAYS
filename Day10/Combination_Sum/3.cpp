class Solution {
    
    vector<vector<int>>ans;
    
    void backtrack(int k, int d, vector<int>& path, int n){
        if(k == 0){
            if(n == 0) ans.push_back(path);
            return;
        }
        if(n < 0) return;
        for(int i = d;i < 10;i++){
            path.push_back(i);
            backtrack(k - 1, i + 1, path, n - i);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>path;
        backtrack(k, 1, path, n);
        return ans;
    }
};
