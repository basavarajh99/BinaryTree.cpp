//similar to vertical view, just take last node

vector<int> bottomview(Node* root)
{
  vector<int> ans;
  if(!root) return ans;
  map<int, int>mp;
  queue<pair<Node*, int>>q;
  q.push({root, 0});
  
  while(!q.empty())
  {
    auto it = q.front();
    q.pop();
    Node* node = it.first;
    int line = it.second;
    mp[line] = node->val; //just don't check condition as in vertical order and override the node
    if(node->left) q.push({node->left, line-1});
    if(node->right) q.push({node->right, line+1});
  }
  
  for(auto it : mp)
    ans.push_back(it.second);
  
  return ans;  
}
