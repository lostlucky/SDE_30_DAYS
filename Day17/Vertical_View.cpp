vector<int> verticalOrder(Node *root)
{
    vector<int>ans;
    map<int, vector<int>>mp;
    
    queue<pair<Node*, int>>q;
    if(root) q.push({root, 0});
    
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto current = q.front();
            q.pop();
            Node* curr = current.first;
            int y = current.second;
            mp[y].push_back(curr -> data);
            
            if(curr -> left) q.push({curr -> left, y - 1});
            if(curr -> right) q.push({curr -> right, y + 1});
            
        }
    }
    
    for(auto x:mp){
        for(auto y:x.second){
            ans.push_back(y);
        }
    }
    
    return ans;
}
