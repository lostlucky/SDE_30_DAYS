class Solution {
    
    bool f(int start, int hash, vector<int>& nums, int k, int curr, int sum){
        if(curr < 0) return 0;
        if(k == 1) return 1;
        if(curr == 0) return f(0, hash, nums, k - 1, sum, sum);
        for(int i = start;i < nums.size();i++){
            if(hash & (1 << i)) continue;
            if( f(i + 1, hash | (1 << i), nums, k, curr - nums[i], sum) ) return 1;
        }
        return 0;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k) return 0;
        return f(0, 0, nums, k, total / k, total / k);
    }
};
