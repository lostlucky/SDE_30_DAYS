#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        vector<string>v;
        string aux;
        
        for(int i = 1;i < (1 << n);i++){
            aux = "";
            for(int j = 0;j < n;j++){
                if(i & (1 << j)) aux.push_back(s[j]);
            }
            v.push_back(aux);
        }
        
        sort(v.begin(), v.end());
        
        for(auto x:v) cout << x << " ";
        cout << endl;
    }
    
	return 0;
}
