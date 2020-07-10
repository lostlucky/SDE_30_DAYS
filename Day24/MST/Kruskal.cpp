class DSU{
    vector<int>parent, size;
    
public:
    DSU(int n){
        for(int i = 0;i < n;i++) parent.push_back(i), size.push_back(1);
    }
    
    int findSet(int v){
        if(v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }
    
    int sameSet(int a,int b){
        a = findSet(a), b = findSet(b);
        return a == b;
    }
    
    void unionSet(int a, int b){
        a = findSet(a), b = findSet(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};


bool comp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}


int Solution::solve(int A, vector<vector<int> > &B) {
    DSU dsu(A + 1);
    sort(B.begin(), B.end(), comp);
    int ans = 0;
    for(auto edge:B){
        int u = edge[0], v = edge[1], w = edge[2];
        if(!dsu.sameSet(u, v)) dsu.unionSet(u, v), ans += w;
    }
    return ans;
}
