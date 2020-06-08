#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> a(n,0);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    int m;
    cin >> m;
    
    vector<int> b(m,0);
    for(int i = 0;i < m;i++) cin >> b[i];
    
    for(int i = 0;i < n;i++){
        if(a[i] > b[0]){
            swap(a[i], b[0]);
            for(int j = 1;j < m;j++) {
                if(b[j - 1] > b[j]) swap(b[j - 1],b[j]);
                else break;
            }
        }
    }
    
    for(auto element:a) cout << element << " ";
    
    cout << endl;
    
    for(auto element:b) cout << element << " ";
    
    
	return 0;
}
