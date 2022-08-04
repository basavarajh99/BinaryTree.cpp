//level-order traversal
//queue = (Node, vertical and level)
//map = map(vertical, mp(level, multiset(node's val))) cuz nodes can have duplicate values
//moving left: level+=1 and vertical-=1; 
//moving right: level+=1 and vertical+=1; 

vector<vector<int>> vertical(Node* root)
{
  map<int, map<int, multiset<int>>> nodes;
  queue<pair<Node*, pair<int, int>>> remains;
  
  remains.push_back(root, {0,0});
  
  while(!remains.empty())
  {
    auto it = remains.front();
    remains.pop();
    Node* node = it.first;
    int x = it.second.first, y=it.second.second;
    nodes[x][y].insert(node->val);
    if(node->left)
      remains.push_back(node->left, {x-1, y+1});
    if(node->right)
      remains.push_back(node->right, {x+1, y+1});
  }
  
  vector<vector<int>> ans;
  for(auto it : nodes)
  {
    vector<int> vertical;
    for(auto it1 : it.second)
      vertical.insert(vertical.end(), it1.second.begin(), it1.second.end());// inserting the multiset at the end
    ans.push_back(vertical);
  }
  
  return ans;
}
