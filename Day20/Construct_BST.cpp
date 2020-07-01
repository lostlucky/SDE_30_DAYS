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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(0, nums.size() - 1, nums);
    }
    
    TreeNode* f(int l, int r, vector<int>& nums){
        if(r < l) return NULL;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root -> left = f(l, m - 1, nums);
        root -> right = f(m + 1, r, nums);
        return root;
    }
};
