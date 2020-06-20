// Madarchod bhosdike lawda randi chutiya question 

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--){
        int n, ans = 0;
        cin >> n;
        
        int k = __builtin_popcount(n);
        
        while(n){
            int leftBit = n&-n;
            n &= (n - 1);
            ans += log2(leftBit) * (leftBit >> 1) + (--k) * leftBit + 1;
        }
        
        cout << ans << endl;
        
    }
    
	return 0;
}
