 //Threaded BT
//case 1: if there is no left then, print root and just traverse right without connceting an thread from left  and vice versa for right
//case 2: before going to left, connect right most node to root and then move to left
//case 3: if the thread already there then remove it before going to right
// thread will be node->right

vector<int> morris(Node* root)
{
  vector<int> inorder;
  if(!root) return inorder;
  
  Node* cur = root;
  
  while(cur)
  {
    if(!cur->left) // 1st case
    {
      inorder.push_back(cur->val);
      cur = cur->right;
    }
    else //2nd case
    {
      Node* prev = cur->left;
      
      while(prev->right and prev->right != cur)
        prev = pre->right;
      
      if(!prev->right) //right most node in left sub tree
      {
        prev->right = cur;
        cur = cur->left;
      }
      else // if there is already a thread
      {
        prev->right = NULL;
        inorder.push_back(cur->val);
        cur - cur->right;
      }
    }
  }
  
  return inorder;
}
