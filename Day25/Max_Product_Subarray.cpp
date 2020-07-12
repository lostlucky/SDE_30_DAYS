class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int minVal, ans = nums[0], currProd = 1, maxElement = nums[0];
        bool alreadyNeg = 0;
        for(auto x:nums){
            maxElement = max(maxElement, x);
            if(x == 0){
                alreadyNeg = 0;
                currProd = 1;
                continue;
            }
            currProd *= x;
            if(currProd < 0){
                if(alreadyNeg) ans = max(ans, currProd / minVal);
                else alreadyNeg = 1, minVal = currProd;
            }
            else ans = max(ans, currProd);
        }
        return max(maxElement, ans);
    }
};
