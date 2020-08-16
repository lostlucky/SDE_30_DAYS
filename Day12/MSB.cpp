// Inbuilt log function 


#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    cout << ( 1 << ( (int) log2(n) ) );
    
	return 0;
}

// -----------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    
    n++;
    
    cout << (n >> 1);
    
	return 0;
}
