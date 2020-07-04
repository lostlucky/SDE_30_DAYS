#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<int>a(n, 0);
	    for(int i = 0;i < n;i++) cin >> a[i];
	    
	    int k;
	    cin >> k;
	    
	    int begin = 0, end = n - 1, pivot, randIndex;
	    
	    while(1){
    	    pivot = begin;
    	    randIndex = begin + rand() % (end - begin + 1);
    	    
    	    swap(a[randIndex], a[end]);
    	    
    	    for(int i = begin;i < end;i++){
    	        if(a[i] < a[end]) swap(a[pivot], a[i]), pivot++;
    	    }
    	    swap(a[end], a[pivot]);
    	    
    	    if(pivot + 1 == k){
    	        cout << a[pivot] << endl;
    	        break;
    	    }
    	    
    	    else if(pivot + 1 < k) begin = pivot + 1;
    	    
    	    else end = pivot - 1;
    	    
	    }
	    
	}
	
	return 0;
}
