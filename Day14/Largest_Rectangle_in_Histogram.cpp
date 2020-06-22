class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        if(!heights.size()) return 0;
        
        int ans = 0, n = heights.size(), lastIndex;
        
        stack<int>position, height;
        position.push(0);
        height.push(heights[0]);
        
        for(int i = 1;i < n;i++){
            
            lastIndex = i;
            
            while( !position.empty() and heights[i] <= height.top() ){
                ans = max(ans, (i - position.top()) * height.top());
                lastIndex = position.top();
                position.pop();
                height.pop();
            }
            
            position.push(lastIndex);
            height.push(heights[i]);
            
        }
        
        while(!position.empty()){
            ans = max(ans, (n - position.top()) * height.top());
            position.pop();
            height.pop();
        }
        
        return ans;
        
    }
};
