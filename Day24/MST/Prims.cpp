#define p pair<int, int>

struct comp{
    bool operator()(p& a, p& b){
        return a.second > b.second;
    }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>selected(A + 1, 0);
    vector<vector<p>>adj(A + 1);
    for(auto edge:B){
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<p, vector<p>, comp>pq;
    pq.push({1, 0});
    int ans = 0;
    vector<bool>vis(A + 1, 0);
    vector<int>dist(A + 1, INT_MAX);
    dist[1] = 0; 
    while(!pq.empty()){
        auto [node, w] = pq.top();
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        ans += w;
        for(auto next:adj[node]){
            if(!vis[next.first] and next.second < dist[next.first]){
                dist[next.first] = next.second;
                pq.push(next);
            }
        }
    }
    return ans;
}
