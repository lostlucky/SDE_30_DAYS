/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

0(1) space 

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* traverse = root;
        while(traverse -> left){
            Node* p = traverse;
            while(p){
                p -> left -> next = p -> right;
                if(p -> next) p -> right -> next = p -> next -> left;
                p = p -> next;
            }
            traverse = traverse -> left;
        }
        return root;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

0(N) space

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* pre;
            for(int i = 0;i < sz;i++){
                Node* curr = q.front();
                q.pop();
                if(i > 0) pre -> next = curr; 
                pre = curr;
                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }
        }
        return root;
    }
};
