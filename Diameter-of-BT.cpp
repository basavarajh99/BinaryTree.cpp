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
int height(Node* root, int& diameter)
{
  if(!node)
    return 0;
  
  int lh = height(root->left, diameter);
  int rh = height(root->right, diameter);
  
  diameter = max(diameter, lh+rh);
  return 1+max(lh, rh);
}

int diameter(Node* root)
{
  int diameter = 0;
  height(root, diameter);
  return diameter;
}
