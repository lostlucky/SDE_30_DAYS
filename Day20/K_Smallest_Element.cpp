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
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        TreeNode* curr = root;
        while(1){
            if(s.empty() and !curr) break;
            while(curr) s.push(curr), curr = curr -> left;
            if(--k == 0) return s.top() -> val;
            curr = s.top() -> right;
            s.pop();
        }
        return 0;
    }
};
