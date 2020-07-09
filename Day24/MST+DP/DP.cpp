class Solution {
    
    const int INF = (int) 1e9;
    vector<vector<int>>dp;
    
    int f(int src, int dst, unordered_map<int, vector<pair<int,int>>>& adj, int k){
        if(src == dst) return 0;
        if(k == 0) return INF;
        if(dp[src][k] != INF) return dp[src][k];
        for(auto next:adj[src]){
            dp[src][k] = min(dp[src][k], next.second + f(next.first, dst, adj, k - 1));
        }
        return dp[src][k] = min(dp[src][k], INF - 1);
    }
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;
        dp.resize(n, vector<int>(k + 1, INF));
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto edge:flights) adj[edge[0]].push_back({edge[1], edge[2]});
        int ans = f(src, dst, adj, k);
        return ans == INF - 1 ? -1 : ans;
    }
};
