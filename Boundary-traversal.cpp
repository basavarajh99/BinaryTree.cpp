//anticlockwise
//left_boundary_excluding_leaf -> leaf -> right_boundary_excluding_leaf_in_reverse_fashion
//for leaf_nodes do inorder traversal
//TC: O(H)+O(H)+O(N) SC: O(N)
bool isleaf(Node* root)
{
  if(!root->left and !root->right)
    return true;
  
  return false;
}

void leftboundary(Node* root, vector<int>& res)
{
  Node* cur = root->left;
  while(cur)
  {
    if(!isleaf(cur)) res.push_back(cur->data);
    if(cur->left) cur = cur->left;
    else
      cur = cur->right;
  }
}

void rightboundary(Node* root, vector<int>& res)
{
  Node* cur = root->right;
  vector<int> temp;
  while(cur)
  {
    if(!isleaf(cur)) temp.push_back(cur->data);
    if(cur->right) cur = cur->right;
    else
      cur = cur->left;
  }
  
  for(int i=temp.size()-1; i>=0; i--)
    res.push_back(temp[i]);
}

void leaves(Node* root, vector<int>& res)
{
  if(isleaf(root))
  {
    res.push_back(root->data);
    return;
  }
  if(root->left) leaves(root->left, res);
  if(root->right) leaves(root->right, res);  
}

vector<int> boundary(Node* root)
{
  vector<int> res;
  
  if(!root) return res;
  if(!isleaf(root)) res.push_back(root->data);
  leftboundary(root, res);
  leaves(root, res);
  rightboundary(root, res);
  return res;
}
