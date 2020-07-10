class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int>dist(N + 1, INT_MAX);
        dist[K] = 0;
        for(int i = 0;i < N - 1;i++){
            vector<int>temp = dist;
            for(auto edge:times){
                int u = edge[0], v = edge[1], w = edge[2];
                if(dist[u] != INT_MAX) temp[v] = min(temp[v], dist[u] + w);
            }
            dist = temp;
        }
        int ans = 0;
        for(int i = 1;i <= N;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
