#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
    return (double) a.first / a.second > (double) b.first / b.second; 
}

int main() {
    
    int t;
    cin >> t;
	
	while(t--){
	    
    	int n, w;
    	cin >> n >> w;
    	
    	vector<pair<int,int>>v;
    	int a, b;
    	for(int i = 0;i < n;i++){
    	    cin >> a >> b;
    	    v.push_back({a,b});
    	}
    	
    	sort(v.begin(), v.end(), comp);
    	double ans = 0;
    	for(auto x:v){
    	    if(w > x.second){
    	        ans += x.first;
    	        w -= x.second;
    	    }
    	    else{
    	        double fraction = (double) w / x.second;
    	        ans += (double) (fraction * x.first);
    	        break;
    	    }
    	}
    	
    	cout << fixed;
    	cout << setprecision(2) << ans << endl;
	}
	
	return 0;
}
