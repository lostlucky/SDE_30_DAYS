class Solution {
    
    struct comp{
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
        }
    };
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp>minHeap;
        vector<vector<vector<int>>>adj(N + 1);
        for(auto edge:times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int>dist(N + 1, INT_MAX);
        dist[K] = 0;
        minHeap.push({K, 0});
        int ans = 0;
        while(!minHeap.empty()){
            auto curr = minHeap.top().first;
            minHeap.pop();
            for(auto neighbor:adj[curr]){
                int to = neighbor[0], time = neighbor[1];
                if(dist[to] == INT_MAX or dist[to] > dist[curr] + time) dist[to] = dist[curr] + time, minHeap.push({to, dist[to]});
            }
        }
        for(int i = 1;i <= N;i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
