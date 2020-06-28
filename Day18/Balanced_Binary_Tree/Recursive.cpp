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
    bool isBalanced(TreeNode* root) {
        bool check = 1;
        f(root, check);
        return check;
    }
    
    int f(TreeNode* root, bool& check){
        if(!root) return -1;
        int leftDepth = 1 + f(root -> left, check);
        int rightDepth = 1 + f(root -> right, check);
        check &= abs(leftDepth - rightDepth) <= 1;
        return max(leftDepth, rightDepth);
    }
};
