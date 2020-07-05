void dfsTranspose(int i,vector<bool>&vis, vector<vector<int>>& transpose, vector<int>& SCC){
    vis[i] = 1;
    for(auto neighbor:transpose[i]) if(!vis[neighbor]) dfsTranspose(neighbor, vis, transpose, SCC);
    SCC.push_back(i);
}


void dfs(int i, vector<bool>&vis, vector<vector<int>>& adj, stack<int>& s){
    vis[i] = 1;
    for(auto neighbor:adj[i]) if(!vis[neighbor]) dfs(neighbor, vis, adj, s);
    s.push(i);
}

vector<vector<int> > Solution::solve(int V, vector<vector<int> > &E) {
    vector<vector<int>>adj(V + 1);
    for(auto edge:E){
        adj[edge[0]].push_back(edge[1]);
    }
    stack<int>s;
    vector<bool>vis(V + 1, 0);
    
    for(int i = 1;i <= V;i++){
        if(!vis[i]) dfs(i, vis, adj, s);
    }
    
    vector<vector<int>>transpose(V + 1);
    for(auto edge:E){
        transpose[edge[1]].push_back(edge[0]);
    }
    
    vis = vector<bool>(V + 1, 0);
    
    vector<vector<int>>ans;
    
    while(!s.empty()){
        int curr = s.top();
        s.pop();
        if(vis[curr]) continue; 
        vector<int>SCC;
        dfsTranspose(curr, vis, transpose, SCC);
        sort(SCC.begin(), SCC.end());
        ans.push_back(SCC);
    }
    
    return ans;
}
