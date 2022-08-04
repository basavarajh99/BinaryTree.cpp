//naive: any traversal, TC: O(N)
//efficient: TC: O(logN)
//No. of nodes = 2^h - 1;
//if lh = rh then simply apply formula
//else compute leftsubtree nodes + rightsubtree nodes + 1

int findlh(Node* root)
{
  int height = 0;
  while(root)
  {
    height++;
    root = root->left;
  }
  return height;
}

int findrh(Node* root)
{
  int height = 0;
  while(root)
  {
    height++;
    root = root->right;
  }
  return height;
}

int count(Node* root)
{
  if(!root) return 0;
  
  int lh = findlh(root);
  int rh = findrh(root);
  
  if(lh==rh) return pow(2, lh)-1;
  
  return 1+count(root->left)+count(root->right);
}
