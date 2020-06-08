#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int xorArray = 0, xorAll = 0;
    
    vector<int> a(n,0);
    for(int i = 0;i < n;i++) cin >> a[i], xorArray ^= a[i], xorAll ^= (i + 1);
    
    int xorMissingRepeated = xorArray ^ xorAll;
    
    int parity = xorMissingRepeated & -xorMissingRepeated;
    
    int v1 = 0, v2 = 0;
    
    for(int i = 0;i < n;i++){
        if(a[i] & parity) v1 ^= a[i];
        else v2 ^= a[i];
        
        if((i + 1) & parity) v1 ^= i + 1;
        else v2 ^= i + 1;
    }
    
    for(auto element:a){
        if(element == v1){
            cout << "Repeated : " << v1 << " Missing : " << v2; 
            break;
        }
        else if(element == v2){
            cout << "Repeated : " << v2 << " Missing : " << v1; 
            break;
        }
    }
    
	return 0;
}
