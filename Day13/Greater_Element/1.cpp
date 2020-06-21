class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(), nums2.end());
        int m = nums1.size(), n = nums2.size();
        stack<int>s;
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto x:nums2){
            while(!s.empty() and s.top() <= x) s.pop();
            if(!s.empty()) mp[x] = s.top();
            else mp[x] = -1;
            s.push(x);
        }
        for(auto x:nums1) ans.push_back(mp[x]);
        return ans;
    }
};
