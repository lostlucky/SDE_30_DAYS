void dfs(int i, vector<bool>&vis, vector<vector<int>>& adj, stack<int>& s, vector<bool>&inStack, vector<int>&ids, vector<int>&lowLink, int& id, vector<vector<int>>& ans){
    vis[i] = 1;
    ids[i] = lowLink[i] = ++id;
    inStack[i] = 1;
    s.push(i);
    for(auto neighbor:adj[i]){
        if(!vis[neighbor]) dfs(neighbor, vis, adj, s, inStack, ids, lowLink, id, ans);
        if(inStack[neighbor]) lowLink[i] = min(lowLink[i], lowLink[neighbor]);
    }
    if(lowLink[i] == ids[i]){
        vector<int>SCC;
        while(1){
            int val = s.top();
            SCC.push_back(val);
            inStack[val] = 0;
            s.pop();
            if(val == i) break;
        }
        sort(SCC.begin(), SCC.end());
        ans.push_back(SCC);
    }
}

vector<vector<int> > Solution::solve(int V, vector<vector<int> > &E) {
    vector<vector<int>>adj(V + 1);
    for(auto edge:E){
        adj[edge[0]].push_back(edge[1]);
    }
    stack<int>s;
    vector<bool>vis(V + 1, 0), inStack(V + 1, 0);
    vector<int>ids(V + 1, 0), lowLink(V + 1, 0);
    vector<vector<int>>ans;
    int id = 0;
    
    for(int i = 1;i <= V;i++){
        if(!vis[i]) dfs(i, vis, adj, s, inStack, ids, lowLink, id, ans);
    }
    
    return ans;
}
