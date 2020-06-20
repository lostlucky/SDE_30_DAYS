#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& v, int target){
    int l = 0, r = v.size() - 1, m, ans = -1;
    while(l <= r){
        m = l + (r - l) / 2;
        if(v[m] <= target) l = m + 1, ans = m;
        else r = m - 1;
    }
    return ans;
}

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        int m, n;
        cin >> m >> n;
        
        vector<vector<int>>matrix(m, vector<int>(n,0));
        
        int minVal = INT_MAX, maxVal = INT_MIN, req = (m * n + 1) / 2;
        
        unordered_map<int,int>freq;
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cin >> matrix[i][j];
                minVal = min(minVal, matrix[i][j]);
                maxVal = max(maxVal, matrix[i][j]);
            }
        }
        
        int l = minVal, r = maxVal, mid;
        
        int maxElement = INT_MIN, lesser;
        
        while(l <= r){
            mid = l + (r - l) / 2;
            lesser = 0;
            for(int i = 0;i < m;i++){
                int lb = lowerBound(matrix[i], mid);
                if(lb > -1) maxElement = max(maxElement, matrix[i][lb]);
                lesser += lb + 1;
            }
            
            if(lesser < req) l = mid + 1;
            else r = mid - 1;
        }
        cout << l << endl;
    }
    
	return 0;
}
