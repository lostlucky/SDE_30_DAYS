#include <bits/stdc++.h>
using namespace std;

int power(int base, int expo){
    if(expo == 0) return 1;
    int sqRoot = power(base, expo / 2);
    if(expo&1) return base * sqRoot * sqRoot; 
    else return sqRoot * sqRoot; 
}

int main() {
    
    int A;
    cin >> A;
    
    int n;
    cin >> n;
    
    int l = 0, r = A, m;
    
    while(l <= r){
        m = l + (r - l) / 2;
        int value = power(m, n);
        if(value == A){
            cout << m;
            break;
        } 
        else if(value < A) l = m + 1;
        else r = m - 1;
    }
    
    
    
	return 0;
}
