//using 2 stacks
vector<int> postorder(Node* root)
{
  vector<int> post;
  if(!root) return post;

  stack<TreeNode*> st1, st2;
  st1.push(root);

  while(!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root->left)
      st1.push(root->left);
    if(root->right)
      st1.push(root->right);
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
  
    if(cur==NULL) return post;

    stack<TreeNode*> st;

    while(cur!=NULL || !st.empty())
    {
      if(cur!=NULL)
      {
         st.push(cur);
        cur = cur->left;
      }
      else
      {
        TreeNode* temp = st.top()->right;
        if(temp==NULL)
        {
          temp = st.top();
          st.pop();
          post.push_back(temp->val);

          while(!st.empty() and temp == st.top()->right)
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
