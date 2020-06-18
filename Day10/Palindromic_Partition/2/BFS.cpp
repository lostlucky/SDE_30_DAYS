class Solution {
    
    struct comp{
        bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second > b.second;
        }
    };

    vector<vector<int>>palin;
    
    void calPalin(int left, int right, string& s){
        while(left >= 0 and right < s.size() and s[left] == s[right]){
            palin[left].push_back(right + 1);
            left--, right++;
        }
    }
    
public:
    int minCut(string s) {
        if(!s.size()) return 0;
        palin.resize(s.size());
        for(int i = 0;i < s.size();i++){
            calPalin(i,i,s);
            calPalin(i, i + 1,s);
        }
        queue<int>q;
        q.push(0);
        vector<bool> vis(s.size() + 1, 0);
        int ans = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int index = q.front();
                q.pop();
                if(index == s.size()) return ans;
                for(auto nextIndex:palin[index]){
                    if(!vis[nextIndex]) vis[nextIndex] = 1, q.push(nextIndex);
                }
            }
            ans++;
        }
        return ans;
    }
};
