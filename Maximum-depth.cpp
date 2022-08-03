//recursive: Worst case: O(Height) in skew tree
//level order: worst case: O(N) in complete bt

int maxdepth(Node* root)
{
  if(!root) return 0;
  
  int left_height = maxdepth(root->left);
  int right_height = maxdepth(root->right);
  
  return 1+max(left_height, right_height);
}
