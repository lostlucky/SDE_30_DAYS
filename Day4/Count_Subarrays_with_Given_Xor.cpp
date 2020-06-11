#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    vector<int>a(n,0);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    unordered_map<int,int>mp;
    int XOR = 0, ans = 0;
    mp[0] = 1;
    
    for(int i = 0;i < n;i++){
        XOR ^= a[i];
        if(mp.count(XOR ^ m)) ans += mp[XOR ^ m];
        mp[XOR]++;
    }
    
    cout << ans;
    
	return 0;
}
