#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int num, curr = 0, ans = 0;
    for(int i = 0;i < n;i++) {
        cin >> num;
        curr = max(curr + x,x);
        ans = max(ans,curr);
    }
    
    cout << ans;
    
	return 0;
}
