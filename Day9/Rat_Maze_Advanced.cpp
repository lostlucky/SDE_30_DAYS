vector<int>dr = {1, 0, 0, -1}, dc = {0, -1, 1, 0};
vector<char> v = {'D', 'L', 'R', 'U'};

void backtrack(int i,int j, int n, int m[][MAX], string& path, vector<string>& ans){
    
    if(i < 0 or j < 0 or i == n or j == n) return;
    if(m[i][j] == 0) return;
    if(i == n - 1 and j == n - 1){
        ans.push_back(path);
        return;
    }
    
    int x, y;
    m[i][j] = 0;
    for(int rc = 0;rc < 4;rc++){
        x = i + dr[rc], y = j + dc[rc];
        path.push_back(v[rc]);
        backtrack(x, y, n, m, path, ans);
        path.pop_back();
    }
    m[i][j] = 1;
    
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    string path;
    vector<string>ans;
    
    backtrack(0, 0, n, m, path, ans);
    
    return ans;
}
