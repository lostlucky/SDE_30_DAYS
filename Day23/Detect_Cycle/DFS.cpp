bool dfs(int i, int pre, unordered_set<int>&s, vector<vector<int>>& adj){
    s.insert(i);
    for(auto x:adj[i]){
        if(x == pre) continue;
        if(s.count(x)) return 1;
        if(dfs(x, i, s, adj)) return 1;
    }
    return 0;
}

int Solution::solve(int n, vector<vector<int> > &g) {
    
    vector<vector<int>>adj(n + 1);
    for(auto edge:g) adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
    
    int ans = 0;
    unordered_set<int>s;
    
    for(int i = 1;i <= n;i++){
        if(!s.count(i)) if(dfs(i, -1, s, adj))  return 1;
    }
    
    return ans;
}
