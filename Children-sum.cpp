//maintain nodeval = leftval+rightval for all level
//u can only increment by 1 any number of times but u cant decrement
//TC: O(N)
//while going down if children is lower than parent then increment the value to parent and while going back add the childrens value and if the sum is greater
//update the parent value to sum
//else while going down if children is greater than parent then take the sum and update the parent value to sum

void childrensum(Node* root)
{
  if(!root) return NULL;
  
  //updating children while going down
  int child = 0;
  
  if(root->left) child += root->left->data;
  if(root->right) child += root->right->data;
  
  if(child >= root->data) root->data = child;
  else
  {
    if(root->left) root->left->data = root->data;
    if(root->right) root->right->data = root->data;
  }
  
  childrensum(root->left);
  childrensum(root->right);
  
  //updating parent while going back up
  int tot = 0;
  if(root->left) tot += root->left->data;
  if(root->right) tot += root->right->data;
  if(root->left or root->right) root->data = tot;
}
