class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int left = 0, right = n - 1, leftMax = height[0], rightMax = height[n - 1], ans = 0;
        while(left <= right){
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if(leftMax < rightMax){
                ans += leftMax - height[left];
                left++;
            }
            else{
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
