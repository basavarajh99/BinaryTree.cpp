 //given target and k
//level order traversal to mark parents of every node
//maintain a visited array so that u don't go to a node repeatedly

void markparent(Node* root, unordered_map<Node*, Node*>& parent, Node* target)
{
  queue<Node*> q;
  q.push(root);
  
  while(!q.empty())
  {
    Node* node = q.front();
    q.pop();
    
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
}

vector<int> distance(Node* root, Node* target, int k)
{
  unordered_map<Node*, Node*> parent;
  markparent(root, parent, target);
  
  unordered_map<Node*, bool> visited;
  queue<Node*> q;
  q.push(target);
  visited[target] = true;
  int level = 0;
  
  while(!q.empty()) // BFS radially outwards till level = k
  {
    int size = q.size();
    if(level++ == k) break;
    for(int i=0; i<size; i++)
    {
      Node* cur = q.front();
      q.pop();
      if(cur->left and !visited[cur->left])
      {
        q.push(cur->left);
        visited[cur->left] = true;
      }
      if(cur->right and !visited[cur->right])
      {
        q.push(cur->right);
        visited[cur->right] - true;
      }
      if(parent[cur] and !visited[parent[cur]])
      {
        q.push(parent[cur]);
        visited[parent[cur]]=true;
      }
    }
  }
  
  vector<int> result;
  while(!q.empty())
  {
    result.push_back(q.front()->val);
    q.pop();
  }
  
  return res;
}
