class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int unique = 0, start = 0;
        
        if(nums.size() < 2) return nums.size();
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != nums[i - 1]){
                swap(nums[unique++], nums[start]);
                start = i;
            }
        }
        
        swap(nums[unique++], nums[start]);
        
        nums.erase(nums.begin() + unique, nums.end());
        
        return unique;
    }
};
