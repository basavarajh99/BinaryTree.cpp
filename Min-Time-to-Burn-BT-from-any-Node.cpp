 //similar to k-nodes
//level order and marking parent

int findmaxdist(map<Node<int>*, Node<int>*>& parent, Node<int>* target)
{
  queue<Node<int>*>q;
  q.push(target);
  
  map<Node<int>*, int> vis;
  vis[target] = 1;
  int maxi = 0;
  
  while(!q.empty())
  {
    int size = q.size();
    int burnt = 0;
    
    for(int i=0; i<size; i++)
    {
      auto node = q.front();
      q.pop();
      
      if(node->left and !vis[node->left])
      {
        burnt = 1;
        vis[node->left] = 1;
        q.push(node->left);
      }
      if(node->right and !vis[node->right])
      {
        burnt = 1;
        vis[node->right] = 1;
        q.push(node->right);
      }
      if(parent[node] and !vis[parent[node]])
      {
        burnt = 1;
        vis[parent[node]] = 1;
        q.push(parent[node]);
      }
    }
    
    if(burnt) maxi++;
  }
  
  return maxi;
}

Node<int>* markparent(Node<int>* root, map<Node<int>*, Node<int>*>& parent, int start)
{
  queue<Node<int>*> q;
  q.push(root);
  Node<int>* res;
  while(!q.empty())
  {
    Node<int>* node = q.front();
    q.pop();
    if(node->data == start) res = node;
    if(node->left) 
    {
      parent[node->left] = node;
      q.push(node->left);
    }
    if(node->right)
    {
      parent[node->right] = node;
      q.push(node->right);
    }
  }
  return res;
}

int timetoburn(Node<int>* root, int start)
{
  map<Node<int>*, Node<int>*> mp;
  Node<int>* target = markparent(root, mp, start);
  int maxi = findmaxdist(map, target);
  return maxi;
}
