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
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        if(!root) return 1;
        if(root -> val < maxVal and root -> val > minVal) return isValidBST(root -> left, minVal, min((long) root -> val, maxVal)) and isValidBST(root -> right, max((long) root -> val, minVal), maxVal);
        return 0;
    }
};
