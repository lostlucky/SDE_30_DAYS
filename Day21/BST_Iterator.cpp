/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    
    stack<TreeNode*>s;
    TreeNode* curr;
    
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(curr) s.push(curr), curr = curr -> left;
        int ans = s.top() -> val;
        curr = s.top() -> right;
        s.pop();
        return ans;
     }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(s.empty() and !curr);
    }
};



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
