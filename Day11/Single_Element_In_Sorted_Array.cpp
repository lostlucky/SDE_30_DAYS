class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m, n = nums.size();
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n - 2] != nums[n - 1]) return nums[n - 1];
        while(l <= r){
            m = l + (r - l) / 2;
            if(nums[m - 1] != nums[m] and nums[m] != nums[m + 1]) return nums[m];
            if(m%2 == 0){
                (nums[m - 1] != nums[m]) ? l = m + 1 : r = m - 1;
            }
            else{ 
                (nums[m] != nums[m + 1]) ? l = m + 1 : r = m - 1;
            }
        }
        return 0;
    }
};
