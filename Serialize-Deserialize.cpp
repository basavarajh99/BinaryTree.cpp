//level-order traversal

string serialize(Node* root)
{
  if(!root) return "";
  
  string s = "";
  queue<Node*> q;
  q.push(root);
  
  while(!q.empty())
  {
    Node* node = q.front();
    q.pop();
    
    if(!node) s.append("#,");
    else s.append(to_string(node->val) + ',');
    if(node)
    {
      q.push(node->left);
      q.push(node->right);
    }
  }
  
  return s;
}

Node* deserialize(string data)
{
  if(data.size()==0) return NULL;
  stringstream s(data); 
  string str;
  getline(s, str, ',');
  Node* root = new node(stoi(str));
  queue<Node*> q;
  q.push(root);
  
  while(!q.empty())
  {
    Node* node = q.front();
    q.pop();
    
    getline(s, str, ',');
    if(str == '#')
      node->left = NULL;
    else
    {
      Node* lnode = new Node(stoi(str));
      node->left = lnode;
      q.push(lnode);
    }
    
    getline(s, str, ',');
    if(str == '#')
      node->right = NULL;
    else
    {
      Node* rnode = new Node(stoi(str));
      node->right = rnode;
      q.push(rnode);
    }
  }
  
  return root;
}
