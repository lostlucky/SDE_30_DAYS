#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int base = 5, ans = 0;
    while(n / base){
        ans += n / base;
        base *= 5;
    }
    
    cout << ans;
    
	return 0;
}
