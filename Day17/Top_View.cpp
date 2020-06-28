void topView(struct Node *root)
{
    queue<pair<Node*, int>>q;
    
    map<int, int>present;
    
    if(root){
        q.push({root, 0});
        present[0] = root -> data;
    }
    
    while(!q.empty()){
        int  sz = q.size();
        while(sz--){
            auto current = q.front();
            Node* curr = current.first;
            int y = current.second;
            q.pop();
            
            if(curr -> left){
                q.push({curr -> left, y -  1});
                if( !present.count(y - 1) ) present[y - 1] = curr -> left -> data;
            }
            
            if(curr -> right){
                q.push({curr -> right, y +  1});
                if( !present.count(y + 1) ) present[y + 1] = curr -> right -> data;
            }
        }
    }
    
    for(auto x:present) cout << x.second << " ";
    
}
