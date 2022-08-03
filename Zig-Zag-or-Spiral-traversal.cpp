//level order traversal
// flag = 0 : l->r; flag = 1 : r->l

vector<vector<int>> zigzag (Node* root)
{
  vector<vector<int>> result;
  if(!root) return result;
  
  queue<Node*> q;
  q.push(root);
  bool fl = 0;
  
  while(!q.empty())
  {
    int size = q.size();
    vector<int> level(size);
    
    for(int i=0; i<size; i++)
    {
      Node* node = q.front();
      q.pop();
      
      int index = (fl) ? i : size-1-i;
      
      level[index] = node->val;
      
      if(node->left)
       q.push(node->left);
      if(node->right)
        q.push(node->right);
    }
    fl = !fl;
    result.push_back(level);
  }
  
  return result;
}
