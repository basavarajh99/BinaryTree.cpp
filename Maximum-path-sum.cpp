 //Naive: Trying all combinations, TC: O(N^2)
//efficient: nodeval + max(maxl+maxr)
int maxpath(Node* node, int &maxi)
{
  if(!node) return 0;
  int left = max(0, maxpath(node->left, maxi));//to handle -ve values in leaf node. return 0 if left and right are -ve
  int right = max(0, maxpath(node->right, maxi));
  maxi = max(maxi, left+right+node->val);
  return max(left, right)+node->val;
}
int maxpathsum(Node* root)
{
  int maxi = INT_MIN;
  maxpath(root, maxi);
  return maxi;
}
