Node* f(Node* root, int key, bool suc){
    if(!root) return NULL;
    if(suc){
        if(root -> key > key){
            Node* ret = f(root -> left, key, suc);
            return ret ? ret : root;
        }
        else return f(root -> right, key, suc);
    }
    
    else{
        if(root -> key < key){
            Node* ret = f(root -> right, key, suc);
            return ret ? ret : root;
        }
        else return f(root -> left, key, suc);
    }
    
    return NULL;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = f(root, key, 0), suc = f(root, key, 1);

// Your code goes here

}
