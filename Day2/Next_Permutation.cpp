class Solution {
    
    int lowerBound(int start,vector<int>& nums){
        int target = nums[start - 1], l = start, r = nums.size() - 1, m, ans;
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m] > target) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        bool rev = 1;
        for(int i = n - 2;i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                swap(nums[i],nums[lowerBound(i + 1,nums)]);
                reverse(nums.begin() + i + 1,nums.end());
                rev = 0;
                break;
            }
        }
        if(rev) reverse(nums.begin(),nums.end());
    }
};
