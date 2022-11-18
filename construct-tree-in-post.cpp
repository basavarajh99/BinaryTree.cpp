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
     TreeNode* construct(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end, map<int, int>& mp){
        if(post_start > post_end || in_start > in_end) return NULL;

        TreeNode* root = new TreeNode(postorder[post_end]);
        
        int in_root = mp[root->val];
        int remains = in_root - in_start;

        root->left =  construct(inorder, in_start, in_root-1, postorder, post_start, post_start+remains-1, mp);

        root->right =  construct(inorder, in_root+1, in_end, postorder, post_start+remains, post_end-1, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = construct(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);

        return root;
    }
};
