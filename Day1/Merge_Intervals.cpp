class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size()) return {};
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<vector<int>>ans;
        int startTime = intervals[0][0],endTime = intervals[0][1];
        for(auto& interval:intervals){
            if(endTime >= interval[0]) endTime = max(interval[1],endTime);
            else{
                ans.push_back({startTime,endTime});
                startTime = interval[0];
                endTime = interval[1];
            }
        }
        ans.push_back({startTime,endTime});
        return ans;
    }
    
    bool static comp(vector<int>& a,vector<int>& b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
};
