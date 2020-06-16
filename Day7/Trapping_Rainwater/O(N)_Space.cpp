class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int maxHeight = height[0];
        vector<int>left(n);
        for(int i = 0;i < n;i++){
            maxHeight = max(maxHeight, height[i]);
            left[i] = maxHeight;
        }
        maxHeight = height[n - 1];
        
        int ans = 0;
        
        for(int i = n - 1;i >= 0;i--){
            maxHeight = max(maxHeight, height[i]);
            ans += min(maxHeight, left[i]) - height[i];
        }
        return ans;
    }
};
