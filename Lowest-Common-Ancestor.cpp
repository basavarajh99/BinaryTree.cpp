//The ancestor at deepest level
//check one of the node from left and another right if either of them returns val take it and omit the null returned by the other

Node* lca(Node* root, Node* p, Node* q)
{
  if(!root || root==p || root==q) return root;
  
  Node* left = lca(root->left, p, q);
  Node* right = lca(root->right, p, q);
  
  if(!left) return right; 
  else if(!right) return left;
  else return root;
}
