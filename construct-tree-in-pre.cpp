Node* build(vector<int>& pre, int prestart, int preend, vector<int>& in, int instart, int inend, map<int, int>& mp)
{
  if(prestart>preend || instart>inend) return NULL;
  
  Node* root = new Node(pre[prestart]);
  
  int inroot = mp[root->val];
  int remains = inroot - instart;
  
  root->left = build(pre, prestart+1, prestart+numsleft, in, instart, inroot-1, mp);
  root->right = build(pre, prestart+numsleft-1, preend, in, inroot+1, inend, mp);
  
  return root;
}

Node* buildtree(vector<int>& pre, vector<int>& in)
{
  map<int, int> mp;
  
  for(int i=0; i<in.size(); i++)
    mp[in[i]]++;
  
  Node* root = build(pre, 0, pre.size()-1, in, 0, in.size()-1, mp);
  
  return root;
}
