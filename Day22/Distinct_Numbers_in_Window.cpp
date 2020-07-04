vector <int> countDistinct (int a[], int n, int k)
{
    unordered_map<int,int>mp;
    int count = 0;
    for(int i = 0;i < k - 1;i++){
        if(++mp[a[i]] == 1) count ++;
    }
    vector<int>ans;
    for(int i = k - 1;i < n;i++){
        if(++mp[a[i]] == 1) count ++;
        ans.push_back(count);
        if(--mp[a[i - k + 1]] == 0) count --;
    }
    return ans;
}
