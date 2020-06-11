#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int>a(n,0);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    unordered_map<int,int>mp;
    int pre = 0, ans = 0;
    mp[0] = -1;
    
    for(int i = 0;i < n;i++){
        pre += a[i];
        if(mp.count(pre)) ans = max(ans, i - mp[pre]);
        else mp[pre] = i;
    }
    
    cout << ans;
    
	return 0;
}
