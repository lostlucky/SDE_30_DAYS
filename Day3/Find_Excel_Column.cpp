#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    
    int ans = 0;
    for(int i = 0;i < s.size();i++) ans = ans * 26 + (s[i] - 'A' + 1);
    
    
    cout << ans << endl;
    
	return 0;
}
