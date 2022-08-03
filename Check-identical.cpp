//use any traversal technique

bool issame(Node* a, Node* b)
{
  if(!a || !b)
    return a==b;
  
  return (a->val == b->val) && (issame(a->left, b->left)) && (issame(a->right, b->right));
}
