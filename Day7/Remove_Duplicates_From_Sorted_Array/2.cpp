class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;
        
        int k = 2;
        
        for(int n:nums){
            if(i < k or nums[i - k] < n){
                nums[i++] = n;
            }
        }
        
        return i;
    }
};
