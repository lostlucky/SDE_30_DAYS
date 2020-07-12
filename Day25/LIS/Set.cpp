class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size();
        set<int>s;
        for(auto x:nums){
            auto it = s.lower_bound(x);
            if(it != s.end()) s.erase(it);
            s.insert(x);
        }
        return s.size();
    }
};
