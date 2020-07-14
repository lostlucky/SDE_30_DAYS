int f(int beg, int end, vector<int>& nums, vector<vector<unsigned long long>>& dp, vector<vector<int>>& path){
    if(beg + 1 == end) return 0;
    if(dp[beg][end] != LLONG_MAX) return dp[beg][end];
    int len = nums[end] - nums[beg], val, index;
    
    for(int k = beg + 1;k < end;k++){
        val = len + f(beg, k, nums, dp, path) + f(k, end, nums, dp, path);
        if(dp[beg][end] > val) dp[beg][end] = val, index = k;
    }
    path[beg][end] = index;
    return dp[beg][end];
}

void pathCal(int i, int j, vector<int>& sol, vector<int>& nums, vector<vector<int>>& path){
    if(i + 1 == j) return;
    sol.push_back(nums[path[i][j]]);
    pathCal(i, path[i][j], sol, nums, path);
    pathCal(path[i][j], j, sol, nums, path);
}

vector<int> Solution::rodCut(int A, vector<int> &nums) {
    sort(nums.begin(), nums.end());
    nums.insert(nums.begin(), 0);
    nums.push_back(A);
    int n = nums.size();
    vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(n, LLONG_MAX));
    vector<vector<int>>path(n, vector<int>(n));
    f(0, n - 1, nums, dp, path);
    vector<int>sol;
    pathCal(0, n - 1, sol, nums, path);
    return sol;
}
