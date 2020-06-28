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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
    
    int f(TreeNode* root, int& ans){
        if(!root) return -1;
        int leftDepth = 1 + f(root -> left, ans);
        int rightDepth = 1 + f(root -> right, ans);
        ans = max(ans, leftDepth + rightDepth);
        return max(leftDepth, rightDepth);
    }
};
