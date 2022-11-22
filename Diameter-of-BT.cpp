//Diameter-of-BT : longest path between 2 nodes and the path may or may not pass through root
//Naive: pseudocode TC: O(N^2)
// find dia(node)
// {
//   if(!root)
//     return;
  
//   lh = findhleft(node->left);
//   rh = findhright(node->right);
  
//   maxi = max(maxi, lh+rh);
  
//   dia(node->left);
//   dia(node->right);
// }

//efficient: TC: O(N)
class Solution {
    int diam(Node* root, int& d){
        if(!root) return 0;
        
        int l = diam(root->left, d);
        int r = diam(root->right, d);
        
        d = max(d, 1+l+r);
        
        return 1 + max(l, r);
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int d = 0;
        diam(root, d);
        return d;
    }
};
