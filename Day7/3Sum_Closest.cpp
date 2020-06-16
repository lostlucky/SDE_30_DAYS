class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return {};
		int j, k, currSum, ans = nums[0] + nums[1] + nums[2];

		for(int i = 0; i < nums.size() - 2; i++){
            while(i > 0 and i < nums.size() - 2 and nums[i] == nums[i - 1]) i++;
			j = i + 1, k = nums.size() - 1;
			while(j < k){
				currSum = nums[i] + nums[j] + nums[k];
				if(currSum == target) return target;
                else if(currSum < target){
                    j++;
                    target - currSum > abs(ans - target) ?: ans = currSum;
                }
                else{
                    k--;
                    currSum - target > abs(ans - target) ?: ans = currSum;
                }
            }
        }
        return ans;
    }
};


