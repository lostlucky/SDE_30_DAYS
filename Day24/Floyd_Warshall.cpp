#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>matrix(n, vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin >> matrix[i][j];
            }
        }
        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        const int INF = (int) 1e7;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == INF) cout << "INF";
                else cout << matrix[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}
