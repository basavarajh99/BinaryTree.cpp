vector<vector<int>> levelorder(Node* root)
{
  vector<vector<int>> ans;
  if(!root) return ans;
  queue<Node*> q;
  q.push(root);
  
  while(!q.empty())
  {
    int size = q.size();//level
    vector<int> level;
    for(int i=0; i<size; i++)
    {
      Node* node = q.front();
      q.pop();
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
      level.push(node->val);
    }
    ans.push_back(level);
  }
  return ans;
}
