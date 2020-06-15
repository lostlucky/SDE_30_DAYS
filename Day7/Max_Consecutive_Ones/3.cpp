// Max Consecutive Ones 3
	
class Solution {

public: 
	
	int longestOnes(vector<int>& nums, int k){
		int start = 0, ans = 0;
		for(int end = 0; end < nums.size(); end++){
			if(nums[end] != 1){
				if(k) k--;
				else{
					while(start <= end and nums[start++] == 1) {}				
                }
            }
			ans = max(ans, end - start + 1);
        }
        return ans;
    }
};

