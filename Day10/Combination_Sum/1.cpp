class Solution {
    
    vector<vector<int>>ans;
    
    void backtrack(int i, vector<int>& path, vector<int>& nums, int target){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int j = i;j < nums.size();j++){
            path.push_back(nums[j]);
            backtrack(j, path, nums, target - nums[j]);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(0, path, candidates, target);
        return ans;
    }
};
