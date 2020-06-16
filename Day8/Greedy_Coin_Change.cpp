// Works for standard denominations only


#include <bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int>denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	
	int value;
	cin >> value;
	
	int ans = 0;
	
	for(int i = denominations.size() - 1;i >= 0;i--){
	    int num = value / denominations[i];
	    ans += num;
	    value -= num * denominations[i];
	}
	
	cout << ans;
	
	return 0;
}
