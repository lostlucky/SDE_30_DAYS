class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(!nums.size()) return {};
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<pair<int,int>>s;
        s.push({nums[0],0});
        for(int i = 1;i < nums.size();i++){
            while(!s.empty() and s.top().first < nums[i]){
                ans[s.top().second] = nums[i];
                s.pop();
            } 
            s.push({nums[i], i});
        }
        for(auto x:nums){
            while(!s.empty() and s.top().first < x){
                ans[s.top().second] = x;
                s.pop();
            }
        }
        return ans;
    }
};
