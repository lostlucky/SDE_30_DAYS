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
    int maxPathSum(TreeNode* root) {
        int ans = root -> val;
        f(root, ans);
        return ans;
    }
    
    int f(TreeNode* root, int& ans){
        if(!root) return 0;
        int leftVal = f(root -> left, ans);
        int rightVal = f(root -> right, ans);
        ans = max(ans, root -> val + (leftVal > 0 ? leftVal : 0) + (rightVal > 0 ? rightVal : 0));
        return root -> val + max({leftVal, rightVal, 0});
    }
};
