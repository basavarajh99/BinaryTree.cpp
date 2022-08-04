 //last node of every level will be the right view and vice versa for left view
// recursive approach: short-code
//reverse of pre-order traversal: (root, right, left)
// to get left view: (root, left, right)

void recur(Node* root, int level, vector<int>& ans)
{
  if(!root) return;
  if(ans.size() == level) ans.push_back(root->val); //each time pushes only one node for every level
  recur(root->right, level+1, res);
  recur(root->left, level-1, res);
}

vector<int> right(Node* root)
{
  vector<int> ans;
  recur(root, 0, ans);
  return ans;
}
