#include <bits/stdc++.h>
using namespace std;

int power(int base,int expo) {
    if(expo == 0) return 1;
    int root = power(base,expo / 2);
    if(expo&1) return base * root * root;
    else return root * root;
}

int main() {
    
    int base;
    cin >> base;
    
    int expo;
    cin >> expo;
    
    cout << power(base,expo);
    
	return 0;
}
