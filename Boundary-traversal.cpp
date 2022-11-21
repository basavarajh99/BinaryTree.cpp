//anticlockwise
//left_boundary_excluding_leaf -> leaf -> right_boundary_excluding_leaf_in_reverse_fashion
//for leaf_nodes do inorder traversal
//TC: O(H)+O(H)+O(N) SC: O(N)
class Solution {
    bool isLeaf(Node* root){
        if(!root->left && !root->right)
            return true;
        return false;
    }
    
    void leftBoundary(Node* root, vector<int>& ans){
        
        if(!root) return;
        
        if(isLeaf(root)) return;
        
        ans.push_back(root->data);
        if(root->left) leftBoundary(root->left, ans);
        else leftBoundary(root->right, ans);
    }
    
    void leaves(Node* root, vector<int>& ans){
        if(!root) return;
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        } 
        
        if(root->left) leaves(root->left, ans);
        if(root->right) leaves(root->right, ans);
    }
    
    void rightBoundary(Node* root, vector<int>& ans){
        
        if(!root) return;
        
        if(isLeaf(root)) return;
        
        if(root->right) rightBoundary(root->right, ans);
        else rightBoundary(root->left, ans);
        
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(!root) return ans;
        
        ans.push_back(root->data);
            
        leftBoundary(root->left, ans);
        leaves(root->left, ans);
        leaves(root->right, ans);
        rightBoundary(root->right, ans);
        
        return ans;
    }
};
