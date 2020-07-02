int kthLargest(Node *root, int k)
{
    stack<Node*>s;
    Node* curr = root;
    while(1){
        if(s.empty() and !curr) break;
        while(curr) s.push(curr), curr = curr -> right;
        if(--k == 0) return s.top() -> data;
        curr = s.top() -> left;
        s.pop();
    }
    return 0;
}
