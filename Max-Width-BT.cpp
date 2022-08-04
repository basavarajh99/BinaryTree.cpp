//width : max no of nodes at any level
//instead of level order, index the nodes at each level and take difference of first node and last node in that level. 
//the max of above will be the max width
//indexing comes in segment tree but this will cause overflow if it is a skew tree
//to prevent overflow use level-order traveral + i=i-min(leftnodeindex- rightnodeindex);

int maxwidth(Node* root)
{
  if(!root) return NULL;
  int ans=0;
  queue<pair<Node*, int>> q;
  q.push({root, 0})
    
    while(!q.empty())
    {
      int size = q.size();//size = no. of nodes in that level
      int min = q.front().second;
      int first, last;
      
      for(int i=0; i<size; i++)
      {
        int cur = q.front().second - min;//prevents overflow while indexing  
        Node* node = q.front().first;
        q.pop();
        if(i==0) first = cur;
        if(i==size-1) last = cur;
        if(node->left) q.push({node->left, 2*cur+1});//for indexing left node 
        if(node->right) q.push({node->right, 2*cur+2});//for indexing right node
      }
      ans = max(ans, last-first+1);
    }
  
  return ans;
}
