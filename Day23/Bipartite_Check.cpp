class Solution {
    
    bool dfs(int i, bool col,vector<int>& color, vector<vector<int>>& graph){
        color[i] = col;
        for(auto x:graph[i]){
            if(color[x] != -1){
                if(color[x] == col) return 0;
            }
            else{
                if(!dfs(x, !col, color, graph)) return 0;
            }
        }
        return 1;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i = 0;i < n;i++){
            if(color[i] == -1) if(!dfs(i, 0, color, graph)) return 0;
        }
        return 1;
    }
};
