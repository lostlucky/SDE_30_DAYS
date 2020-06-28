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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>path;
        unordered_map<TreeNode*, int>mp;
        stack<TreeNode*>s;
        
        if(root) s.push(root);
        
        while(!s.empty()){
            
            mp[s.top()]++;
            
            if( mp[s.top()] == 1 ){
                if(s.top() -> left) s.push(s.top() -> left);
            }
            
            else if( mp[s.top()] == 2 ){
                path.push_back(s.top() -> val);
                if(s.top() -> right) s.push(s.top() -> right);
            }
            
            else{
                s.pop();
            }
            
        }
        
        return path;
    }
};
