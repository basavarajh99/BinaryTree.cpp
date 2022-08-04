//if both left subtree and right subtree are symmentric then preorder traversal of left = reverse preorder traversal of right
//(root, left, right) = (root, right, left)

bool issymmentry(Node* a, Node* b)
{
  if(!a || !b) return a==b;
  
  if(a->val != b->val) return false;
  
  return issymmentry(a->left, b->right) and issymmentry(a->right, b->left);  
}

bool symmentry(Node* root)
{
  return !root || issymmentry(root->left, root->right);
}
