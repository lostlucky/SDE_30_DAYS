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
    
    TreeNode* prev(TreeNode* root){
        TreeNode* initial = root;
        if(!root -> left) return NULL;
        root = root -> left;
        while(root -> right){
            if(root -> right == initial) return root;
            root = root -> right;
        }
        return root;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* prevNode;
        while(root){
            prevNode = prev(root);
            if(!prevNode){
                ans.push_back(root -> val);
                root = root -> right;
            }
            else if(prevNode -> right){
                ans.push_back(root -> val);
                prevNode -> right = NULL;
                root = root -> right;
            }
            else{
                prevNode -> right = root;
                root = root -> left;
            }
        }
        for(auto x:ans) cout << x << " ";
        return ans;
    }
};
