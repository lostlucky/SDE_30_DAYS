class Solution {
    
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n = nums.size();
        map<int,int>mp;
        vector<int>link(n);
        mp[nums[0]] = 0, link[0] = -1;
        for(int i = 1;i < n;i++){
            auto it = mp.lower_bound(nums[i]);
            if(it != mp.end()) mp.erase(it);
            mp[nums[i]] = i;
            auto it2 = mp.lower_bound(nums[i]);
            if(it2 != mp.begin()){
                it2--;
                link[i] = (*it2).second;
            }
            else link[i] = -1;
        }
        for(int i = n - 1;i >= 0;i--){
            int j = i;
            while(j != -1) { cout << j << " "; j = link[j]; }
            cout << endl;
        }
        return mp.size();
    }
};
