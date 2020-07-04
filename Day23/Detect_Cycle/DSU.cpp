class DSU{
    vector<int>parent, size;
    
public:

    DSU(int n){
        for(int i = 0;i <= n;i++) parent.push_back(i), size.push_back(1);
    }    
    
    int findSet(int v){
        if(v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }
    
    void unionSet(int a, int b){
        a = findSet(a),b = findSet(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            size[a] += size[b];
            parent[b] = a;
        }
    }
};

int Solution::solve(int n, vector<vector<int> > &g) {
    DSU dsu(n + 1);
    for(auto i:g){
        if(dsu.findSet(i[0]) != dsu.findSet(i[1])) dsu.unionSet(i[0], i[1]);
        else return 1;
    }
    return 0;
}
