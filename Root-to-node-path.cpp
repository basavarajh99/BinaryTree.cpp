 //inorder traversal
bool solve(Node* root, vector<int>& ans, int node)
{
  if(!root) return false;
  
  ans.push_back(root->val);
  
  if(root->val == node) return true;
  
  if(solve(root->left, ans, node) || solve(root->right, ans, node)) return true;
  
  ans.pop_back();
  return false;
}

vector<int> root_to_node(Node* root, int node)
{
  vector<int> ans;
  if(!root) return ans;
  solve(root, ans, node)
  return ans;
}
