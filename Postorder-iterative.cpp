//using 2 stacks
vector<int> postorder(Node* root)
{
  vector<int> post;
  if(!root) return post;
  
  stack<Node*> st1, st2;
  st1.push(root);
  
  while(!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root->left)
      st2.push(root->left);
    if(root->right)
      st2.push(root->right);
  }
  
  while(!st2.empty())
  {
    post.push_back(st2.top()->val);
    st2.pop();
  }
  
  return post;
  
}

//using 1 stack
//TC: O(2N) SC: O(N)

vector<int> postOrder(Node* cur)
{
   vector<int> post;
  
  if(!cur) return post;
  
  stack<int> st;
  
  while(cur || !st.empty())
  {
    if(cur)
    {
       st.push(cur);
      cur = cur->left;
    }
    else
    {
      Node* temp = st.top()->right;
      st.pop();
      
      if(!temp)
      {
        temp = st.top();
        st.pop();
        post.push_back(temp->data);
        
        while(!st.empty() and st.top()->right = temp)
        {
          temp = st.top();
          st.pop();
          post.push_back(temp->val);
        }
      }
      
      else
        cur = temp;
    } 
  }
  
  return post;
}
