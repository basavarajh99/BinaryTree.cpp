vector<int> inorder(Node* root)
{
  vector<int> in;
  if(!root) return in;
  stack<Node*> st;
  Node* node = root;
  
  while(true)
  {
    if(node)
    {
      st.push(node);
      node = node->left;
    }
    else
    {
      if(st.empty()) break;
      node = st.top();
      st.pop();
      in.push_back(node->val);
      node = node->right;
    }
  }
  
  return in;
}
