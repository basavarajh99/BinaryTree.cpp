
    void parentAndDepth(TreeNode* root, int x, int y, int level, int& depth_x, int& parent_x,                                                                   int& depth_y, int& parent_y)
    {
        if(!root) return;
        
        if(root->left)
        {
            if(root->left->val == x)
            {
                parent_x = root->val;
                depth_x = level+1;
            }
            else if(root->left->val == y)
            {
                parent_y = root->val;
                depth_y = level+1;
            }
        }
        
         if(root->right)
            {
                if(root->right->val == x)
                {
                    parent_x = root->val;
                    depth_x = level+1;
                }
                else if(root->right->val == y)
                {
                    parent_y = root->val;
                    depth_y = level+1;
                }
            }
        
        if(depth_x != -1 and depth_y != -1) return;
        
        parentAndDepth(root->left, x, y, level+1, depth_x, parent_x, depth_y, parent_y);
        parentAndDepth(root->right, x, y, level+1, depth_x, parent_x, depth_y, parent_y);
    }
        
    bool isCousins(TreeNode* root, int x, int y) {
        int parent_x = 0, parent_y = 0, depth_x = -1, depth_y = -1;
        
        parentAndDepth(root, x, y, 0, depth_x, parent_x, depth_y, parent_y);
        
        return ((depth_x == depth_y) and (parent_x != parent_y));
    }
