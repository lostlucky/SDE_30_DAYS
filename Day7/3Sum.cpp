// 3Sum 

class  Solution {
	
public: 
	vector<vector<int>> threeSum (vector<int>& nums){
		sort(nums.begin(), nums.end());
        if(nums.size() < 3) return {};
		vector<vector<int>>ans;
		int j, k, currSum;

		for(int i = 0; i < nums.size() - 2; i++){
            while(i > 0 and i < nums.size() and nums[i] == nums[i - 1]) i++;
			j = i + 1, k = nums.size() - 1;
			while(j < k){
				currSum = nums[j] + nums[k];
				if(currSum == -nums[i]){
                    ans.push_back({nums[i], nums[j], nums[k]}); 
                    while(j < k and nums[j] == nums[++j]) {}
                    while(k > j and nums[k] == nums[--k]) {}
                }
                else if(currSum < -nums[i]) j++;
                else k--;
            }
        }

        return ans;
    }
};

