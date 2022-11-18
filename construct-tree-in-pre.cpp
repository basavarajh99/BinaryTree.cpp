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
    TreeNode* construct(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end, map<int, int>& mp){
        if(pre_start > pre_end || in_start > in_end) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        int in_root = mp[root->val];
        int remains = in_root - in_start;

        root->left =  construct(preorder, pre_start+1, pre_start+remains, inorder, in_start, in_root-1, mp);

        root->right = construct(preorder, pre_start+remains+1, pre_end, inorder, in_root+1, in_end, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        TreeNode* root = construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);

        return root;
    }
};
