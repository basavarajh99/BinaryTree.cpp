//TC: O(3N) SC: O(4N) 

vector<int> preinpost_order(Node* root)
{
  vector<int> pre, in, post;
  
  if(!root) return pre;
  
  stack<pair<Node*, int>> st;
  st.push({root, 1});
  
  while(!st.empty())
  {
    auto it = st.top();
    st.pop();
    
    if(it.second == 1) //preorder
    {
      pre.push_back(it.first->val);
      it.second++;
      st.push(it);
      
      if(it.first->left)
        st.push({it.first->left, 1});
    }
    
    else if(it.second == 2) //inorder
    {
      in.push_back(it.first->val);
      it.second++;
      st.push({it});
      
      if(it.first->right)
        st.push({it.first->right, 1});
    }
    
    else // post order
      post.push_back(it.first->val);
  }
}
