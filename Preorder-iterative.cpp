vector<int> preorder(Node* root)
{
  vector<int> pre;
  if(!root) return pre;
  
  stack<Node*> st;
  st.push(root);
  
  while(!st.empty())
  {
    root = st.top();
    st.pop();
    pre.push_back(root->val);
    if(root->right) st.push(root->right);
    if(root->left) st.push(root->left);
  }
  
  return pre;
}
