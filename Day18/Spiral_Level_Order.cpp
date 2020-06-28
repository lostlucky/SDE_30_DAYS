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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        bool level = 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>now;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                now.push_back(node -> val);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            if(level) reverse(now.begin(),now.end());
            ans.push_back(now);
            now.clear();
            level = !level;
        }
        return ans;
    }
};
