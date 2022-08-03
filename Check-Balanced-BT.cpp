//Balanced BT: for every node, height(left)-height(right)<=1
//Naive: pseudocode TC: O(N^2)
// Bool Check(Node)
// {
//   if node == null
//     return true
//   lh = findhleft(node->left);
//   rh = findhright(node->right);
  
//   if(abs(rh-lh)>1) return false;
  
//   bool left = check(node->left);
//   bool right = check(node->right);
  
//   if(left || right) return false;
  
//   return true;
// }

//efficient TC: O(N)

int height(Node* root)
{
  if(!root) return 0;
  
  int lh = height(root->left);
  if(lh == -1) return -1;
  int rh = height(rot->right);
  if(rh == -1) return -1;
  
  if(abs(height(lh - rh))>1) return -1;
  
  return max(lh, rh) + 1;    
}

bool check(Node* root)
{
  return height(root) != -1;
}
