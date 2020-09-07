#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int k;
        cin >> k;
        int n = s.size();
        vector<int>map(128, 0);
        int begin = 0, end = 0, ans = -1;
        while(end < n){
            if(map[s[end]]++ == 0){
                k--;
                while(k == -1){
                    if(map[s[begin++]]-- == 1) k++;
                }
            }
            if(k == 0) ans = max(ans, end - begin + 1);
            end++;
        }
        cout << ans << endl;
    }
    
    return 0;
}
