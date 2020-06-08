#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    int start = 0, end = n - 1;
    
    for(int i = 0;i <= end;i++){
        while(1){
            if(start < i and a[i] == 0) swap(a[i],a[start++]);
            else if(i < end and a[i] == 2) swap(a[i],a[end--]);
            else break;
        }
    }
    
    for(auto x:a) cout << x << " ";
    
	return 0;
}
