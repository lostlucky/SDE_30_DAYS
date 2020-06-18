class Solution {
    vector<vector<int>>ans;
    
    void backtrack(int i, vector<int>& path, vector<int>& nums, int target){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(i == nums.size()) return;
        for(int j = i;j < nums.size();j++){
            if(j > i and nums[j] == nums[j -  1]) continue;
            path.push_back(nums[j]);
            backtrack(j + 1, path, nums, target - nums[j]);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        backtrack(0, path, candidates, target);
        return ans;
    }
};
