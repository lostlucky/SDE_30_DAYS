class Solution {
    int ans = 0;
    unordered_set<int>right, left, mid;
    
    void f(int x, int n){
        if(x == n){
            ans++;
            return;
        }
        for(int y = 0;y < n;y++){
            if(!mid.count(y) and !right.count(x - y) and !left.count(x + y)){
                mid.insert(y), right.insert(x - y), left.insert(x + y);
                f(x + 1, n);
                mid.erase(y), right.erase(x - y), left.erase(x + y);
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        f(0, n);
        return ans;
    }
};
