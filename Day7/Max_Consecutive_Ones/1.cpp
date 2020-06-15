class Solution {

public: 
	int findMaxConsecutiveOnes(vector<int>& nums){
		int currCount  = 0, ans  = 0;
		for(int num:nums){
			if(num != 1) currCount = 0;
			else currCount++;
			ans = max(ans, currCount);
        }
        return ans;
    }

};

